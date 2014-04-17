#ifndef  __FILTERD_COUNT_MIN_SKETCH_ESTIMATOR_H__
#define  __FILTERD_COUNT_MIN_SKETCH_ESTIMATOR_H__

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <vector>

namespace filterd {

/**
 * A CountMinSketch is an estimator that can summarize a data stream,
 * while retaining enough information to estimate frequence and 
 * quantiles.
 *
 * Original Paper:
 * Cormode & Muthukrishnan, "An Improved Data Stream Summary:
 * The Count-Min Sketch and its Applications", Proceedings of Latin American
 * Theoretical Informatics (LATIN), pages 29-38, 2004.
 * http://dimacs.rutgers.edu/~graham/pubs/papers/cm-full.pdf
 *
 * Implementation From Streamlib:
 * https://github.com/addthis/stream-lib/blob/master/src/main/java/com/clearspring/analytics/stream/frequency/CountMinSketch.java
 *
 * Implementation From Larson:
 * https://github.com/laserson/dsq/blob/master/dsq.py
 */
template<typename T>
class CountMinSketch {

  typedef std::vector<T> Row;
  typedef std::vector<Row> Table;
  typedef std::vector<long> Hash;

  size_t depth;
  size_t width;
  size_t totalElements;
  double eps;
  double confidence; 
  Table table;
  Hash hash;

public:

  CountMinSketch(size_t depth, size_t width) : depth(depth), width(width), totalElements(0), hash(depth) {
    eps = 2.0 / width;
    confidence = 1 - 1 / std::pow(2, depth);
    for(int i = 0; i < depth; i++) {
      table.push_back(Row(width));
      hash[i] = std::rand();
    }
  }

  void add(T elem) {
    for (int i = 0; i < depth; ++i) {
      table[i][computeHash(elem, i)]++;
    }
    totalElements++;
  }

  size_t count(T elem) {
    size_t count = std::numeric_limits<size_t>::max();
    for (int i = 0; i < depth; i++) {
      count = std::min(count, static_cast<size_t>(table[i][computeHash(elem, i)]));
    }
    return count;
  }

private:

  int computeHash(long val, int i) {
    long h = hash[i] * val;
    // http://www.cs.princeton.edu/courses/archive/fall09/cos521/Handouts/universalclasses.pdf
    h += h >> 32;
    h &= ((1L << 31) - 1);
    return ((int) h) % width;
  }

  // TODO: Make state serializable
  // TODO: Add merge function
 
};

}

#endif //  __FILTERD_COUNT_MIN_SKETCH_ESTIMATOR_H__
