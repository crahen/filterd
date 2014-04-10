#ifndef  __FILTERD_SQLITE3_SOURCE_H__
#define  __FILTERD_SQLITE3_SOURCE_H__
#include "filterd/source.h"
namespace filterd {

/**
 */
template<typename T>
class Sqlite3Source : public Source<T> {
  public:
    virtual ~Sqlite3Source() {}
    virtual T get(long timestamp, const std::string& name) {}
};

}
#endif // __FILTERD_SQLITE3_SOURCE_H__
