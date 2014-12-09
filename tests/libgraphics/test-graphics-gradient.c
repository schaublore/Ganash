#include "test-graphics-gradient.h"
#include "test-graphics-gradient-linear.h"
#include "test-graphics-gradient-radial.h"

#include <libgraphics/graphics.h>


void
test_graphics_gradient_test1(void) {
    GraphicsGradientLinear *linear = graphics_gradient_linear_new();
    GraphicsGradient *gradient = (GraphicsGradient*) linear;
    graphics_gradient_add_stop(gradient, 0.0, 0.4, 0.4, 0.4, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.6, 0.6, 0.6, 1.0);

    GraphicsGradientStop* stop = (GraphicsGradientStop*)g_list_last(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.6);
}

void
test_graphics_gradient_test2(void) {
    GraphicsGradientRadial *radial = graphics_gradient_radial_new(GRAPHICS_GRADIENT_RADIAL_TYPE, NULL);
    GraphicsGradient *gradient = (GraphicsGradient*) radial;
    graphics_gradient_add_stop(gradient, 0.0, 0.4, 0.4, 0.4, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.6, 0.6, 0.6, 1.0);

    GraphicsGradientStop* stop = (GraphicsGradientStop*)g_list_last(gradient->stops)->data;
    g_assert_cmpfloat(stop->color->red, ==, 0.6);
}

void
test_graphics_gradient_test20(void)
{
    cairo_t *cr;
    cairo_surface_t *surface;
    unsigned char *data_surface;
    int width_surface  = 100;
    int height_surface = 100;

    cairo_surface_t *image;
    unsigned char *data_image;
    int width_image;
    int height_image;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width_surface, height_surface);
    cr = cairo_create(surface);

    cairo_pattern_t *pattern;
    pattern = cairo_pattern_create_linear(0.0, 0.0,  100.0, 100.0);
    cairo_pattern_add_color_stop_rgb(pattern, 0.0, 1.0, 0.0, 0.0);
    cairo_pattern_add_color_stop_rgb(pattern, 1.0, 0.0, 0.0, 1.0);

    cairo_set_source(cr, pattern);

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 100.0,   0.0);
    cairo_line_to(cr, 100.0, 100.0);
    cairo_line_to(cr,   0.0, 100.0);
    cairo_line_to(cr,   0.0,   0.0);

    cairo_fill(cr);

    data_surface   = cairo_image_surface_get_data(surface);
    width_surface  = cairo_image_surface_get_width(surface);
    height_surface = cairo_image_surface_get_height(surface);


    //cairo_surface_write_to_png(surface, "/home/instant/workspace/Gtk/ganash/0-3/tests/libgraphics/share/gradient1.test.png");
    //image = cairo_image_surface_create_from_png ("/home/instant/workspace/Gtk/ganash/0-3/tests/libgraphics/share/gradient1.test.png");
    image = cairo_image_surface_create_from_png (TEST_GRAPHICS_SHARE_DIR "/gradient1.test.png");


    data_image   = cairo_image_surface_get_data(image);
    width_image  = cairo_image_surface_get_width(image);
    height_image = cairo_image_surface_get_height(image);

    g_assert_cmpint(width_surface, ==, width_image);
    g_assert_cmpint(height_surface, ==, height_image);

    int rst = memcmp (data_surface, data_image, width_surface * height_surface);
    g_assert_cmpint(rst, ==, 0);


    cairo_surface_destroy(image);
    cairo_surface_destroy(surface);
    cairo_destroy(cr);
}


GTestSuite *
test_graphics_gradient_create_suite(void) {
    GTestSuite *test_suite = g_test_create_suite("gradient");

    g_test_suite_add_suite(test_suite, test_graphics_gradient_linear_create_suite());
    g_test_suite_add_suite(test_suite, test_graphics_gradient_radial_create_suite());

    g_test_suite_add (test_suite, TESTCASE (test_graphics_gradient_test1, NULL));
    g_test_suite_add (test_suite, TESTCASE (test_graphics_gradient_test2, NULL));

    g_test_suite_add (test_suite, TESTCASE (test_graphics_gradient_test20, NULL));

    return test_suite;
}
