#ifndef  __FILTERD_IDENTITY_SOURCE_H__
#define  __FILTERD_IDENTITY_SOURCE_H__
#include "filterd/source.h"

namespace filterd {

/**
 */
template<typename T>
class IdentitySource : public AbstractSource<T> {
  public:
    IdentitySource(Source<T>* source) : AbstractSource<T>(source) {}
    virtual ~IdentitySource() {}
};

}
#endif // __FILTERD_IDENTITY_SOURCE_H__
