/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-color.c
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
#include "graphics-color.h"


static void graphics_color_class_init(GraphicsColorClass *klass);
static void graphics_color_init(GraphicsColor *gobject);

G_DEFINE_TYPE (GraphicsColor, graphics_color, G_TYPE_OBJECT)

static void
graphics_color_class_init(GraphicsColorClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

	graphics_color_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_color_init (GraphicsColor *object)
{
    object->red   = 0.0;
    object->green = 0.0;
    object->blue  = 0.0;
    object->alpha = 1.0;
}

GraphicsColor *
graphics_color_new (void)
{
    return g_object_new (graphics_color_get_type (), NULL);
}

GraphicsColor *
graphics_color_new_gray(gdouble value)
{
    GraphicsColor *color = g_object_new (graphics_color_get_type (), NULL);
    color->red   = value;
    color->green = value;
    color->blue  = value;
    color->alpha = 1.0;

    return color;
}

GraphicsColor *
graphics_color_new_rgb(gdouble red, gdouble green, gdouble blue)
{
    GraphicsColor *color = g_object_new (graphics_color_get_type (), NULL);
    color->red   = red;
    color->green = green;
    color->blue  = blue;
    color->alpha = 1.0;

    return color;
}

GraphicsColor *
graphics_color_new_rgba(gdouble red, gdouble green, gdouble blue, gdouble alpha)
{
    GraphicsColor *color = g_object_new (graphics_color_get_type (), NULL);
    color->red   = red;
    color->green = green;
    color->blue  = blue;
    color->alpha = alpha;

    return color;
}
