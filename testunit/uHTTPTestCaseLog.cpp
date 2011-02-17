#include <string.h>

#include <cybergarage/util/clog.h>

#include "uHTTPTestCase.h"

#define CGTEST_LOG_MESSAGE	"CLOGTEST"

////////////////////////////////////////
// testLog
////////////////////////////////////////

void uHTTPTestCase::testLog()
{
	cg_log_info("%s", CGTEST_LOG_MESSAGE);
	cg_log_warning("%s", CGTEST_LOG_MESSAGE);
	cg_log_error("%s", CGTEST_LOG_MESSAGE);
	cg_log_debug("%s", CGTEST_LOG_MESSAGE);
	cg_log_debug_l4("%s", CGTEST_LOG_MESSAGE);
	cg_log_debug_l5("%s", CGTEST_LOG_MESSAGE);
}
