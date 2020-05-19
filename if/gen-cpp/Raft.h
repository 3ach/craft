/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Raft_H
#define Raft_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "raft_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class RaftIf {
 public:
  virtual ~RaftIf() {}
  virtual void RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm) = 0;
  virtual void AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit) = 0;
};

class RaftIfFactory {
 public:
  typedef RaftIf Handler;

  virtual ~RaftIfFactory() {}

  virtual RaftIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RaftIf* /* handler */) = 0;
};

class RaftIfSingletonFactory : virtual public RaftIfFactory {
 public:
  RaftIfSingletonFactory(const ::std::shared_ptr<RaftIf>& iface) : iface_(iface) {}
  virtual ~RaftIfSingletonFactory() {}

  virtual RaftIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RaftIf* /* handler */) {}

 protected:
  ::std::shared_ptr<RaftIf> iface_;
};

class RaftNull : virtual public RaftIf {
 public:
  virtual ~RaftNull() {}
  void RequestVote(Reply& /* _return */, const int64_t /* term */, const int64_t /* candidateId */, const int64_t /* lastLogIndex */, const int64_t /* lastLogTerm */) {
    return;
  }
  void AppendEntries(Reply& /* _return */, const int64_t /* term */, const int64_t /* leaderId */, const int64_t /* prevLogIndex */, const int64_t /* prevLogTerm */, const std::vector<std::string> & /* entries */, const int64_t /* leaderCommit */) {
    return;
  }
};

typedef struct _Raft_RequestVote_args__isset {
  _Raft_RequestVote_args__isset() : term(false), candidateId(false), lastLogIndex(false), lastLogTerm(false) {}
  bool term :1;
  bool candidateId :1;
  bool lastLogIndex :1;
  bool lastLogTerm :1;
} _Raft_RequestVote_args__isset;

class Raft_RequestVote_args {
 public:

  Raft_RequestVote_args(const Raft_RequestVote_args&);
  Raft_RequestVote_args& operator=(const Raft_RequestVote_args&);
  Raft_RequestVote_args() : term(0), candidateId(0), lastLogIndex(0), lastLogTerm(0) {
  }

  virtual ~Raft_RequestVote_args() noexcept;
  int64_t term;
  int64_t candidateId;
  int64_t lastLogIndex;
  int64_t lastLogTerm;

  _Raft_RequestVote_args__isset __isset;

  void __set_term(const int64_t val);

  void __set_candidateId(const int64_t val);

  void __set_lastLogIndex(const int64_t val);

  void __set_lastLogTerm(const int64_t val);

  bool operator == (const Raft_RequestVote_args & rhs) const
  {
    if (!(term == rhs.term))
      return false;
    if (!(candidateId == rhs.candidateId))
      return false;
    if (!(lastLogIndex == rhs.lastLogIndex))
      return false;
    if (!(lastLogTerm == rhs.lastLogTerm))
      return false;
    return true;
  }
  bool operator != (const Raft_RequestVote_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Raft_RequestVote_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Raft_RequestVote_pargs {
 public:


  virtual ~Raft_RequestVote_pargs() noexcept;
  const int64_t* term;
  const int64_t* candidateId;
  const int64_t* lastLogIndex;
  const int64_t* lastLogTerm;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Raft_RequestVote_result__isset {
  _Raft_RequestVote_result__isset() : success(false) {}
  bool success :1;
} _Raft_RequestVote_result__isset;

class Raft_RequestVote_result {
 public:

  Raft_RequestVote_result(const Raft_RequestVote_result&);
  Raft_RequestVote_result& operator=(const Raft_RequestVote_result&);
  Raft_RequestVote_result() {
  }

  virtual ~Raft_RequestVote_result() noexcept;
  Reply success;

  _Raft_RequestVote_result__isset __isset;

  void __set_success(const Reply& val);

  bool operator == (const Raft_RequestVote_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Raft_RequestVote_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Raft_RequestVote_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Raft_RequestVote_presult__isset {
  _Raft_RequestVote_presult__isset() : success(false) {}
  bool success :1;
} _Raft_RequestVote_presult__isset;

class Raft_RequestVote_presult {
 public:


  virtual ~Raft_RequestVote_presult() noexcept;
  Reply* success;

  _Raft_RequestVote_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Raft_AppendEntries_args__isset {
  _Raft_AppendEntries_args__isset() : term(false), leaderId(false), prevLogIndex(false), prevLogTerm(false), entries(false), leaderCommit(false) {}
  bool term :1;
  bool leaderId :1;
  bool prevLogIndex :1;
  bool prevLogTerm :1;
  bool entries :1;
  bool leaderCommit :1;
} _Raft_AppendEntries_args__isset;

class Raft_AppendEntries_args {
 public:

  Raft_AppendEntries_args(const Raft_AppendEntries_args&);
  Raft_AppendEntries_args& operator=(const Raft_AppendEntries_args&);
  Raft_AppendEntries_args() : term(0), leaderId(0), prevLogIndex(0), prevLogTerm(0), leaderCommit(0) {
  }

  virtual ~Raft_AppendEntries_args() noexcept;
  int64_t term;
  int64_t leaderId;
  int64_t prevLogIndex;
  int64_t prevLogTerm;
  std::vector<std::string>  entries;
  int64_t leaderCommit;

  _Raft_AppendEntries_args__isset __isset;

  void __set_term(const int64_t val);

  void __set_leaderId(const int64_t val);

  void __set_prevLogIndex(const int64_t val);

  void __set_prevLogTerm(const int64_t val);

  void __set_entries(const std::vector<std::string> & val);

  void __set_leaderCommit(const int64_t val);

  bool operator == (const Raft_AppendEntries_args & rhs) const
  {
    if (!(term == rhs.term))
      return false;
    if (!(leaderId == rhs.leaderId))
      return false;
    if (!(prevLogIndex == rhs.prevLogIndex))
      return false;
    if (!(prevLogTerm == rhs.prevLogTerm))
      return false;
    if (!(entries == rhs.entries))
      return false;
    if (!(leaderCommit == rhs.leaderCommit))
      return false;
    return true;
  }
  bool operator != (const Raft_AppendEntries_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Raft_AppendEntries_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Raft_AppendEntries_pargs {
 public:


  virtual ~Raft_AppendEntries_pargs() noexcept;
  const int64_t* term;
  const int64_t* leaderId;
  const int64_t* prevLogIndex;
  const int64_t* prevLogTerm;
  const std::vector<std::string> * entries;
  const int64_t* leaderCommit;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Raft_AppendEntries_result__isset {
  _Raft_AppendEntries_result__isset() : success(false) {}
  bool success :1;
} _Raft_AppendEntries_result__isset;

class Raft_AppendEntries_result {
 public:

  Raft_AppendEntries_result(const Raft_AppendEntries_result&);
  Raft_AppendEntries_result& operator=(const Raft_AppendEntries_result&);
  Raft_AppendEntries_result() {
  }

  virtual ~Raft_AppendEntries_result() noexcept;
  Reply success;

  _Raft_AppendEntries_result__isset __isset;

  void __set_success(const Reply& val);

  bool operator == (const Raft_AppendEntries_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Raft_AppendEntries_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Raft_AppendEntries_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Raft_AppendEntries_presult__isset {
  _Raft_AppendEntries_presult__isset() : success(false) {}
  bool success :1;
} _Raft_AppendEntries_presult__isset;

class Raft_AppendEntries_presult {
 public:


  virtual ~Raft_AppendEntries_presult() noexcept;
  Reply* success;

  _Raft_AppendEntries_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RaftClient : virtual public RaftIf {
 public:
  RaftClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RaftClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm);
  void send_RequestVote(const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm);
  void recv_RequestVote(Reply& _return);
  void AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit);
  void send_AppendEntries(const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit);
  void recv_AppendEntries(Reply& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RaftProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<RaftIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RaftProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_RequestVote(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_AppendEntries(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RaftProcessor(::std::shared_ptr<RaftIf> iface) :
    iface_(iface) {
    processMap_["RequestVote"] = &RaftProcessor::process_RequestVote;
    processMap_["AppendEntries"] = &RaftProcessor::process_AppendEntries;
  }

  virtual ~RaftProcessor() {}
};

class RaftProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RaftProcessorFactory(const ::std::shared_ptr< RaftIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< RaftIfFactory > handlerFactory_;
};

class RaftMultiface : virtual public RaftIf {
 public:
  RaftMultiface(std::vector<std::shared_ptr<RaftIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RaftMultiface() {}
 protected:
  std::vector<std::shared_ptr<RaftIf> > ifaces_;
  RaftMultiface() {}
  void add(::std::shared_ptr<RaftIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->RequestVote(_return, term, candidateId, lastLogIndex, lastLogTerm);
    }
    ifaces_[i]->RequestVote(_return, term, candidateId, lastLogIndex, lastLogTerm);
    return;
  }

  void AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->AppendEntries(_return, term, leaderId, prevLogIndex, prevLogTerm, entries, leaderCommit);
    }
    ifaces_[i]->AppendEntries(_return, term, leaderId, prevLogIndex, prevLogTerm, entries, leaderCommit);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class RaftConcurrentClient : virtual public RaftIf {
 public:
  RaftConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  RaftConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void RequestVote(Reply& _return, const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm);
  int32_t send_RequestVote(const int64_t term, const int64_t candidateId, const int64_t lastLogIndex, const int64_t lastLogTerm);
  void recv_RequestVote(Reply& _return, const int32_t seqid);
  void AppendEntries(Reply& _return, const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit);
  int32_t send_AppendEntries(const int64_t term, const int64_t leaderId, const int64_t prevLogIndex, const int64_t prevLogTerm, const std::vector<std::string> & entries, const int64_t leaderCommit);
  void recv_AppendEntries(Reply& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif