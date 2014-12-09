/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient-linear.c
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
#include "graphics-gradient-linear.h"


static void graphics_gradient_linear_class_init(GraphicsGradientLinearClass *klass);
static void graphics_gradient_linear_init(GraphicsGradientLinear *gobject);

G_DEFINE_TYPE (GraphicsGradientLinear, graphics_gradient_linear, GRAPHICS_TYPE_GRADIENT)

static void
graphics_gradient_linear_to_context(GraphicsGradient *self, cairo_t *cr, gboolean preserve)
{
    GraphicsGradientLinear *linear   = GRAPHICS_GRADIENT_LINEAR(self);
    GraphicsGradient       *gradient = GRAPHICS_GRADIENT(linear);

    if (!gradient->pattern) {
        gradient->pattern = cairo_pattern_create_linear (linear->x0, linear->y0,
                                                       linear->x1, linear->y1);

        graphics_gradient_stops_to_pattern(gradient->stops, gradient->pattern);
        cairo_pattern_set_extend(gradient->pattern, gradient->extend);
    }

    cairo_set_source (cr, gradient->pattern);
}

static void
graphics_gradient_linear_class_init(GraphicsGradientLinearClass *klass)
{
    GObjectClass *gobject_class;
    GraphicsGradientClass *gradient_class;

    gobject_class  = (GObjectClass *) klass;
    gradient_class = (GraphicsGradientClass *) klass;

    gradient_class->to_context = graphics_gradient_linear_to_context;

	graphics_gradient_linear_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_gradient_linear_init (GraphicsGradientLinear *object)
{
    object->x0 = 0.0;
    object->y0 = 0.0;
    object->x1 = 0.0;
    object->y1 = 0.0;

    object->relative = FALSE;
}

GraphicsGradientLinear *
graphics_gradient_linear_new ()
{
    GraphicsGradientLinear *linear = g_object_new (graphics_gradient_linear_get_type (), NULL);

    return linear;
}
