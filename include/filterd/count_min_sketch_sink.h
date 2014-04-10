#ifndef  __FILTERD_COUNT_MIN_SKETCH_SINK_H__
#define  __FILTERD_COUNT_MIN_SKETCH_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 * From:
 * https://github.com/laserson/dsq/blob/master/dsq.py
 */
template<typename T>
class CountMinSketchSink : public Sink<T> {
  public:
    virtual ~CountMinSketchSink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_COUNT_MIN_SKETCH_SINK_H__
