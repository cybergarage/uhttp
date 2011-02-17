#include <string.h>

#include <cybergarage/util/cmutex.h>

#include "uHTTPTestCase.h"

#define CGTEST_MUTEX_SIMPLE_RETRY	10

////////////////////////////////////////
// testMutex
////////////////////////////////////////

void uHTTPTestCase::testMutex()
{
	for (int i=0; i<CGTEST_MUTEX_SIMPLE_RETRY; i++) {
		CgMutex *mutex = cg_mutex_new();
		CPPUNIT_ASSERT(mutex != NULL);
		for (int j=0; j<CGTEST_MUTEX_SIMPLE_RETRY; j++) {
			CPPUNIT_ASSERT(cg_mutex_lock(mutex) == TRUE);
			CPPUNIT_ASSERT(cg_mutex_unlock(mutex) == TRUE);
		}
		CPPUNIT_ASSERT(cg_mutex_delete(mutex) == TRUE);
	}
}
