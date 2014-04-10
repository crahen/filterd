#ifndef  __FILTERD_HTTP_SINK_H__
#define  __FILTERD_HTTP_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class HttpSink : public Sink<T> {
  public:
    virtual ~HttpSink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_HTTP_SINK_H__
