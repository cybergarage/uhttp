#include <string.h>

#include <cybergarage/util/cmutex.h>
#include <cybergarage/util/ctime.h>
#include <cybergarage/util/cthread.h>

#include "uHTTPTestCase.h"

#define CGTEST_THREAD_ADDITIONAL_RETRY	10

////////////////////////////////////////
// testThread
////////////////////////////////////////

static CgMutex *CgTestThreadAdditionalMutex;
static int CgTestThreadAdditionalCounter;

static void CgTestThreadAdditionalFunc(CgThread *)
{
	cg_mutex_lock(CgTestThreadAdditionalMutex);
	
	CgTestThreadAdditionalCounter++;

	cg_mutex_unlock(CgTestThreadAdditionalMutex);
}

void uHTTPTestCase::testThread()
{
	CgTestThreadAdditionalMutex = cg_mutex_new();
	CgTestThreadAdditionalCounter = 0;
	CgThread *threads[CGTEST_THREAD_ADDITIONAL_RETRY];
	for (int i=0; i<CGTEST_THREAD_ADDITIONAL_RETRY; i++) {
		threads[i] = cg_thread_new();
		CPPUNIT_ASSERT(threads[i] != NULL);
		cg_thread_setaction(threads[i], CgTestThreadAdditionalFunc);
		CPPUNIT_ASSERT(cg_thread_start(threads[i]) == TRUE);
	}
	for (int i=0; i<CGTEST_THREAD_ADDITIONAL_RETRY; i++) {
		while (CgTestThreadAdditionalCounter < (i+1))
			cg_sleep(50);
	}
	CPPUNIT_ASSERT(CgTestThreadAdditionalCounter == CGTEST_THREAD_ADDITIONAL_RETRY);
	for (int i=0; i<CGTEST_THREAD_ADDITIONAL_RETRY; i++) {
		CPPUNIT_ASSERT(cg_thread_stop(threads[i]) == TRUE);
		CPPUNIT_ASSERT(cg_thread_isrunnable(threads[i]) == FALSE);
		CPPUNIT_ASSERT(cg_thread_delete(threads[i]) == TRUE);
	}
	cg_mutex_delete(CgTestThreadAdditionalMutex);
	
}
