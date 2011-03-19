#include "uHTTPTestCase.h"

#include <cybergarage/net/curi.h>
#include <cybergarage/util/clog.h>

////////////////////////////////////////
// testURI
////////////////////////////////////////

#define UHTTP_TESTCASE_NET_URI_PATH "/test.cgi"
#define UHTTP_TESTCASE_NET_URI_PARAM1_NAME "abc"
#define UHTTP_TESTCASE_NET_URI_PARAM2_NAME "defgh"
#define UHTTP_TESTCASE_NET_URI_PARAM1_VALUE "123"
#define UHTTP_TESTCASE_NET_URI_PARAM2_VALUE "45678"

#define UHTTP_TESTCASE_NET_URI_FRAGMENT "fragment"

void uHTTPTestCase::testURI()
{
	CgNetURI *uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_URI_PATH "?" 
		UHTTP_TESTCASE_NET_URI_PARAM1_NAME "=" UHTTP_TESTCASE_NET_URI_PARAM1_VALUE "&"
		UHTTP_TESTCASE_NET_URI_PARAM2_NAME "=" UHTTP_TESTCASE_NET_URI_PARAM2_VALUE
		"#" UHTTP_TESTCASE_NET_URI_FRAGMENT);
	CPPUNIT_ASSERT(cg_streq(cg_net_uri_getpath(uri), UHTTP_TESTCASE_NET_URI_PATH));
	CPPUNIT_ASSERT(cg_streq(cg_net_uri_getquery(uri), 
		UHTTP_TESTCASE_NET_URI_PARAM1_NAME "=" UHTTP_TESTCASE_NET_URI_PARAM1_VALUE "&"
		UHTTP_TESTCASE_NET_URI_PARAM2_NAME "=" UHTTP_TESTCASE_NET_URI_PARAM2_VALUE
		));
	CPPUNIT_ASSERT(cg_streq(cg_net_uri_getfragment(uri), UHTTP_TESTCASE_NET_URI_FRAGMENT));
	CgDictionary *paramDir = cg_net_uri_getquerydictionary(uri);
	CgDictionaryElement *paramElem;
	paramElem = cg_dictionary_gets(paramDir);
	CPPUNIT_ASSERT(paramElem != NULL);
	CPPUNIT_ASSERT(cg_streq(cg_dictionary_element_getkey(paramElem), UHTTP_TESTCASE_NET_URI_PARAM1_NAME));
	CPPUNIT_ASSERT(cg_streq(cg_dictionary_element_getvalue(paramElem), UHTTP_TESTCASE_NET_URI_PARAM1_VALUE));
	paramElem = cg_dictionary_element_next(paramElem);
	CPPUNIT_ASSERT(paramElem != NULL);
	CPPUNIT_ASSERT(cg_streq(cg_dictionary_element_getkey(paramElem), UHTTP_TESTCASE_NET_URI_PARAM2_NAME));
	CPPUNIT_ASSERT(cg_streq(cg_dictionary_element_getvalue(paramElem), UHTTP_TESTCASE_NET_URI_PARAM2_VALUE));

	cg_net_uri_delete(uri);
}

////////////////////////////////////////
// testAbsoluteURI
////////////////////////////////////////

#define UHTTP_TESTCASE_NET_ABSOLUTEURI "http://www.yahoo.co.jp:80/rss.xml"

#define UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_01 "http://www.yahoo.co.jp"
#define UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_01 "rss.xml"

#define UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_02 "http://www.yahoo.co.jp"
#define UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_02 "/rss.xml"

#define UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_03 "http://www.yahoo.co.jp/"
#define UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_03 "/rss.xml"

#define UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_04 "http://www.yahoo.co.jp/"
#define UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_04 "rss.xml"

#define UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_05 "http://www.yahoo.co.jp"
#define UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_05 "rss.xml"

void uHTTPTestCase::testAbsoluteURI()
{
	CgNetURI *uri;
    char *uriString;
    
    uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_01);
    cg_net_uri_setpath(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_01);
    uriString = cg_net_uri_getvalue(uri);
	cg_log_info("%s\n", uriString);
	CPPUNIT_ASSERT(cg_streq(uriString, UHTTP_TESTCASE_NET_ABSOLUTEURI));
	cg_net_uri_delete(uri);
    
    uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_02);
    cg_net_uri_setpath(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_02);
    uriString = cg_net_uri_getvalue(uri);
	cg_log_info("%s\n", uriString);
	CPPUNIT_ASSERT(cg_streq(uriString, UHTTP_TESTCASE_NET_ABSOLUTEURI));
	cg_net_uri_delete(uri);

    uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_03);
    cg_net_uri_setpath(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_03);
    uriString = cg_net_uri_getvalue(uri);
	cg_log_info("%s\n", uriString);
	CPPUNIT_ASSERT(cg_streq(uriString, UHTTP_TESTCASE_NET_ABSOLUTEURI));
	cg_net_uri_delete(uri);    

    uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_04);
    cg_net_uri_setpath(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_04);
    uriString = cg_net_uri_getvalue(uri);
	cg_log_info("%s\n", uriString);
	CPPUNIT_ASSERT(cg_streq(uriString, UHTTP_TESTCASE_NET_ABSOLUTEURI));
	cg_net_uri_delete(uri);    

    uri = cg_net_uri_new();
	cg_net_uri_setvalue(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_HOST_05);
    cg_net_uri_setpath(uri, UHTTP_TESTCASE_NET_ABSOLUTEURI_PATH_05);
    uriString = cg_net_uri_getvalue(uri);
	cg_log_info("%s\n", uriString);
	CPPUNIT_ASSERT(cg_streq(uriString, UHTTP_TESTCASE_NET_ABSOLUTEURI));
	cg_net_uri_delete(uri);    
}


