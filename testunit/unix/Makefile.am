noinst_PROGRAMS = uhttptestunit

INCLUDES = -I$(top_srcdir)/include -I../

noinst_HEADERS = \
	../uHTTPTestCase.h

uhttptestunit_SOURCES = \
	../uHTTPTestCase.cpp \
	../uHTTPTestCaseDictionary.cpp \
	../uHTTPTestCaseHttp.cpp \
	../uHTTPTestCaseNetwork.cpp \
	../uHTTPTestCaseURI.cpp \
	../cppunitmain.cpp

#if HAVE_LIBTOOL
#uhttptestunit_LDADD = ../../lib/unix/libuhttp.la -lcppunit
#else
uhttptestunit_LDADD = ../../lib/unix/libuhttp.a  -lcppunit
#endif
