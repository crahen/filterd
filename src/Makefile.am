AM_CPPFLAGS = -I$(top_srcdir)/include $(SQLITE3_CFLAGS) $(LIBFCGI_CFLAGS) $(BOOST_CFLAGS) $(BOOST_THREAD_CFLAGS) $(BOOST_SYSTEM_CFLAGS)
AM_LDFLAGS = $(SQLITE3_LDFLAGS) $(LIBFCGI_LDFLAGS) $(BOOST_LDFLAGS) $(BOOST_THREAD_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS)

bin_PROGRAMS = filterd
filterd_SOURCES = filterd.cc \
									buffering_filter.cc \
									composite_filter.cc \
									count_min_sketch_filter.cc \
									http_filter.cc \
									null_filter.cc \
									udp_filter.cc \
									sqlite3_filter.cc
