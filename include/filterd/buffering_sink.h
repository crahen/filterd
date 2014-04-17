#ifndef  __FILTERD_BUFFERING_SINK_H__
#define  __FILTERD_BUFFERING_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class BufferingSink : public AbstractSink<T> {
  public:

    BufferingSink(Sink<T>* sink, size_t size);
    virtual ~BufferingSink();

    virtual void put(long timestamp, const std::string& name, T value);

  private:
    size_t size;
};

}
#endif // __FILTERD_BUFFERING_SINK_H__
