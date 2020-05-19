/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef raft_TYPES_H
#define raft_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>




class Reply;

typedef struct _Reply__isset {
  _Reply__isset() : term(false), voteGranted(false) {}
  bool term :1;
  bool voteGranted :1;
} _Reply__isset;

class Reply : public virtual ::apache::thrift::TBase {
 public:

  Reply(const Reply&);
  Reply& operator=(const Reply&);
  Reply() : term(0), voteGranted(0) {
  }

  virtual ~Reply() noexcept;
  int64_t term;
  bool voteGranted;

  _Reply__isset __isset;

  void __set_term(const int64_t val);

  void __set_voteGranted(const bool val);

  bool operator == (const Reply & rhs) const
  {
    if (!(term == rhs.term))
      return false;
    if (!(voteGranted == rhs.voteGranted))
      return false;
    return true;
  }
  bool operator != (const Reply &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Reply & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Reply &a, Reply &b);

std::ostream& operator<<(std::ostream& out, const Reply& obj);



#endif
