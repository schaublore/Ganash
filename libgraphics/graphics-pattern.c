/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-pattern.c
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
#include "graphics-painter-iface.h"
#include "graphics-pattern.h"

#include <string.h>

static void graphics_pattern_class_init(GraphicsPatternClass *klass);
static void graphics_pattern_init(GraphicsPattern *gobject);
static void graphics_pattern_painter_interface_init (GraphicsPainterIfaceInterface *iface);

G_DEFINE_TYPE_WITH_CODE (GraphicsPattern, graphics_pattern, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GRAPHICS_TYPE_PAINTER_IFACE,
                                                graphics_pattern_painter_interface_init))

static void
graphics_pattern_finalize (GObject *gobject)
{
    GraphicsPattern *self = GRAPHICS_PATTERN (gobject);

    if (self->pattern)
        g_free (self->pattern);

    /* Always chain up to the parent class; as with dispose(), finalize()
     * is guaranteed to exist on the parent's class virtual function table
     */
    G_OBJECT_CLASS (graphics_pattern_parent_class)->finalize (gobject);
}

static void
graphics_pattern_init (GraphicsPattern *object)
{
    object->pattern    = NULL;
    object->extend     = CAIRO_EXTEND_NONE;
    object->use_matrix = FALSE;
}

static void
graphics_pattern_class_init(GraphicsPatternClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

    gobject_class->finalize = graphics_pattern_finalize;

	graphics_pattern_parent_class = g_type_class_peek_parent (klass);
}

/* painter interface */
/* ************************************************************************* */
void
graphics_pattern_to_context(GraphicsPattern *source, cairo_t* cr, gboolean preserve)
{
    if (!source->pattern) {
        g_error("No pattern set\n");
        return;
    }

    cairo_pattern_set_extend (source->pattern, source->extend);

    if (source->use_matrix) {
        cairo_pattern_set_matrix (source->pattern, &source->matrix);
    }

    cairo_set_source (cr, source->pattern);
}

/* painter interface */
/* ************************************************************************* */
static void
graphics_pattern_painter_interface_init (GraphicsPainterIfaceInterface *iface)
{
    iface->to_context = (GraphicsPainterToContext) graphics_pattern_to_context;
}

GraphicsPattern *
graphics_pattern_new (void)
{
	return g_object_new (graphics_pattern_get_type (),
	                     NULL);
}

void graphics_pattern_set_surface(GraphicsPattern *source, cairo_surface_t *surface)
{
    g_return_if_fail(surface);

    source->pattern = cairo_pattern_create_for_surface (surface);
}

void graphics_pattern_set_matrix(GraphicsPattern *source, cairo_matrix_t *matrix)
{
    source->use_matrix = TRUE;
    memcpy(&source->matrix, matrix, sizeof(cairo_matrix_t));
}

void graphics_pattern_set_extend(GraphicsPattern *source, cairo_extend_t extend)
{
    source->extend = extend;
}
