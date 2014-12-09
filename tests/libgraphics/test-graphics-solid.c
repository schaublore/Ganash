#include "test-graphics-solid.h"

#include <libgraphics/graphics.h>


void
test_graphics_solid_test1(void) {
    GraphicsSolid *solid_null = graphics_solid_new();
    g_assert(solid_null->color == NULL);

    GraphicsSolid *solid = graphics_solid_new_init(1.0, 1.0, 1.0, 1.0);
    g_assert_cmpfloat(solid->color->red, ==, 1.0);
    g_assert_cmpfloat(solid->color->green, ==, 1.0);
    g_assert_cmpfloat(solid->color->blue, ==, 1.0);
    g_assert_cmpfloat(solid->color->alpha, ==, 1.0);
}

void
test_graphics_solid_test20(void) {
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

    GraphicsSolid *solid = graphics_solid_new_init(0.0, 1.0, 0.0, 1.0);
    graphics_solid_to_context(solid, cr);

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 100.0,   0.0);
    cairo_line_to(cr, 100.0, 100.0);
    cairo_line_to(cr,   0.0, 100.0);
    cairo_line_to(cr,   0.0,   0.0);

    cairo_fill(cr);

    data_surface   = cairo_image_surface_get_data(surface);
    width_surface  = cairo_image_surface_get_width(surface);
    height_surface = cairo_image_surface_get_height(surface);

    //cairo_surface_write_to_png(surface, "/home/instant/workspace/Gtk/ganash/0-3/tests/libgraphics/share/solid1.test.png");
    image = cairo_image_surface_create_from_png (TEST_GRAPHICS_SHARE_DIR "/solid1.test.png");

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
test_graphics_solid_create_suite(void) {
    GTestSuite *suite_graphics_solid = g_test_create_suite("solid");

    g_test_suite_add (suite_graphics_solid, TESTCASE (test_graphics_solid_test1, NULL));
    g_test_suite_add (suite_graphics_solid, TESTCASE (test_graphics_solid_test20, NULL));

	return suite_graphics_solid;
}

