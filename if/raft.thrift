struct Reply {
    1:i64 term,
    2:bool voteGranted,
}

service Raft {
    Reply RequestVote(1:i64 term, 
                      2:i64 candidateId, 
                      3:i64 lastLogIndex, 
                      4:i64 lastLogTerm);
    Reply AppendEntries(1:i64 term, 
                        2:i64 leaderId, 
                        3:i64 prevLogIndex, 
                        4:i64 prevLogTerm, 
                        5:list<binary> entries, 
                        6:i64 leaderCommit)
}
