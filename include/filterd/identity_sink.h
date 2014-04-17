#ifndef  __FILTERD_IDENTITY_SINK_H__
#define  __FILTERD_IDENTITY_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class IdentitySink : public AbstractSink<T> {
  public:
    IdentitySink(Sink<T>* sink) : AbstractSink<T>(sink) {}
    virtual ~IdentitySink() {}
};

}
#endif // __FILTERD_IDENTITY_SINK_H__
