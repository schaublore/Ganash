#include "test-graphics-pattern.h"

#include "libgraphics/graphics.h"


void
test_graphics_pattern_test1(void) {
    cairo_t *cr;
    cairo_surface_t *surface;
    unsigned char *data_surface;
    int width_surface  = 100;
    int height_surface = 100;

    cairo_surface_t *image;
    unsigned char *data_image;
    int width_image;
    int height_image;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 302, 302);
    cr = cairo_create(surface);

    cairo_matrix_t matrix;
    cairo_matrix_init_scale(&matrix, 0.5, 0.5);
    GraphicsImage     *img   = graphics_image_new_from_uri(TEST_GRAPHICS_SHARE_DIR "pattern_millimetre.png");
    GraphicsPattern *pattern = graphics_pattern_new();
    graphics_pattern_set_surface(pattern, img->surface);
    graphics_pattern_set_extend(pattern, CAIRO_EXTEND_REPEAT);
    graphics_pattern_set_matrix(pattern, &matrix);

    GraphicsPainter *painter = graphics_painter_new();
    graphics_painter_set_pattern(painter, pattern);

    GraphicsFill  *fill  = graphics_fill_new();
    fill->painter = painter;

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 400.0,   0.0);
    cairo_line_to(cr, 400.0, 400.0);
    cairo_line_to(cr,   0.0, 400.0);
    cairo_line_to(cr,   0.0,   0.0);


    graphics_fill_to_context(fill, cr, FALSE);
    cairo_surface_write_to_png(surface, TEST_GRAPHICS_SHARE_DIR "/pattern_millimetre.test.png");

/*
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
    cairo_destroy(cr);*/

}


void
test_graphics_pattern_test2(void) {
    cairo_t *cr;
    cairo_t *cr_image;
    cairo_surface_t *surface;
    cairo_pattern_t *pattern;
    unsigned char *data_surface;
    int width_surface  = 100;
    int height_surface = 100;

    cairo_surface_t *image;
    unsigned char *data_image;
    int width_image;
    int height_image;

    image   = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 50, 50);
    cr_image = cairo_create(image);
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 500, 500);
    cr = cairo_create(surface);

    cairo_set_line_width(cr_image, 1.0);
    cairo_set_line_cap(cr_image, CAIRO_LINE_CAP_SQUARE);

    cairo_set_source_rgb(cr_image, 1.0, 1.0, 1.0);
    cairo_paint(cr_image);


    int x_n = 10;
    int y_n = 10;
    int x_i,y_i;
    int x,y;
    int width = 50;
    int height = 50;
    int size = 5;
    for(x_i=0; x_i<=x_n; x_i++) {
        cairo_move_to(cr_image, size*x_i+0.5, 0.0+0.5);
        cairo_line_to(cr_image, size*x_i+0.5, height+0.5);
    }
    for(y_i=0; y_i<=y_n; y_i++) {
        cairo_move_to(cr_image, 0.0+0.5, size*y_i+0.5);
        cairo_line_to(cr_image, width+0.5, size*y_i+0.5);
    }
    cairo_set_source_rgba(cr_image, 0.0, 0.0, 0.0, 0.3);
    cairo_stroke(cr_image);

    pattern = cairo_pattern_create_for_surface (image);
    cairo_pattern_set_extend (pattern, CAIRO_EXTEND_REPEAT);


    cairo_set_source (cr, pattern);
    cairo_rectangle(cr, 0, 0, 500, 500);
    cairo_fill(cr);

    size *= 5;
    height *= 5;
    width *= 5;
    for(x_i=0; x_i<=x_n; x_i++) {
        cairo_move_to(cr, size*x_i+0.5, 0.0+0.5);
        cairo_line_to(cr, size*x_i+0.5, height+0.5);
    }
    for(y_i=0; y_i<=y_n; y_i++) {
        cairo_move_to(cr, 0.0+0.5, size*y_i+0.5);
        cairo_line_to(cr, width+0.5, size*y_i+0.5);
    }
    cairo_set_line_width(cr, 1.0);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_SQUARE);
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 0.3);
    cairo_stroke(cr);

    size *= 2;
    height *= 2;
    width *= 2;
    for(x_i=0; x_i<=x_n; x_i++) {
        cairo_move_to(cr, size*x_i+0.5, 0.0+0.5);
        cairo_line_to(cr, size*x_i+0.5, height+0.5);
    }
    for(y_i=0; y_i<=y_n; y_i++) {
        cairo_move_to(cr, 0.0+0.5, size*y_i+0.5);
        cairo_line_to(cr, width+0.5, size*y_i+0.5);
    }
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 0.5);
    cairo_stroke(cr);

    size *= 5;
    height *= 5;
    width *= 5;
    for(x_i=0; x_i<=x_n; x_i++) {
        cairo_move_to(cr, size*x_i+0.5, 0.0+0.5);
        cairo_line_to(cr, size*x_i+0.5, height+0.5);
    }
    for(y_i=0; y_i<=y_n; y_i++) {
        cairo_move_to(cr, 0.0+0.5, size*y_i+0.5);
        cairo_line_to(cr, width+0.5, size*y_i+0.5);
    }
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 0.8);
    cairo_stroke(cr);


    cairo_surface_write_to_png(surface, TEST_GRAPHICS_SHARE_DIR "/pattern_my.test.png");

/*
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
    cairo_destroy(cr);*/

}

GTestSuite *
test_graphics_pattern_create_suite(void) {
    GTestSuite *suite_graphics_pattern = g_test_create_suite("pattern");

    g_test_suite_add (suite_graphics_pattern, TESTCASE (test_graphics_pattern_test1, NULL));
    g_test_suite_add (suite_graphics_pattern, TESTCASE (test_graphics_pattern_test2, NULL));

	return suite_graphics_pattern;
}

