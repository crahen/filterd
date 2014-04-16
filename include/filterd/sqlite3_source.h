#ifndef  __FILTERD_SQLITE3_SOURCE_H__
#define  __FILTERD_SQLITE3_SOURCE_H__
#include "filterd/source.h"

struct sqlite3;

namespace filterd {

/**
 */
template<typename T>
class Sqlite3Source : public Source<T> {
  public:
    Sqlite3Source(const std::string& db_path);
    virtual ~Sqlite3Source();
    virtual T get(long timestamp, const std::string& name);
  private:
    sqlite3 *db;
};

template <>
int Sqlite3Source<int>::get(long timestamp, const std::string& name);

}
#endif // __FILTERD_SQLITE3_SOURCE_H__
