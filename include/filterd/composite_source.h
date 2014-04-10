#ifndef  __FILTERD_NULL_SOURCE_H__
#define  __FILTERD_NULL_SOURCE_H__
#include "filterd/source.h"

namespace filterd {

/**
 */
template<typename T>
class NullSource : public Source<T> {
  public:
    virtual ~NullSource() {}
    virtual T get(long timestamp, const std::string& name) {}
};

}
#endif // __FILTERD_NULL_SOURCE_H__
