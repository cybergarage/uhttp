#include "uHTTPTestCase.h"

#include <cybergarage/util/cdictionary.h>

////////////////////////////////////////
// testNetworkInterface
////////////////////////////////////////

#define UHTTP_TESTCASE_DICTIONARY_KEY "hello"
#define UHTTP_TESTCASE_DICTIONARY_VALUE "hello_value"

void uHTTPTestCase::testDictionary()
{
	CgDictionary *dir;
	char *dirVal;

	/* Basic Unit Test */
	dir = cg_dictionary_new();
	CPPUNIT_ASSERT((dir != NULL));
	cg_dictionary_delete(dir);

	/* Complet Unit Test */
	dir = cg_dictionary_new();
	CPPUNIT_ASSERT((dir != NULL));
	CPPUNIT_ASSERT((cg_dictionary_size(dir) == 0));
	cg_dictionary_setvalue(dir, UHTTP_TESTCASE_DICTIONARY_KEY, UHTTP_TESTCASE_DICTIONARY_VALUE);
	CPPUNIT_ASSERT((cg_dictionary_size(dir) == 1));
	cg_dictionary_setvalue(dir, UHTTP_TESTCASE_DICTIONARY_KEY, UHTTP_TESTCASE_DICTIONARY_VALUE);
	CPPUNIT_ASSERT((cg_dictionary_size(dir) == 1));
	dirVal = cg_dictionary_getvalue(dir, UHTTP_TESTCASE_DICTIONARY_KEY);
	CPPUNIT_ASSERT((0 < cg_strlen(dirVal)));
	CPPUNIT_ASSERT(cg_streq(dirVal, UHTTP_TESTCASE_DICTIONARY_VALUE));
	cg_dictionary_delete(dir);
}
