/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient-radial.c
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
#include "graphics-gradient.h"
#include "graphics-gradient-radial.h"


static void graphics_gradient_radial_class_init(GraphicsGradientRadialClass *klass);
static void graphics_gradient_radial_init(GraphicsGradientRadial *gobject);

G_DEFINE_TYPE (GraphicsGradientRadial, graphics_gradient_radial, GRAPHICS_TYPE_GRADIENT)


static void
graphics_gradient_radial_to_context(GraphicsGradient *self, cairo_t *cr, gboolean preserve)
{
    GraphicsGradientRadial *radial   = GRAPHICS_GRADIENT_RADIAL(self);
    GraphicsGradient       *gradient = GRAPHICS_GRADIENT(radial);

    if (!gradient->pattern) {
        gradient->pattern = cairo_pattern_create_radial (radial->cx0, radial->cy0, radial->radius0,
                                                         radial->cx1, radial->cy1, radial->radius1);
        graphics_gradient_stops_to_pattern(gradient->stops, gradient->pattern);
    }
    cairo_set_source (cr, gradient->pattern);
}

static void
graphics_gradient_radial_class_init(GraphicsGradientRadialClass *klass)
{
	GObjectClass *gobject_class;
    GraphicsGradientClass *gradient_class;

    gobject_class = (GObjectClass *) klass;
    gradient_class = (GraphicsGradientClass *) klass;

    gradient_class->to_context = graphics_gradient_radial_to_context;

	graphics_gradient_radial_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_gradient_radial_init (GraphicsGradientRadial *object)
{
    object->cx0     = 0.0;
    object->cy0     = 0.0;
    object->radius0 = 0.0;
    object->cx1     = 0.0;
    object->cy1     = 0.0;
    object->radius1 = 0.0;
}

GraphicsGradientRadial *
graphics_gradient_radial_new ()
{
    GraphicsGradientRadial* gradient = g_object_new (graphics_gradient_radial_get_type (), NULL);

    return gradient;
}
