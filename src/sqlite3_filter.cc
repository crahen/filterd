#include "filterd/sqlite3_source.h"
#include "filterd/sqlite3_sink.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

namespace filterd {

template <typename T>
Sqlite3Source<T>::Sqlite3Source(const std::string& db_path) {
  int rc = sqlite3_open(db_path.c_str(), &db);
  if(SQLITE_OK != rc) {
    fprintf(stderr, "Can't open database %s (%i): %s\n", db_path.c_str(), rc, sqlite3_errmsg(db));
    exit(1);
  }
}

template <typename T>
Sqlite3Source<T>::~Sqlite3Source() {
  sqlite3_close(db);
}

template <typename T>
Sqlite3Sink<T>::Sqlite3Sink(const std::string& db_path) {
  int rc = sqlite3_open(db_path.c_str(), &db);
  if(SQLITE_OK != rc) {
    fprintf(stderr, "Can't open database %s (%i): %s\n", db_path.c_str(), rc, sqlite3_errmsg(db));
    exit(1);
  }
}

template <typename T>
Sqlite3Sink<T>::~Sqlite3Sink() {
  sqlite3_close(db);
}

template <>
int Sqlite3Source<int>::get(long timestamp, const std::string& name) {
  return 0;
}

template <>
void Sqlite3Sink<int>::put(long timestamp, const std::string& name, int value) {
}

}
