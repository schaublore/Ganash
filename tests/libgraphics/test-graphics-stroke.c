#include <cairo/cairo.h>

#include "test-graphics-stroke.h"
#include "test-lib.h"


#include <libgraphics/graphics.h>




void
test_graphics_stroke_to_context1(cairo_t *cr, gboolean preserve) {
    GraphicsSolid* solid = graphics_solid_new_init(0.2, 0.4, 0.8, 1.0);
    GraphicsPainter* painter = graphics_painter_new();
    graphics_painter_set_solid(painter, solid);

    GraphicsStroke* stroke = graphics_stroke_new();
    stroke->painter = painter;
    stroke->width = 2.0;

    graphics_stroke_to_context(stroke, cr, preserve);
}

void
test_graphics_stroke_test1(void) {
    test_lib_graphics_assert_cmpsurface(test_graphics_stroke_to_context1, "stroke1.test.png", FALSE, FALSE);
}

GTestSuite *
test_graphics_stroke_create_suite(void) {
    GTestSuite *suite_graphics_stroke = g_test_create_suite("stroke");

	g_test_suite_add (suite_graphics_stroke, TESTCASE (test_graphics_stroke_test1, NULL));

	return suite_graphics_stroke;
}
