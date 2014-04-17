AM_CPPFLAGS = -std=c++0x \
							-I$(top_srcdir)/include \
							-I$(top_srcdir) \
							$(SQLITE3_CFLAGS) \
							$(LIBFCGI_CFLAGS) \
							$(BOOST_CFLAGS) \
						  $(BOOST_SYSTEM_CFLAGS) \
							$(BOOST_THREAD_CFLAGS) \
							$(BOOST_UNIT_TEST_FRAMEWORK_CFLAGS)

AM_LDFLAGS = $(SQLITE3_LDFLAGS) \
						 $(LIBFCGI_LDFLAGS) \
						 $(BOOST_LDFLAGS) \
						 $(BOOST_SYSTEM_LDFLAGS) \
						 $(BOOST_SYSTEM_LIBS) \
						 $(BOOST_THREAD_LDFLAGS) \
						 $(BOOST_THREAD_LIBS) \
						 $(BOOST_UNIT_TEST_FRAMEWORK_LDFLAGS) \
						 $(BOOST_UNIT_TEST_FRAMEWORK_LIBS)

TESTS = all_tests
bin_PROGRAMS = all_tests

all_tests_SOURCES = all_tests.cc \
										count_min_sketch_test.cc \
										munro_paterson_estimator_test.cc
