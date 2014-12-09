/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-painter.c
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
#include "graphics-painter.h"


static void graphics_painter_class_init(GraphicsPainterClass *klass);
static void graphics_painter_init(GraphicsPainter *gobject);

G_DEFINE_TYPE (GraphicsPainter, graphics_painter, G_TYPE_OBJECT)

static void
graphics_painter_class_init(GraphicsPainterClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

	graphics_painter_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_painter_init (GraphicsPainter *object)
{
    object->type = GRAPHICS_PAINTER_UNKNOW_TYPE;
    object->data.solid    = NULL;
    object->data.gradient = NULL;
    object->data.image    = NULL;
    object->data.pattern  = NULL;
}

GraphicsPainter *
graphics_painter_new ()
{
    GraphicsPainter *painter = g_object_new (graphics_painter_get_type(), NULL);

    return painter;
}

void
graphics_painter_set_gradient(GraphicsPainter *painter, GraphicsGradient *gradient)
{
    painter->type = GRAPHICS_PAINTER_GRADIENT_TYPE;
    painter->data.gradient = gradient;
}

void
graphics_painter_set_solid(GraphicsPainter *painter, GraphicsSolid *solid)
{
    painter->type = GRAPHICS_PAINTER_SOLID_TYPE;
    painter->data.solid = solid;
}

void
graphics_painter_set_image(GraphicsPainter *painter, GraphicsImage *image)
{
    painter->type = GRAPHICS_PAINTER_IMAGE_TYPE;
    painter->data.image = image;
}
void
graphics_painter_set_pattern (GraphicsPainter *painter, GraphicsPattern* pattern)
{
    painter->type = GRAPHICS_PAINTER_PATTERN_TYPE;
    painter->data.pattern = pattern;
}

void
graphics_painter_to_context (GraphicsPainter *painter, cairo_t* cr, gboolean preserve)
{
    switch(painter->type) {
        case GRAPHICS_PAINTER_SOLID_TYPE:
            graphics_solid_to_context(painter->data.solid, cr);
            break;
        case GRAPHICS_PAINTER_GRADIENT_TYPE:
            graphics_gradient_to_context(painter->data.gradient, cr, preserve);
            break;
        case GRAPHICS_PAINTER_IMAGE_TYPE:
            graphics_image_to_context(painter->data.image, cr, preserve);
            break;
        case GRAPHICS_PAINTER_PATTERN_TYPE:
            graphics_pattern_to_context(painter->data.pattern, cr, preserve);
            break;
        case GRAPHICS_PAINTER_UNKNOW_TYPE:
        default:
            painter->type = GRAPHICS_PAINTER_UNKNOW_TYPE;
            break;
    }
}
