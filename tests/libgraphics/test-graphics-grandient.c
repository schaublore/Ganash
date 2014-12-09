#include "test-graphics-grandient.h"

#include "libgraphics/graphics-gradient.h"

void
test_graphics_grandient_test1(void) {
	g_test_message("Not implemented");
	/* Add asserts */
}

GTestSuite *
test_graphics_grandient_create_suite(void) {
    GTestSuite *suite_graphics_grandient = g_test_create_suite("gradient");

	g_test_suite_add (suite_graphics_grandient, TESTCASE (test_graphics_grandient_test1, NULL));

	return suite_graphics_grandient;
}
