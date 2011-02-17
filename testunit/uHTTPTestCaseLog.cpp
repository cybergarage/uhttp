#include <string.h>

#include <cybergarage/util/clog.h>
#include <cybergarage/util/cmutex.h>
#include <cybergarage/util/cthread.h>

#include "uHTTPTestCase.h"

#define CGTEST_LOG_MESSAGE	"CLOGTEST"
#define CGTEST_LOG_FILENAME	"cglogtest.log"
#define CGTEST_LOG_THREAD_NUM 10

////////////////////////////////////////
// testLog
////////////////////////////////////////

void uHTTPTestCase::testLog()
{
	cg_log_info("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_warning("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_error("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug_l4("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug_l5("%s\n", CGTEST_LOG_MESSAGE);
}

////////////////////////////////////////
// testLogMultiThread
////////////////////////////////////////

static CgMutex *CgTestThreadInfoLoglMutex;
static int CgTestThreadInfoLogCounter;

static void CgTestThreadInfoLogFunc(CgThread *thread)
{
	for (int i=0; i<CGTEST_LOG_THREAD_NUM; i++) {
		cg_log_info("%s\n", CGTEST_LOG_MESSAGE);
		cg_sleep(50);
	}
	
	cg_mutex_lock(CgTestThreadInfoLoglMutex);
	CgTestThreadInfoLogCounter++;
	cg_mutex_unlock(CgTestThreadInfoLoglMutex);
}

void uHTTPTestCase::testLogMultiThread()
{
	CgTestThreadInfoLoglMutex = cg_mutex_new();
	CgTestThreadInfoLogCounter = 0;
	CgThread *threads[CGTEST_LOG_THREAD_NUM];
	for (int i=0; i<CGTEST_LOG_THREAD_NUM; i++) {
		threads[i] = cg_thread_new();
		cg_thread_setaction(threads[i], CgTestThreadInfoLogFunc);
		cg_thread_start(threads[i]);
	}
	while (CgTestThreadInfoLogCounter != CGTEST_LOG_THREAD_NUM)
		cg_sleep(50);
	for (int i=0; i<CGTEST_LOG_THREAD_NUM; i++) {
		cg_thread_stop(threads[i]);
		cg_thread_delete(threads[i]);
	}
	cg_mutex_delete(CgTestThreadInfoLoglMutex);
	
}

////////////////////////////////////////
// testLogFile
////////////////////////////////////////

void uHTTPTestCase::testLogFile()
{
	cg_log_add_target(CGTEST_LOG_FILENAME, SEV_ERROR | SEV_WARNING | SEV_INFO | SEV_DEBUG_L1 | SEV_DEBUG_L2 | SEV_DEBUG_L3);
	
	cg_log_info("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_warning("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_error("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug_l4("%s\n", CGTEST_LOG_MESSAGE);
	cg_log_debug_l5("%s\n", CGTEST_LOG_MESSAGE);
	
	CPPUNIT_ASSERT(remove(CGTEST_LOG_FILENAME) == 0);
}

////////////////////////////////////////
// testLogFileMultiThread
////////////////////////////////////////

void uHTTPTestCase::testLogFileMultiThread()
{
	cg_log_add_target(CGTEST_LOG_FILENAME, SEV_ERROR | SEV_WARNING | SEV_INFO | SEV_DEBUG_L1 | SEV_DEBUG_L2 | SEV_DEBUG_L3);
	
	CgTestThreadInfoLoglMutex = cg_mutex_new();
	CgTestThreadInfoLogCounter = 0;
	CgThread *threads[CGTEST_LOG_THREAD_NUM];
	for (int i=0; i<CGTEST_LOG_THREAD_NUM; i++) {
		threads[i] = cg_thread_new();
		cg_thread_setaction(threads[i], CgTestThreadInfoLogFunc);
		cg_thread_start(threads[i]);
	}
	while (CgTestThreadInfoLogCounter != CGTEST_LOG_THREAD_NUM)
		cg_sleep(50);
	for (int i=0; i<CGTEST_LOG_THREAD_NUM; i++) {
		cg_thread_stop(threads[i]);
		cg_thread_delete(threads[i]);
	}
	cg_mutex_delete(CgTestThreadInfoLoglMutex);
	
}

