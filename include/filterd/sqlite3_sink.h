#ifndef  __FILTERD_SQLITE3_SINK_H__
#define  __FILTERD_SQLITE3_SINK_H__
#include "filterd/sink.h"

namespace filterd {

/**
 */
template<typename T>
class Sqlite3Sink : public Sink<T> {
  public:
    virtual ~Sqlite3Sink() {}
    virtual void put(long timestamp, const std::string& name, T value) {}
};

}
#endif // __FILTERD_SQLITE3_SINK_H__
