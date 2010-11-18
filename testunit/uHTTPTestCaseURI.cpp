#include "uHTTPTestCase.h"

#include <cybergarage/net/curi.h>

////////////////////////////////////////
// testNetworkInterface
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
