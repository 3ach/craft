#include "src/Replicator.h"
#include "src/RaftHandler.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TBufferTransports.h>

#include <iostream>
#include <random>
#include <chrono>
#include <list>
#include <mutex>
#include <condition_variable>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

Replicator::Replicator(int port) {
    srand(port);

    this->port = port;
    this->state = std::make_shared<RaftState>();

    this->state->currentTerm = 0;
    this->state->votedFor = 0;
}

void Replicator::addPeer(int port) {
    std::cout << this->port << ": Connecting to peer on " << port << std::endl;
    
    std::shared_ptr<TTransport> socket(new TSocket("localhost", port));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    auto client = std::make_shared<RaftClient>(protocol);
    this->others.push_back(std::make_pair(transport, client));
}

void Replicator::startServer() {
  std::shared_ptr<RaftHandler> handler(new RaftHandler(this->state));
  std::shared_ptr<TProcessor> processor(new RaftProcessor(handler));
  std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(this->port));
  std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  
  std::cout << this->port << ": listening" << std::endl;
  server.serve();
}

void Replicator::poll(std::pair<std::shared_ptr<TTransport>, std::shared_ptr<RaftClient>> ct, std::shared_ptr<std::atomic_int> votes) {
    Reply r;
    ct.first->open();
    ct.second->RequestVote(r, this->state->currentTerm, this->port, 1, this->state->currentTerm - 1);
    ct.first->close();

    if (r.voteGranted) {
        (*votes)++;
    }
}

void Replicator::follow() {
    while (1) {
        int naptime = rand() % 30;
        std::cout << this->port << ": Sleeping for " << naptime << " s" << std::endl;

        std::unique_lock<std::mutex> lock(this->state->heartbeat);
        auto gate = this->state->heartbeat_cv.wait_for(lock, std::chrono::seconds(naptime));

        if (gate == std::cv_status::timeout) {
            std::cout << this->port << ": triggering leader election!" << std::endl;
            std::list<std::thread> waiting;
            auto votes = std::make_shared<std::atomic_int>(1);

            const std::lock_guard<std::mutex> lock(this->state->data);
            this->state->currentTerm++;
            this->state->votedFor = this->port;

            for (auto &client : this->others) {
                waiting.push_back(std::thread(&Replicator::poll, this, client, votes));
            }

            for (auto &thread : waiting) {
                thread.join();
            }

            std::cout << this->port << ": got " << *votes << " votes" << std::endl;
            
            if (*votes >= 3) {
                this->lead();
            }
        } else {
            std::cout << this->port << ": thud thud" << std::endl;
        }
    }
}

void Replicator::update(std::pair<std::shared_ptr<TTransport>, std::shared_ptr<RaftClient>> ct) {
   Reply r;
   ct.first->open();
   ct.second->AppendEntries(r, this->state->currentTerm, this->port, 0, 0, this->state->log, this->state->commitIndex);
   ct.first->close();
}

void Replicator::lead() {
    while(1) {
        int naptime = rand() % 1000; 
        std::cout << this->port << ": lead-sleeping for " << naptime << " ms" << std::endl;
        std::unique_lock<std::mutex> lock(this->state->heartbeat, std::adopt_lock);
        auto gate = this->state->heartbeat_cv.wait_for(lock, std::chrono::milliseconds(naptime));
        
        if (gate == std::cv_status::timeout) {
            std::cout << "Sending heartbeats" << std::endl;
            std::list<std::thread> waiting;
            for (auto &client : this->others) {
                waiting.push_back(std::thread(&Replicator::update, this, client));
            }

            for (auto &thread : waiting) {
                thread.join();
            }
        } else {
            break;
        }
    }
}

void Replicator::listen() {
    this->listenThread = std::make_shared<std::thread>(&Replicator::startServer, this);
    this->listenThread->detach();
}

void Replicator::replicate() {
  this->tickThread = std::make_shared<std::thread>(&Replicator::follow, this);
  this->tickThread->join();
}

