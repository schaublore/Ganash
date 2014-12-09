
#include "tests/lib.h"
#include "test-suite.h"



int
main(int argc, char *argv[])
{
    g_type_init();
    g_test_init (&argc, &argv, NULL);

    GTestSuite *suite = g_test_get_root();

    GTestSuite *suite_graphics = test_graphics_create_suite();
    g_test_suite_add_suite(suite, suite_graphics);

    g_print("\n");
    g_test_run_suite(suite);

    return 0;
}
