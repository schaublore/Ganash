#include "test-graphics-gradient-radial.h"

#include <libgraphics/graphics.h>

void
test_graphics_gradient_radial_test1(void) {
    GraphicsGradientRadial *radial   = graphics_gradient_radial_new();
    GraphicsGradient       *gradient = (GraphicsGradient*)radial;
    graphics_gradient_add_stop(gradient, 0.0, 0.2, 0.2, 0.2, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.8, 0.8, 0.8, 1.0);

    GraphicsGradientStop *stop = (GraphicsGradientStop *) g_list_first(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.2);
}

void
test_graphics_gradient_radial_test2(void) {
    GraphicsGradientRadial* radial = graphics_gradient_radial_new();
    GraphicsGradient* gradient = (GraphicsGradient*)radial;
    graphics_gradient_add_stop(gradient, 0.0, 0.2, 0.2, 0.2, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.8, 0.8, 0.8, 1.0);

    GraphicsGradientStop *stop = (GraphicsGradientStop *) g_list_last(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.8);
}

GTestSuite *
test_graphics_gradient_radial_create_suite(void) {
    GTestSuite *suite_graphics_gradient_radial = g_test_create_suite("radial");

    g_test_suite_add (suite_graphics_gradient_radial, TESTCASE (test_graphics_gradient_radial_test1, NULL));
    g_test_suite_add (suite_graphics_gradient_radial, TESTCASE (test_graphics_gradient_radial_test2, NULL));

	return suite_graphics_gradient_radial;
}
