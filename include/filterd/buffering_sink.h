#ifndef  __FILTERD_BUFFERING_SINK_H__
#define  __FILTERD_BUFFERING_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class BufferingSink : public Sink<T> {
  public:
    virtual ~BufferingSink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_BUFFERING_SINK_H__
