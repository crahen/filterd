#include "filterd/http_source.h"
#include "filterd/http_sink.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

namespace filterd {

template <typename T>
HttpSource<T>::HttpSource(const std::string& url) : url(url) {
}

template <typename T>
HttpSource<T>::~HttpSource() {
}

template <typename T>
HttpSink<T>::HttpSink(const std::string& url) : url(url) {
}

template <typename T>
HttpSink<T>::~HttpSink() {
}

template <>
int HttpSource<int>::get(long timestamp, const std::string& name) {
  return 0;
}

template <>
void HttpSink<int>::put(long timestamp, const std::string& name, int value) {
}

}
