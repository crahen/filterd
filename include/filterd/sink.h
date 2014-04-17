#ifndef  __FILTERD_SINK_H__
#define  __FILTERD_SINK_H__

#include <memory>
#include <string>

namespace filterd {

/**
 */
template<typename T>
class Sink {
  public:
    virtual ~Sink() {}

    /**
     */
    virtual void put(long timestamp, const std::string& name, T value) = 0;
};

/**
 */
template<typename T>
class AbstractSink {

  Sink<T>* sink;

  public:
    AbstractSink(Sink<T>* sink) : sink(sink) {}
    virtual ~AbstractSink() {}

    /**
     */
    virtual T put(long timestamp, const std::string& name) {
      if (sink)
        sink->put(timestamp, name);
    }

};

/**
 */
template<typename T>
class SinkFactory {

  public:
    virtual ~SinkFactory() {}

    /**
     */
    virtual std::unique_ptr<Sink<T>> newSink() = 0;

};

}
#endif // __FILTERD_SINK_H__
