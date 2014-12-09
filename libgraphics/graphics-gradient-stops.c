/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient-stops.c
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
#include "graphics-gradient-stops.h"


void
graphics_gradient_stops_to_pattern(GList *stops, cairo_pattern_t* pattern)
{
    GList* l;
    for (l=g_list_first(stops); l; l=l->next) {
        GraphicsGradientStop* stop = l->data;
        GraphicsColor *color = stop->color;
        if (color->alpha<1.0)
        {
            cairo_pattern_add_color_stop_rgba (pattern, stop->offset,
                                               color->red,
                                               color->green,
                                               color->blue,
                                               color->alpha);
        } else {
            cairo_pattern_add_color_stop_rgb (pattern, stop->offset,
                                              color->red,
                                              color->green,
                                              color->blue);
        }
    }
}
