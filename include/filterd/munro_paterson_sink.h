#ifndef  __FILTERD_MUNRO_PATERSON_SINK_H__
#define  __FILTERD_MUNRO_PATERSON_SINK_H__

#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class MunroPatersonSink : public AbstractSink<T> {
  public:

    MunroPatersonSink(Sink<T>* sink, size_t numQuantiles);
    virtual ~MunroPatersonSink();

    virtual void put(long timestamp, const std::string& name, T value);
 
  private:
    size_t numQuantiles;
};

}
#endif // __FILTERD_MUNRO_PATERSON_SINK_H__
