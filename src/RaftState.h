#ifndef raftstate_h
#define raftstate_h
#include <map>
#include <mutex>
#include <string>


struct RaftState {  
  std::mutex m;

  // Raft persistend state
  int currentTerm;
  int votedFor;
  // log ?
  
  // Raft volatile state
  int commitIndex;
  int lastApplied;

  // Raft volatile leader state        
  std::map<std::string, int> nextIndex;
  std::map<std::string, int> matchIndex;
};
#endif
