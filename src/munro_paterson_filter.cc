#include "filterd/munro_paterson_sink.h"
#include "../src/munro_paterson_estimator.h"

namespace filterd {

template <typename T>
MunroPatersonSink<T>::MunroPatersonSink(Sink<T>* sink, size_t numQuantiles) : AbstractSink<T>(sink), numQuantiles(numQuantiles) {
}

template <typename T>
MunroPatersonSink<T>::~MunroPatersonSink() {
}

template <>
void MunroPatersonSink<int>::put(long timestamp, const std::string& name, int value) {
}

}
