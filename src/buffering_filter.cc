#include "filterd/buffering_sink.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

namespace filterd {

template <typename T>
BufferingSink<T>::BufferingSink(Sink<T>* sink, size_t size) : AbstractSink<T>(sink), size(size) {} 

template <typename T>
BufferingSink<T>::~BufferingSink() {
}

template <>
void BufferingSink<int>::put(long timestamp, const std::string& name, int value) {
}

}
