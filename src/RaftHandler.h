#include "if/gen-cpp/Raft.h"
#include "src/RaftState.h"

#include <memory>

class RaftHandler : virtual public RaftIf {
 public:
  RaftHandler(std::shared_ptr<RaftState>);

  void RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm);
  void AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit);

private:
  std::shared_ptr<RaftState> state;
};
