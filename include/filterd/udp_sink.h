#ifndef  __FILTERD_UDP_SINK_H__
#define  __FILTERD_UDP_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class UdpSink : public Sink<T> {
  public:
    virtual ~UdpSink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_UDP_SINK_H__
