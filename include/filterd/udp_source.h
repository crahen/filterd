#ifndef  __FILTERD_UDP_SOURCE_H__
#define  __FILTERD_UDP_SOURCE_H__
#include "filterd/source.h"

namespace filterd {

/**
 */
template<typename T>
class UdpSource : public Source<T> {
  public:
    virtual ~UdpSource() {}
    virtual T get(long timestamp, const std::string& name) {}
};

}
#endif // __FILTERD_UDP_SOURCE_H__
