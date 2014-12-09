/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * test-lib.c
 * Copyright (C) 2013 Ludovic Schaublore <schaublore@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cairo/cairo.h>
#include "test-lib.h"

void
test_lib_graphics_assert_cmpsurface(toContext to_context, gchar *filename, gboolean preserve, gboolean generate)
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

    cairo_move_to(cr,   0.0,   0.0);
    cairo_line_to(cr, 100.0,   0.0);
    cairo_line_to(cr, 100.0, 100.0);
    cairo_line_to(cr,   0.0, 100.0);
    cairo_line_to(cr,   0.0,   0.0);

    (*to_context)(cr, preserve);


    data_surface   = cairo_image_surface_get_data(surface);
    width_surface  = cairo_image_surface_get_width(surface);
    height_surface = cairo_image_surface_get_height(surface);


    if (generate) {
        gchar *basename = g_path_get_basename(filename);
        gchar *basepath = g_path_get_dirname(filename);
        gchar *f = g_strdup_printf("%s/%s/%s%s", TEST_GRAPHICS_SHARE_DIR, basepath, "_", basename);
        cairo_surface_write_to_png(surface, f);
        g_free(basename);
        g_free(basepath);
        g_free(f);
    }
    //image = cairo_image_surface_create_from_png ("/home/instant/workspace/Gtk/ganash/0-3/tests/libgraphics/share/gradient1.test.png");
    gchar *file = g_strdup_printf("%s%s", TEST_GRAPHICS_SHARE_DIR, filename);
    image = cairo_image_surface_create_from_png (file);
    g_free(file);

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
