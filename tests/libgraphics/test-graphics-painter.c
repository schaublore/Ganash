#include "test-graphics-painter.h"

#include <libgraphics/graphics.h>


static GraphicsPainter*
test_graphics_painter_create_painter_linear(void) {

    GraphicsGradientLinear   *linear = graphics_gradient_linear_new();
    GraphicsGradient         *gradient = (GraphicsGradient*)linear;
    graphics_gradient_add_stop(gradient, 0.0, 0.1, 0.1, 0.1, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.9, 0.9, 0.9, 1.0);
    linear->x0 = 0;
    linear->y0 = 0;
    linear->x1 = 100;
    linear->y1 = 0;

    GraphicsPainter *painter = graphics_painter_new();
    graphics_painter_set_gradient(painter, gradient);
    //graphics_painter_set_solid(painter, gradient);

    /*GraphicsFill       *graphics     = (GraphicsFill*) g_new(GraphicsFill, 1);
                        graphics->painter = painter;*/

    return painter;
}

void
test_graphics_painter_test1(void) {

    GraphicsPainter   *painter  = test_graphics_painter_create_painter_linear();
    GraphicsGradient  *gradient = painter->data.gradient;
    //GraphicsGradientLinear  *linear = GRAPHICS_GRADIENT_LINEAR(gradient);

    g_assert_cmpuint(painter->type, ==, GRAPHICS_PAINTER_GRADIENT_TYPE);

    GraphicsGradientStop *stop;
    stop = (GraphicsGradientStop *) g_list_first(gradient->stops)->data;
    g_assert_cmpuint(stop->color->red, ==, 0.1);
    stop = (GraphicsGradientStop *) g_list_last(gradient->stops)->data;
    g_assert_cmpuint(stop->color->red, ==, 0.9);
}

void
test_graphics_painter_test20(void)
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

    /*cairo_pattern_t *pattern;
    pattern = cairo_pattern_create_linear(0.0, 0.0,  100.0, 100.0);
    cairo_pattern_add_color_stop_rgb(pattern, 0.0, 1.0, 0.0, 0.0);
    cairo_pattern_add_color_stop_rgb(pattern, 1.0, 0.0, 0.0, 1.0);

    cairo_set_source(cr, pattern);*/

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 100.0,   0.0);
    cairo_line_to(cr, 100.0, 100.0);
    cairo_line_to(cr,   0.0, 100.0);
    cairo_line_to(cr,   0.0,   0.0);

    //cairo_fill(cr);
    GraphicsPainter* painter = test_graphics_painter_create_painter_linear();
    graphics_painter_to_context(painter, cr, FALSE);
    cairo_fill(cr);

    data_surface   = cairo_image_surface_get_data(surface);
    width_surface  = cairo_image_surface_get_width(surface);
    height_surface = cairo_image_surface_get_height(surface);


    //cairo_surface_write_to_png(surface, TEST_GRAPHICS_SHARE_DIR "/gradient2.test.png");
    //image = cairo_image_surface_create_from_png (TEST_GRAPHICS_SHARE_DIR "/gradient2.test.png");
    image = cairo_image_surface_create_from_png (TEST_GRAPHICS_SHARE_DIR "/gradient2.test.png");


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
test_graphics_painter_create_suite(void) {
    GTestSuite *suite_graphics_painter = g_test_create_suite("painter");

    g_test_suite_add (suite_graphics_painter, TESTCASE (test_graphics_painter_test1, NULL));
    g_test_suite_add (suite_graphics_painter, TESTCASE (test_graphics_painter_test20, NULL));

	return suite_graphics_painter;
}
