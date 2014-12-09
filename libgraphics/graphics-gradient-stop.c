/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient-stop.c
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

#include "graphics.h"
#include "graphics-gradient-stop.h"


static void graphics_gradient_stop_class_init(GraphicsGradientStopClass *klass);
static void graphics_gradient_stop_init(GraphicsGradientStop *gobject);

G_DEFINE_TYPE (GraphicsGradientStop, graphics_gradient_stop, G_TYPE_OBJECT)

static void
graphics_gradient_stop_finalize(GObject *g_object)
{
    /* TODO: Add deinitalization code here */
    GraphicsGradientStop *stop = GRAPHICS_GRADIENT_STOP(g_object);
    g_object_unref(stop->color);

    G_OBJECT_CLASS (graphics_gradient_stop_parent_class)->finalize (g_object);
}

static void
graphics_gradient_stop_class_init(GraphicsGradientStopClass *klass)
{
	GObjectClass *gobject_class;

    gobject_class = (GObjectClass *) klass;
    gobject_class->finalize = graphics_gradient_stop_finalize;

	graphics_gradient_stop_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_gradient_stop_init (GraphicsGradientStop *object)
{
    object->offset = 0.0;
    object->color  = graphics_color_new();
}

GraphicsGradientStop *
graphics_gradient_stop_new (void)
{
    GraphicsGradientStop *stop = g_object_new (graphics_gradient_stop_get_type (), NULL);
    return stop;
}

GraphicsGradientStop *
graphics_gradient_stop_new_init (gdouble offset, gdouble red, gdouble green, gdouble blue, gdouble alpha)
{
    GraphicsGradientStop *stop = g_object_new (graphics_gradient_stop_get_type (), NULL);

    stop->color->red   = red;
    stop->color->green = green;
    stop->color->blue  = blue;
    stop->color->alpha = alpha;
    stop->offset = offset;

    return stop;
}
