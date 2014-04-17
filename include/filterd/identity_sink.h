#ifndef  __FILTERD_IDENTITY_SINK_H__
#define  __FILTERD_IDENTITY_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class IdentitySink : public Sink<T> {
  public:
    virtual ~IdentitySink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_IDENTITY_SINK_H__
