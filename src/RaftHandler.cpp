
#include "src/RaftHandler.h"
#include <iostream>
#include <mutex>

RaftHandler::RaftHandler(std::shared_ptr<RaftState> raftState) {
    this->state = raftState;
}

void RaftHandler::RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm) {
    std::cout << "RequestVote(reply, " << term << ", " << candidateId << ", " << lastLogIndex << ", " << lastLogTerm << ")" << std::endl;

    if(this->state->currentTerm > term) {
        _return.voteGranted = false;
        _return.term = this->state->currentTerm;
        return;
    }

    if(this->state->votedFor == 0 && true) { // second term should deal with indices
        std::lock_guard<std::mutex> lock(this->state->m);
        this->state->votedFor = candidateId;
        this->currentTerm = term;

        _return.voteGranted = true;
        _return.term = term;
        return;
    }

    _return.voteGranted = false;
    _return.term = this->state->currentTerm;
}

void RaftHandler::AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit) {
  // Your implementation goes here
  printf("AppendEntries\n");
}
