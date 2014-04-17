#ifndef  __FILTERD_SOURCE_H__
#define  __FILTERD_SOURCE_H__

#include <memory>
#include <string>

namespace filterd {

/**
 */
template<typename T>
class Source {
  public:
    virtual ~Source() {}

    /**
     */
    virtual T get(long timestamp, const std::string& name) = 0;

};

/**
 */
template<typename T>
class AbstractSource {
  std::unique_ptr<Source<T>>& source;
  public:
    AbstractSource(std::unique_ptr<Source<T>>& source) : source(source) {}
    virtual ~AbstractSource() {}

    /**
     */
    virtual T get(long timestamp, const std::string& name) {
      source->get(timestamp, name);
    }

};

/**
 */
template<typename T>
class SourceFactory {
  public:
    virtual ~SourceFactory() {}

    /**
     */
    virtual std::unique_ptr<Source<T>> newSource() = 0;
};

}
#endif // __FILTERD_SOURCE_H__
