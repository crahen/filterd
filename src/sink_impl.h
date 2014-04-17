#ifndef  __FILTERD_SINK_H__
#define  __FILTERD_SINK_H__
#include <string>

namespace filterd {

/**
 */
template<typename T>
class SinkImpl {
  public:
    virtual ~SinkImpl() {}
    virtual void put(long timestamp, const std::string& name, T value) = 0;
};

}
#endif // __FILTERD_SINK_H__
