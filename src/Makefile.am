AM_CPPFLAGS = -std=c++0x \
							-I$(top_srcdir)/include \
							$(SQLITE3_CFLAGS) \
							$(LIBFCGI_CFLAGS) \
							$(BOOST_CFLAGS) \
						  $(BOOST_SYSTEM_CFLAGS) \
							$(BOOST_THREAD_CFLAGS)

AM_LDFLAGS = $(SQLITE3_LDFLAGS) \
						 $(LIBFCGI_LDFLAGS) \
						 $(BOOST_SYSTEM_LDFLAGS) \
						 $(BOOST_SYSTEM_LIBS) \
						 $(BOOST_THREAD_LDFLAGS) \
						 $(BOOST_THREAD_LIBS)

bin_PROGRAMS = filterd
filterd_SOURCES = filterd.cc \
									buffering_filter.cc \
									composite_filter.cc \
									http_filter.cc \
									munro_paterson_filter.cc \
									null_filter.cc \
									udp_filter.cc \
									sqlite3_filter.cc
