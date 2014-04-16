#include "filterd/udp_source.h"
#include "filterd/udp_sink.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

namespace filterd {

template <typename T>
UdpSource<T>::UdpSource(const std::string& url) : url(url) {
}

template <typename T>
UdpSource<T>::~UdpSource() {
}

template <typename T>
UdpSink<T>::UdpSink(const std::string& url) : url(url) {
}

template <typename T>
UdpSink<T>::~UdpSink() {
}

template <>
int UdpSource<int>::get(long timestamp, const std::string& name) {
  return 0;
}

template <>
void UdpSink<int>::put(long timestamp, const std::string& name, int value) {
}

}
