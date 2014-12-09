#include "test-graphics-image.h"

#include <libgraphics/graphics.h>


void
test_graphics_image_test1(void) {
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

    GraphicsImage   *img     = graphics_image_new_from_uri(TEST_GRAPHICS_SHARE_DIR "pattern.png");
    graphics_image_scale(img, 0.1, 0.1);
    GraphicsPainter *painter = graphics_painter_new();
    graphics_painter_set_image(painter, img);
    GraphicsFill  *fill  = graphics_fill_new();
    fill->painter = painter;

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 100.0,   0.0);
    cairo_line_to(cr, 100.0, 100.0);
    cairo_line_to(cr,   0.0, 100.0);
    cairo_line_to(cr,   0.0,   0.0);


    graphics_fill_to_context(fill, cr, FALSE);
    //cairo_surface_write_to_png(surface, TEST_GRAPHICS_SHARE_DIR "/pattern.test.png");


    data_surface   = cairo_image_surface_get_data(surface);
    width_surface  = cairo_image_surface_get_width(surface);
    height_surface = cairo_image_surface_get_height(surface);

    image = cairo_image_surface_create_from_png (TEST_GRAPHICS_SHARE_DIR "/pattern.test.png");

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
test_graphics_image_create_suite(void) {
    GTestSuite *suite_graphics_image = g_test_create_suite("image");

	g_test_suite_add (suite_graphics_image, TESTCASE (test_graphics_image_test1, NULL));

	return suite_graphics_image;
}
