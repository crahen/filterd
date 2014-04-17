#ifndef  __FILTERD_MUNRO_PATERSON_ESTIMATOR_H__
#define  __FILTERD_MUNRO_PATERSON_ESTIMATOR_H__

#include <algorithm>
#include <cmath>
#include <vector>

namespace filterd {

/**
 * A MunroPatersonEstimator is an estimator that can compute a set of quantiles
 * for a stream data using a relatively small, bounded amount of storage.
 *
 * Original Paper:
 * Munro & Paterson, "Selection and Sorting with Limited Storage",
 * Theoretical Computer Science, Vol 12, p 315-323, 1980.
 * http://scholar.google.com/scholar?q=munro+paterson
 *
 * Implementation From Cloudera:
 * https://github.com/cloudera/ades/blob/master/src/main/java/com/cloudera/science/
 *
 * Implementation From Sawzall:
 * https://code.google.com/p/szl/source/browse/trunk/src/emitters/szlquantile.cc
 */
template<typename T>
class MunroPatersonEstimator {

  typedef std::vector<T> Buffer;
  typedef std::vector<Buffer*> BufferList;

  BufferList buffers;
  size_t numQuantiles;
  size_t maxElementsPerBuffer;
  size_t totalElements;
  T max;
  T min;

public:

  MunroPatersonEstimator(size_t numQuantiles) : numQuantiles(numQuantiles), totalElements(0) {
    size_t MAX_TOTAL_ELEMS = 1024L * 1024L * 1024L * 1024L;
    double epsilon = 1.0 / (numQuantiles - 1.0);
    int b = 2;
    while ((b - 2) * (0x1L << (b - 2)) + 0.5 <= epsilon * MAX_TOTAL_ELEMS) {
      ++b;
    }
    maxElementsPerBuffer = (int) (MAX_TOTAL_ELEMS / (0x1L << (b - 1)));
  }

  ~MunroPatersonEstimator() {
    for(size_t i = 0; i < buffers.size(); i++) {
      if (buffers[i] != nullptr) {
        delete buffers[i];
      }
    }
  }

  void quantiles(std::vector<T>& result) {

    result.clear();
    result.push_back(min);
    
    if (buffers[0] != nullptr) {
      std::sort(buffers[0]->begin(), buffers[0]->end());
    }
    if (buffers[1] != nullptr) {
      std::sort(buffers[1]->begin(), buffers[1]->end());
    }

    std::vector<int> index;
    for (int i = 0; i < buffers.size(); i++) {
      index.push_back(0);
    }
    long S = 0;
    for (int i = 1; i <= numQuantiles - 2; i++) {
      long targetS = (long) std::ceil(i * (totalElements / (numQuantiles - 1.0)));
      while (true) {
        double smallest = max;
        int minBufferId = -1;
        for (int j = 0; j < buffers.size(); j++) {
          if (buffers[j] != nullptr && index[j] < buffers[j]->size()) {
            if (!(smallest < buffers[j]->at(index[j]))) {
              smallest = buffers[j]->at(index[j]);
              minBufferId = j;
            }
          }
        }
        
        long incrementS = minBufferId <= 1 ? 1L : (0x1L << (minBufferId - 1));
        if (S + incrementS >= targetS) {
          result.push_back(smallest);
          break;
        } else {
          index[minBufferId]++;
          S += incrementS;
        }
      }
    }
    result.push_back(max);
  }

  void add(T elem) {
    if (totalElements == 0 || elem < min) {
      min = elem;
    }
    if (totalElements == 0 || max < elem) {
      max = elem;
    }
    if (totalElements > 0 && totalElements % (2 * maxElementsPerBuffer) == 0) {
      std::sort(buffers[0]->begin(), buffers[0]->end());
      std::sort(buffers[1]->begin(), buffers[1]->end());
      recursiveCollapse(buffers[0], 1);
    }
    ensureBuffer(0);
    ensureBuffer(1);
    int index = buffers[0]->size() < maxElementsPerBuffer ? 0 : 1;
    buffers[index]->push_back(elem);
    totalElements++;
  }

private:

  void ensureBuffer(size_t level) {
    while (buffers.size() < level + 1) {
      buffers.push_back(nullptr);
    }
    if (buffers[level] == nullptr) {
      buffers[level] = new Buffer();
    }
  }

  void collapse(Buffer* a, Buffer* b, Buffer* out) {
    int indexA = 0, indexB = 0, count = 0;
    T smaller;
    while (indexA < maxElementsPerBuffer || indexB < maxElementsPerBuffer) {
      if (indexA >= maxElementsPerBuffer || (indexB < maxElementsPerBuffer && a->at(indexA) >= b->at(indexB))) {
        smaller = b->at(indexB++);
      } else {
        smaller = a->at(indexA++);
      }
      if (count++ % 2 == 0) {
        out->push_back(smaller);
      }
    }
    a->clear();
    b->clear();
  }

  void recursiveCollapse(Buffer* a, size_t level) {
    ensureBuffer(level + 1);
    Buffer* merged = nullptr;
    if (buffers[level + 1]->empty()) {
      merged = buffers[level + 1];
    } else {
      merged = new Buffer(maxElementsPerBuffer);
    }
    collapse(buffers[level + 1], a, merged);
    if(buffers[level + 1] != merged) {
      recursiveCollapse(merged, level + 1);
    }
  }

  // TODO: Make state serializable
  // TODO: Add merge function
 
};

}

#endif //  __FILTERD_MUNRO_PATERSON_ESTIMATOR_H__
