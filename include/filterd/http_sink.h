#ifndef  __FILTERD_HTTP_SINK_H__
#define  __FILTERD_HTTP_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class HttpSink : public Sink<T> {
  public:
    HttpSink(const std::string& url);
    virtual ~HttpSink();
    virtual void put(long timestamp, const std::string& name, T value);
  private:
    std::string url;
};

}
#endif // __FILTERD_HTTP_SINK_H__
