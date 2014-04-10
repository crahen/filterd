#ifndef  __FILTERD_NULL_SINK_H__
#define  __FILTERD_NULL_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class NullSink : public Sink<T> {
  public:
    virtual ~NullSink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_NULL_SINK_H__
