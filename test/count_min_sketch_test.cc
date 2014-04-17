#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>
#include "src/count_min_sketch.h"

using namespace filterd;
using namespace std;

BOOST_AUTO_TEST_SUITE(test_count_min)

BOOST_AUTO_TEST_CASE(test_basic) {

  CountMinSketch<int> sketch(5, 5);
  for(int i = 0; i < 25; i++) {
    sketch.add(2);
  }
  
  BOOST_CHECK_EQUAL(sketch.count(2), 25);
  
}

BOOST_AUTO_TEST_SUITE_END()
