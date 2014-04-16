#ifndef  __FILTERD_SQLITE3_SINK_H__
#define  __FILTERD_SQLITE3_SINK_H__
#include "filterd/sink.h"

struct sqlite3;

namespace filterd {

/**
 */
template<typename T>
class Sqlite3Sink : public Sink<T> {
  public:
    Sqlite3Sink(const std::string& db_path);
    virtual ~Sqlite3Sink();
    virtual void put(long timestamp, const std::string& name, T value);
  private:
    sqlite3* db;
};

template <>
void Sqlite3Sink<int>::put(long timestamp, const std::string& name, int value);

}
#endif // __FILTERD_SQLITE3_SINK_H__
