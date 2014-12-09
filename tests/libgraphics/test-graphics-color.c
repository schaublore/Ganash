#include "test-graphics-color.h"

#include <libgraphics/graphics.h>


void
test_graphics_color_test1(void) {
    GraphicsColor *color = graphics_color_new();
    color->red   = 1.0;
    color->green = 1.0;
    color->blue  = 1.0;
    color->alpha = 1.0;

    g_assert_cmpfloat(color->red,   ==, 1.0);
    g_assert_cmpfloat(color->green, ==, 1.0);
    g_assert_cmpfloat(color->blue,  ==, 1.0);
    g_assert_cmpfloat(color->alpha, ==, 1.0);
}

void
test_graphics_color_test2(void) {
    GraphicsColor *color = graphics_color_new_rgb(0.5, 0.3, 0.2);
    g_assert_cmpfloat(color->red,   ==, 0.5);
    g_assert_cmpfloat(color->green, ==, 0.3);
    g_assert_cmpfloat(color->blue,  ==, 0.2);
    g_assert_cmpfloat(color->alpha, ==, 1.0);
}

void
test_graphics_color_test3(void) {
    GraphicsColor *color = graphics_color_new_rgba(0.5, 0.3, 0.2, 1.0);
    g_assert_cmpfloat(color->red,   ==, 0.5);
    g_assert_cmpfloat(color->green, ==, 0.3);
    g_assert_cmpfloat(color->blue,  ==, 0.2);
    g_assert_cmpfloat(color->alpha, ==, 1.0);
}

void
test_graphics_color_test4(void) {
    GraphicsColor *color = graphics_color_new_gray(0.5);
    g_assert_cmpfloat(color->red,   ==, 0.5);
    g_assert_cmpfloat(color->green, ==, 0.5);
    g_assert_cmpfloat(color->blue,  ==, 0.5);
    g_assert_cmpfloat(color->alpha, ==, 1.0);
}

GTestSuite *
test_graphics_color_create_suite(void) {
    GTestSuite *suite_graphics_color = g_test_create_suite("color");

    g_test_suite_add (suite_graphics_color, TESTCASE (test_graphics_color_test1, NULL));
    g_test_suite_add (suite_graphics_color, TESTCASE (test_graphics_color_test2, NULL));
    g_test_suite_add (suite_graphics_color, TESTCASE (test_graphics_color_test3, NULL));
    g_test_suite_add (suite_graphics_color, TESTCASE (test_graphics_color_test4, NULL));

	return suite_graphics_color;
}
