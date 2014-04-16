#include "filterd/count_min_sketch_sink.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

namespace filterd {

template <typename T>
CountMinSketchSink<T>::CountMinSketchSink(T lower_bound, T upper_bound, size_t num_levels, float epsilon, float delta) 
  : lower_bound(lower_bound), upper_bound(upper_bound), num_levels(num_levels), epsilon(epsilon), delta(delta) {}

template <typename T>
CountMinSketchSink<T>::~CountMinSketchSink() {
}

template <>
void CountMinSketchSink<int>::put(long timestamp, const std::string& name, int value) {
}

}
