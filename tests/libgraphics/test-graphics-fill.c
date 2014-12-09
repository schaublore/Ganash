#include <cairo/cairo.h>

#include "test-graphics-fill.h"
#include "test-lib.h"

#include <libgraphics/graphics.h>


void
test_graphics_fill_to_context1(cairo_t *cr, gboolean preserve) {
    GraphicsSolid* solid = graphics_solid_new_init(0.2, 0.4, 0.8, 1.0);
    GraphicsPainter* painter = graphics_painter_new();
    graphics_painter_set_solid(painter, solid);

    GraphicsFill* fill = graphics_fill_new();
    fill->painter = painter;

    graphics_fill_to_context(fill, cr, preserve);
}

void
test_graphics_fill_to_context2(cairo_t *cr, gboolean preserve) {
    GraphicsGradientLinear *linear   = graphics_gradient_linear_new();
    GraphicsGradient       *gradient = (GraphicsGradient*)linear;
    graphics_gradient_add_stop(gradient,  0.0, 0.0, 1.0, 1.0, 1.0);
    graphics_gradient_add_stop(gradient, 0.25, 0.0, 1.0, 0.0, 1.0);
    graphics_gradient_add_stop(gradient, 0.75, 1.0, 0.0, 0.0, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.0, 0.0, 1.0, 1.0);

    linear->x0 = 0;
    linear->y0 = 0;
    linear->x1 = 100;
    linear->y1 = 0;

    GraphicsPainter    *painter      = graphics_painter_new();
    graphics_painter_set_gradient(painter, gradient);

    GraphicsFill* fill = graphics_fill_new();
    fill->painter = painter;

    graphics_fill_to_context(fill, cr, preserve);
}

void
test_graphics_fill_to_context3(cairo_t *cr, gboolean preserve) {
    GraphicsGradientRadial *radial = graphics_gradient_radial_new();
    GraphicsGradient *gradient = (GraphicsGradient*) radial;
    graphics_gradient_add_stop(gradient, 0.0, 1.0, 0.0, 0.0, 1.0);
    graphics_gradient_add_stop(gradient, 1.0, 0.0, 0.0, 1.0, 1.0);

    radial->cx0 = 100;
    radial->cy0 = 100;
    radial->cx1 = 100;
    radial->cy1 = 100;
    radial->radius0 = 0;
    radial->radius1 = 100;

    GraphicsPainter *painter = graphics_painter_new(GRAPHICS_PAINTER_GRADIENT_TYPE);
    graphics_painter_set_gradient(painter, gradient);

    GraphicsFill* fill = graphics_fill_new();
    fill->painter = painter;

    graphics_fill_to_context(fill, cr, preserve);
}

void
test_graphics_fill_test1(void) {
    test_lib_graphics_assert_cmpsurface(test_graphics_fill_to_context1, "fill1.test.png", FALSE, FALSE);
}

void
test_graphics_fill_test2(void) {
    test_lib_graphics_assert_cmpsurface(test_graphics_fill_to_context2, "fill2.test.png", FALSE, FALSE);
}

void
test_graphics_fill_test3(void) {
    test_lib_graphics_assert_cmpsurface(test_graphics_fill_to_context3, "fill3.test.png", FALSE, FALSE);
}

GTestSuite *
test_graphics_fill_create_suite(void) {
    GTestSuite *suite_graphics_fill = g_test_create_suite("fill");

    g_test_suite_add (suite_graphics_fill, TESTCASE (test_graphics_fill_test1, NULL));
    g_test_suite_add (suite_graphics_fill, TESTCASE (test_graphics_fill_test2, NULL));
    g_test_suite_add (suite_graphics_fill, TESTCASE (test_graphics_fill_test3, NULL));

	return suite_graphics_fill;
}
