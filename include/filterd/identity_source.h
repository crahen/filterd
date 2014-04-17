#ifndef  __FILTERD_IDENTITY_SOURCE_H__
#define  __FILTERD_IDENTITY_SOURCE_H__
#include "filterd/source.h"

namespace filterd {

/**
 */
template<typename T>
class IdentitySource : public Source<T> {
  public:
    virtual ~IdentitySource() {}
    virtual T get(long timestamp, const std::string& name) {}
};

}
#endif // __FILTERD_IDENTITY_SOURCE_H__
