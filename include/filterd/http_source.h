#ifndef  __FILTERD_HTTP_SOURCE_H__
#define  __FILTERD_HTTP_SOURCE_H__
#include "filterd/source.h"

namespace filterd {

/**
 */
template<typename T>
class HttpSource : public Source<T> {
  public:
    HttpSource(const std::string& url);
    virtual ~HttpSource();
    virtual T get(long timestamp, const std::string& name);
  private:
    std::string url;
};

}
#endif // __FILTERD_HTTP_SOURCE_H__
