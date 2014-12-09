
#include "test-graphics-color.h"
#include "test-graphics-gradient.h"
#include "test-graphics-solid.h"
#include "test-graphics-painter.h"
#include "test-graphics-fill.h"
#include "test-graphics-stroke.h"
#include "test-graphics-image.h"
#include "test-graphics-pattern.h"


GTestSuite *
test_graphics_create_suite(void) {
    GTestSuite *test_suite = g_test_create_suite("libgraphics");

    g_test_suite_add_suite(test_suite, test_graphics_color_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_gradient_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_solid_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_painter_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_fill_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_stroke_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_image_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_pattern_create_suite());


    return test_suite;
}
