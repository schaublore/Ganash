/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-stroke.c
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
#include "graphics-stroke.h"


static void graphics_stroke_class_init(GraphicsStrokeClass *klass);
static void graphics_stroke_init(GraphicsStroke *gobject);

G_DEFINE_TYPE (GraphicsStroke, graphics_stroke, G_TYPE_OBJECT)

static void
graphics_stroke_finalize (GObject *gobject)
{
    GraphicsStroke *self = GRAPHICS_STROKE (gobject);

    if(self->painter)
        g_object_unref (self->painter);

    G_OBJECT_CLASS (graphics_stroke_parent_class)->finalize (gobject);
}

static void
graphics_stroke_class_init(GraphicsStrokeClass *klass)
{
	GObjectClass *gobject_class;

    gobject_class = (GObjectClass *) klass;
    gobject_class->finalize = graphics_stroke_finalize;

	graphics_stroke_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_stroke_init (GraphicsStroke *stroke)
{
    stroke->painter     = NULL;
    stroke->cap         = GRAPHICS_CAP_SQUARE;
    stroke->join        = GRAPHICS_JOIN_BEVEL;
    stroke->width       = 0.0;
    stroke->miter_limit = 1.0;
}

GraphicsStroke *
graphics_stroke_new (void)
{
    GraphicsStroke *stroke = g_object_new (graphics_stroke_get_type (), NULL);
    return stroke;
}


void graphics_stroke_to_context(GraphicsStroke *stroke, cairo_t *cr, gboolean preserve)
{
    g_return_if_fail(GRAPHICS_IS_STROKE(stroke));
    if (!stroke->painter)
        return;

    graphics_painter_to_context(stroke->painter, cr, preserve);
    cairo_set_line_cap(cr, stroke->cap);
    cairo_set_line_join(cr, stroke->join);
    cairo_set_miter_limit(cr, stroke->miter_limit);
    cairo_set_line_width(cr, stroke->width);
    if (preserve) {
        cairo_stroke_preserve(cr);
    } else {
        cairo_stroke(cr);
    }
}
