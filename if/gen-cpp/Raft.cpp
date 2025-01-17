/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Raft.h"




Raft_RequestVote_args::~Raft_RequestVote_args() noexcept {
}


uint32_t Raft_RequestVote_args::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->term);
          this->__isset.term = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->candidateId);
          this->__isset.candidateId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->lastLogIndex);
          this->__isset.lastLogIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->lastLogTerm);
          this->__isset.lastLogTerm = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Raft_RequestVote_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Raft_RequestVote_args");

  xfer += oprot->writeFieldBegin("term", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->term);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("candidateId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->candidateId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastLogIndex", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->lastLogIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastLogTerm", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->lastLogTerm);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_RequestVote_pargs::~Raft_RequestVote_pargs() noexcept {
}


uint32_t Raft_RequestVote_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Raft_RequestVote_pargs");

  xfer += oprot->writeFieldBegin("term", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->term)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("candidateId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->candidateId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastLogIndex", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64((*(this->lastLogIndex)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastLogTerm", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64((*(this->lastLogTerm)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_RequestVote_result::~Raft_RequestVote_result() noexcept {
}


uint32_t Raft_RequestVote_result::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Raft_RequestVote_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Raft_RequestVote_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_RequestVote_presult::~Raft_RequestVote_presult() noexcept {
}


uint32_t Raft_RequestVote_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}


Raft_AppendEntries_args::~Raft_AppendEntries_args() noexcept {
}


uint32_t Raft_AppendEntries_args::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->term);
          this->__isset.term = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->leaderId);
          this->__isset.leaderId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->prevLogIndex);
          this->__isset.prevLogIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->prevLogTerm);
          this->__isset.prevLogTerm = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->entries.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->entries.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += iprot->readBinary(this->entries[_i6]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.entries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->leaderCommit);
          this->__isset.leaderCommit = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Raft_AppendEntries_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Raft_AppendEntries_args");

  xfer += oprot->writeFieldBegin("term", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->term);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("leaderId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->leaderId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prevLogIndex", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->prevLogIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prevLogTerm", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->prevLogTerm);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("entries", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->entries.size()));
    std::vector<std::string> ::const_iterator _iter7;
    for (_iter7 = this->entries.begin(); _iter7 != this->entries.end(); ++_iter7)
    {
      xfer += oprot->writeBinary((*_iter7));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("leaderCommit", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->leaderCommit);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_AppendEntries_pargs::~Raft_AppendEntries_pargs() noexcept {
}


uint32_t Raft_AppendEntries_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Raft_AppendEntries_pargs");

  xfer += oprot->writeFieldBegin("term", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->term)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("leaderId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->leaderId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prevLogIndex", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64((*(this->prevLogIndex)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prevLogTerm", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64((*(this->prevLogTerm)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("entries", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->entries)).size()));
    std::vector<std::string> ::const_iterator _iter8;
    for (_iter8 = (*(this->entries)).begin(); _iter8 != (*(this->entries)).end(); ++_iter8)
    {
      xfer += oprot->writeBinary((*_iter8));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("leaderCommit", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64((*(this->leaderCommit)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_AppendEntries_result::~Raft_AppendEntries_result() noexcept {
}


uint32_t Raft_AppendEntries_result::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Raft_AppendEntries_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Raft_AppendEntries_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Raft_AppendEntries_presult::~Raft_AppendEntries_presult() noexcept {
}


uint32_t Raft_AppendEntries_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

void RaftClient::RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm)
{
  send_RequestVote(term, candidateId, lastLogIndex, lastLogTerm);
  recv_RequestVote(_return);
}

void RaftClient::send_RequestVote(const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("RequestVote", ::apache::thrift::protocol::T_CALL, cseqid);

  Raft_RequestVote_pargs args;
  args.term = &term;
  args.candidateId = &candidateId;
  args.lastLogIndex = &lastLogIndex;
  args.lastLogTerm = &lastLogTerm;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void RaftClient::recv_RequestVote(Reply& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("RequestVote") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  Raft_RequestVote_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "RequestVote failed: unknown result");
}

void RaftClient::AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit)
{
  send_AppendEntries(term, leaderId, prevLogIndex, prevLogTerm, entries, leaderCommit);
  recv_AppendEntries(_return);
}

void RaftClient::send_AppendEntries(const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("AppendEntries", ::apache::thrift::protocol::T_CALL, cseqid);

  Raft_AppendEntries_pargs args;
  args.term = &term;
  args.leaderId = &leaderId;
  args.prevLogIndex = &prevLogIndex;
  args.prevLogTerm = &prevLogTerm;
  args.entries = &entries;
  args.leaderCommit = &leaderCommit;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void RaftClient::recv_AppendEntries(Reply& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("AppendEntries") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  Raft_AppendEntries_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "AppendEntries failed: unknown result");
}

bool RaftProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void RaftProcessor::process_RequestVote(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Raft.RequestVote", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Raft.RequestVote");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Raft.RequestVote");
  }

  Raft_RequestVote_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Raft.RequestVote", bytes);
  }

  Raft_RequestVote_result result;
  try {
    iface_->RequestVote(result.success, args.term, args.candidateId, args.lastLogIndex, args.lastLogTerm);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Raft.RequestVote");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("RequestVote", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "Raft.RequestVote");
  }

  oprot->writeMessageBegin("RequestVote", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "Raft.RequestVote", bytes);
  }
}

void RaftProcessor::process_AppendEntries(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Raft.AppendEntries", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Raft.AppendEntries");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Raft.AppendEntries");
  }

  Raft_AppendEntries_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Raft.AppendEntries", bytes);
  }

  Raft_AppendEntries_result result;
  try {
    iface_->AppendEntries(result.success, args.term, args.leaderId, args.prevLogIndex, args.prevLogTerm, args.entries, args.leaderCommit);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Raft.AppendEntries");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("AppendEntries", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "Raft.AppendEntries");
  }

  oprot->writeMessageBegin("AppendEntries", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "Raft.AppendEntries", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > RaftProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< RaftIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< RaftIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new RaftProcessor(handler));
  return processor;
}

void RaftConcurrentClient::RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm)
{
  int32_t seqid = send_RequestVote(term, candidateId, lastLogIndex, lastLogTerm);
  recv_RequestVote(_return, seqid);
}

int32_t RaftConcurrentClient::send_RequestVote(const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("RequestVote", ::apache::thrift::protocol::T_CALL, cseqid);

  Raft_RequestVote_pargs args;
  args.term = &term;
  args.candidateId = &candidateId;
  args.lastLogIndex = &lastLogIndex;
  args.lastLogTerm = &lastLogTerm;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void RaftConcurrentClient::recv_RequestVote(Reply& _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("RequestVote") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      Raft_RequestVote_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "RequestVote failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void RaftConcurrentClient::AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit)
{
  int32_t seqid = send_AppendEntries(term, leaderId, prevLogIndex, prevLogTerm, entries, leaderCommit);
  recv_AppendEntries(_return, seqid);
}

int32_t RaftConcurrentClient::send_AppendEntries(const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("AppendEntries", ::apache::thrift::protocol::T_CALL, cseqid);

  Raft_AppendEntries_pargs args;
  args.term = &term;
  args.leaderId = &leaderId;
  args.prevLogIndex = &prevLogIndex;
  args.prevLogTerm = &prevLogTerm;
  args.entries = &entries;
  args.leaderCommit = &leaderCommit;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void RaftConcurrentClient::recv_AppendEntries(Reply& _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("AppendEntries") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      Raft_AppendEntries_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "AppendEntries failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}



