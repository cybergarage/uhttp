#if HAVE_LIBTOOL
#lib_LTLIBRARIES = libuhttp.la
#else
lib_LIBRARIES = libuhttp.a
#endif

INCLUDES = -I$(top_srcdir)/include -I$(top_builddir)/include @HTTP_CFLAGS@ @CLOG_DEBUG_FLAGS@

########################################
# CyberLink
########################################

uhttp_source = \
	../../src/cybergarage/io/cfile.c \
	../../src/cybergarage/io/cfile_list.c \
	../../src/cybergarage/util/clist.c \
	../../src/cybergarage/util/cmutex.c \
	../../src/cybergarage/util/ccond.c \
	../../src/cybergarage/util/cdictionary.c \
	../../src/cybergarage/util/cdictionary_elem.c \
	../../src/cybergarage/util/cstring.c \
	../../src/cybergarage/util/cstring_tokenizer.c \
	../../src/cybergarage/util/cstring_function.c \
	../../src/cybergarage/util/cthread.c \
	../../src/cybergarage/util/cthread_list.c \
	../../src/cybergarage/util/ctime.c \
	../../src/cybergarage/util/clog.c \
	../../src/cybergarage/net/cdatagram_packet.c \
	../../src/cybergarage/net/csocket.c \
	../../src/cybergarage/net/cinterface.c \
	../../src/cybergarage/net/cinterface_list.c \
	../../src/cybergarage/net/cinterface_function.c \
	../../src/cybergarage/net/cnet_function.c \
	../../src/cybergarage/net/curi.c \
	../../src/cybergarage/net/curl.c \
	../../src/cybergarage/http/chttp.c \
	../../src/cybergarage/http/chttp_date.c \
	../../src/cybergarage/http/chttp_header.c \
	../../src/cybergarage/http/chttp_header_list.c \
	../../src/cybergarage/http/chttp_packet.c \
	../../src/cybergarage/http/chttp_persistent_connection.c \
	../../src/cybergarage/http/chttp_request.c \
	../../src/cybergarage/http/chttp_response.c \
	../../src/cybergarage/http/chttp_server.c \
	../../src/cybergarage/http/chttp_server_list.c

########################################
# Library
########################################

libuhttpincludedir = $(includedir)/cybergarage
nobase_libuhttpinclude_HEADERS =  \
        $(uhttp_header)

#if HAVE_LIBTOOL
#libuhttp_la_SOURCES = \
#        $(uhttp_source)
#libuhttp_la_LIBADD = @HTTP_LIBS@
#else
libuhttp_a_SOURCES = \
        $(uhttp_source)
libuhttp_a_CFLAGS = $(AM_CFLAGS)
libuhttp_a_LIBADD = @HTTP_LIBS@
#endif
