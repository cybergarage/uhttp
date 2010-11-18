#ifndef CPP_UNIT_UHTTPTESTCASE_H
#define CPP_UNIT_UHTTPTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

class uHTTPTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( uHTTPTestCase );

  CPPUNIT_TEST( testDictionary );
  CPPUNIT_TEST( testURI );
  CPPUNIT_TEST( testNetworkInterface );
  CPPUNIT_TEST( testHttpServer );
  
  CPPUNIT_TEST_SUITE_END();

public:

	void setUp();
	void tearDown();

protected:
  
	void testDictionary();
	void testURI();
	void testNetworkInterface();
	void testHttpServer();
};

#endif
