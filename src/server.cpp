#include "src/Replicator.h"
#include <gflags/gflags.h>
#include <cstring>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iostream>

DEFINE_int32(port, 9090, "Port for thrift server");
DEFINE_string(cluster, "", "Other raft server ports");

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  int port = FLAGS_port;
  char* others = new char[FLAGS_cluster.length() + 1];
  std::strcpy(others, FLAGS_cluster.c_str());

  Replicator rep(port);
  rep.listen();
  std::this_thread::sleep_for(std::chrono::seconds(5));

  char* other = std::strtok(others, ",");
  while (other) {
    int otherPort = std::atoi(other);
    other = std::strtok(NULL, ",");

    if (otherPort == port) continue;

    rep.addPeer(otherPort);
  }

  rep.replicate();

  return 0;
}

