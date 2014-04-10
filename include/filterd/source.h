#ifndef  __FILTERD_SOURCE_H__
#define  __FILTERD_SOURCE_H__
#include <string>

namespace filterd {

/**
 */
template<typename T>
class Source {
  public:
    virtual ~Source() {}
    virtual T get(long timestamp, const std::string& name) = 0;
};

}
#endif // __FILTERD_SOURCE_H__
