/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-path.c
 * Copyright (C) 2014 #AUTHOR# #MAIL#
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

#include "graphics.h"
#include "graphics-path.h"


static void graphics_path_class_init(GraphicsPathClass *klass);
static void graphics_path_init(GraphicsPath *gobject);

G_DEFINE_TYPE (GraphicsPath, graphics_path, G_TYPE_OBJECT)

static void
graphics_path_init (GraphicsPath *object)
{
    object->path = NULL;
}

static void
graphics_path_finalize(GObject *object)
{
    GraphicsPath *path = GRAPHICS_PATH(object);
    if (path->path)
        cairo_path_destroy(path->path);

    G_OBJECT_CLASS (graphics_path_parent_class)->finalize (object);
}
static void
graphics_path_class_init(GraphicsPathClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

    gobject_class->finalize = graphics_path_finalize;

	graphics_path_parent_class = g_type_class_peek_parent (klass);
}


GraphicsPath *
graphics_path_new (void)
{
	return g_object_new (graphics_path_get_type (),
	                     NULL);
}

gboolean graphics_path_is_empty(GraphicsPath *path)
{
    if (!path)
        return TRUE;
    if (!path->path)
        return TRUE;

    if (path->path->num_data>1)
        return FALSE;

    return TRUE;
}

void graphics_path_set(GraphicsPath *path, cairo_path_t *c_path)
{
    if (path->path) {
        cairo_path_destroy(path->path);
    }
    path->path = c_path;
}

void graphics_path_bounding_box(GraphicsPath *path, cairo_t *cr, double *x1, double *y1, double *x2, double *y2)
{
    cairo_path_extents(cr, x1, y1, x2, y2);
}

void graphics_path_to_context(GraphicsPath *path, cairo_t *cr, gboolean preserve)
{
    g_return_if_fail(GRAPHICS_IS_PATH(path));
    g_return_if_fail(path->path);

    if (preserve) {
        cairo_new_sub_path(cr);
    }
    cairo_append_path(cr, path->path);
}


gchar* graphics_path_to_string(GraphicsPath *path)
{
    cairo_path_t *cairo_path = path->path;
    if (!cairo_path)
        return "";

    gchar *str = g_new(gchar, 1);
    str[0] = '\0';
    gchar *tmp;
    int i;
    for (i=0; i<cairo_path->num_data; i += cairo_path->data[i].header.length) {
        switch(cairo_path->data[i].header.type)
        {
        case CAIRO_PATH_MOVE_TO:
            tmp = g_strdup_printf("%sMove{%f, %f}, ", str, cairo_path->data[i+1].point.x, cairo_path->data[i+1].point.y);
            g_free(str);
            str = tmp;
            break;
        case CAIRO_PATH_LINE_TO:
            tmp = g_strdup_printf("%sLine{%f, %f}, ", str, cairo_path->data[i+1].point.x, cairo_path->data[i+1].point.y);
            g_free(str);
            str = tmp;
            break;
        case CAIRO_PATH_CURVE_TO:
            tmp = g_strdup_printf("%sCurve{%f, %f, %f, %f, %f, %f}, ", str,
                                  cairo_path->data[i+1].point.x, cairo_path->data[i+1].point.y,
                                  cairo_path->data[i+2].point.x, cairo_path->data[i+2].point.y,
                                  cairo_path->data[i+3].point.x, cairo_path->data[i+3].point.y);
            g_free(str);
            str = tmp;
            break;
        default:
            g_error("%s: Not implemented", G_STRFUNC);
        }
    }
    return str;
}
