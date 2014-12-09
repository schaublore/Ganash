#include "test-graphics-gradient-linear.h"

#include <libgraphics/graphics.h>


void
test_graphics_gradient_linear_test1(void) {
    GraphicsGradientLinear *linear   = graphics_gradient_linear_new();
    GraphicsGradient       *gradient = (GraphicsGradient*)linear;
    graphics_gradient_add_stop(gradient, 0.0, 0.2, 0.2, 0.2, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.8, 0.8, 0.8, 1.0);

    GraphicsGradientStop *stop = (GraphicsGradientStop *) g_list_first(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.2);
}

void
test_graphics_gradient_linear_test2(void) {
    GraphicsGradientLinear* linear = graphics_gradient_linear_new();
    GraphicsGradient* gradient = (GraphicsGradient*)linear;
    graphics_gradient_add_stop(gradient, 0.0, 0.2, 0.2, 0.2, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.8, 0.8, 0.8, 1.0);

    GraphicsGradientStop *stop = (GraphicsGradientStop *) g_list_last(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.8);
}

GTestSuite *
test_graphics_gradient_linear_create_suite(void) {
    GTestSuite *suite_graphics_gradient_linear = g_test_create_suite("linear");

    g_test_suite_add (suite_graphics_gradient_linear, TESTCASE (test_graphics_gradient_linear_test1, NULL));
    g_test_suite_add (suite_graphics_gradient_linear, TESTCASE (test_graphics_gradient_linear_test2, NULL));

	return suite_graphics_gradient_linear;
}
