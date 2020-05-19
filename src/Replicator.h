#include "if/gen-cpp/Raft.h"

#include "src/RaftState.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TBufferTransports.h>

#include <map>
#include <list>
#include <memory>
#include <thread>
#include <atomic>
#include <utility>

using namespace ::apache::thrift::transport;

class Replicator {
    public:
        Replicator(int port);
        void replicate();
        void listen();
        void addPeer(int port);

    private:
        int port;
        std::shared_ptr<std::thread> tickThread;
        std::shared_ptr<std::thread> listenThread;
        std::list<std::pair<std::shared_ptr<TTransport>, std::shared_ptr<RaftClient>>> others;

        std::shared_ptr<RaftState> state;

        void startServer();
        void lead();
        void follow();
        
        void poll(std::pair<std::shared_ptr<TTransport>, std::shared_ptr<RaftClient>>, std::shared_ptr<std::atomic_int>);
        void update(std::pair<std::shared_ptr<TTransport>, std::shared_ptr<RaftClient>>);
};
