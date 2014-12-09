#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

#include <glib.h>
#include <glib/gtestutils.h>


#if GLIB_CHECK_VERSION(2,25,12)
typedef GTestFixtureFunc TCFunc;
#else
typedef void (*TCFunc)(void);
#endif

#define TESTCASE(t, d) g_test_create_case (#t, 0, d, NULL, (TCFunc) t, NULL)

#endif /* __TEST__LIB_H__ */
