#ifndef  __FILTERD_H__
#define  __FILTERD_H__

namespace filterd {

template<typename T>
class Sink<T> {
  public:
    virtual ~Sink() {}
    virtual void putData(long timestamp, const std::string& name, T value) = 0;
};

template<typename T>
class Source<T> {
  public:
    virtual ~Source() {}
    virtual T getData(long timestamp, const std::string& name) = 0;
};

}

#endif // __FILTERD_H__
