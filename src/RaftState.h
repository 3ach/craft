#ifndef raftstate_h
#define raftstate_h
#include <map>
#include <mutex>
#include <string>
#include <condition_variable>


struct RaftState {  
  std::mutex data;
  std::mutex heartbeat;
  std::condition_variable heartbeat_cv;

  // Raft persistend state
  int currentTerm;
  int votedFor;
  std::vector<std::string> log;
  
  // Raft volatile state
  int commitIndex;
  int lastApplied;

  // Raft volatile leader state        
  std::map<std::string, int> nextIndex;
  std::map<std::string, int> matchIndex;
};
#endif
