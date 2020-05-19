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

void Replicator::tick() {
    int naptime = rand() % 30;
    std::cout << this->port << ": Sleeping for " << naptime << " s" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(naptime));

    std::cout << this->port << ": triggering leader election!" << std::endl;
    std::list<std::thread> waiting;
    auto votes = std::make_shared<std::atomic_int>(0);

    const std::lock_guard<std::mutex> lock(this->state->m);
    this->state->currentTerm++;

    for (auto &client : this->others) {
        waiting.push_back(std::thread(&Replicator::poll, this, client, votes));
    }

    for (auto &thread : waiting) {
        thread.join();
    }

    std::cout << this->port << ": got " << *votes << " votes" << std::endl;
}

void Replicator::listen() {
    this->listenThread = std::make_shared<std::thread>(&Replicator::startServer, this);
    this->listenThread->detach();
}

void Replicator::replicate() {
  this->tickThread = std::make_shared<std::thread>(&Replicator::tick, this);
  this->tickThread->join();
}

