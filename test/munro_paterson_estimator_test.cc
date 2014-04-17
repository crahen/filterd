#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>
#include "src/munro_paterson_estimator.h"

using namespace filterd;
using namespace std;

BOOST_AUTO_TEST_SUITE(test_munro_paterson)

BOOST_AUTO_TEST_CASE(test_basic) {

  MunroPatersonEstimator<int> estimator(6);
  for(int i = 0; i < 200; i += 2) {
    estimator.add(i);
  }

  vector<int> result;
  estimator.quantiles(result);

  BOOST_CHECK_EQUAL(result[0], 0);
  BOOST_CHECK_EQUAL(result[1], 38);
  BOOST_CHECK_EQUAL(result[2], 78);
  BOOST_CHECK_EQUAL(result[3], 118);
  BOOST_CHECK_EQUAL(result[4], 158);
  BOOST_CHECK_EQUAL(result[5], 198);

}

BOOST_AUTO_TEST_SUITE_END()
