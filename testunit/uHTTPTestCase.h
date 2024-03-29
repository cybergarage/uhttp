#ifndef CPP_UNIT_UHTTPTESTCASE_H
#define CPP_UNIT_UHTTPTESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

class uHTTPTestCase : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( uHTTPTestCase );

	CPPUNIT_TEST( testDictionary );
	CPPUNIT_TEST( testMutex );
	//CPPUNIT_TEST( testThread );
	CPPUNIT_TEST( testLog );
	//CPPUNIT_TEST( testLogMultiThread );
	//CPPUNIT_TEST( testLogFile );
	//CPPUNIT_TEST( testLogFileMultiThread );
	CPPUNIT_TEST( testURI );
	CPPUNIT_TEST( testAbsoluteURI );
	//CPPUNIT_TEST( testNetworkInterface );
	//CPPUNIT_TEST( testHttpServer );

	CPPUNIT_TEST_SUITE_END();

public:

	void setUp();
	void tearDown();

protected:
  
	void testDictionary();
	void testMutex();
	void testThread();
	void testLog();
	void testLogMultiThread();
	void testLogFile();
	void testLogFileMultiThread();
	void testURI();
    void testAbsoluteURI();
	void testNetworkInterface();
	void testHttpServer();
};

#endif
