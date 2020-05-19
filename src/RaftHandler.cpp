
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
        std::lock_guard<std::mutex> lock(this->state->data);
        this->state->votedFor = candidateId;
        this->state->currentTerm = term;
        this->state->heartbeat_cv.notify_all();

        _return.voteGranted = true;
        _return.term = term;
        return;
    }

    _return.voteGranted = false;
    _return.term = this->state->currentTerm;
}

void RaftHandler::AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit) {
    std::cout << "AppendEntries(r, " << term << ", " << leaderId << ", " << prevLogIndex << ", " << prevLogTerm << ", entries, " << leaderCommit << ")" << std::endl;
    if (this->state->currentTerm <= term) {
        std::cout << "beating heart" << std::endl;
        this->state->heartbeat_cv.notify_all();
    }
  printf("AppendEntries\n");
}
