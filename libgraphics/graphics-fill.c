/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-fill.c
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
#include "graphics-painter.h"
#include "graphics-fill.h"



static void graphics_fill_class_init(GraphicsFillClass *klass);
static void graphics_fill_init(GraphicsFill *gobject);

G_DEFINE_TYPE (GraphicsFill, graphics_fill, G_TYPE_OBJECT)

static void
graphics_fill_finalize (GObject *gobject)
{
    GraphicsFill *self = GRAPHICS_FILL (gobject);

    if (self->painter)
        g_object_unref (self->painter);

    /* Always chain up to the parent class; as with dispose(), finalize()
     * is guaranteed to exist on the parent's class virtual function table
     */
    G_OBJECT_CLASS (graphics_fill_parent_class)->finalize (gobject);
}

static void
graphics_fill_class_init(GraphicsFillClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;
    gobject_class->finalize = graphics_fill_finalize;

	graphics_fill_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_fill_init (GraphicsFill *object)
{
    object->painter = NULL;
    object->rule    = GRAPHICS_FILL_WINDING_TYPE;
}

GraphicsFill *
graphics_fill_new (void)
{
	return g_object_new (graphics_fill_get_type (),
	                     NULL);
}

void graphics_fill_to_context(GraphicsFill *fill, cairo_t *cr, gboolean preserve)
{
    g_return_if_fail(GRAPHICS_IS_PAINTER(fill->painter));

    cairo_set_fill_rule(cr, (cairo_fill_rule_t) fill->rule);

    graphics_painter_to_context(fill->painter, cr, preserve);
    if (preserve) {
        cairo_fill_preserve(cr);
    } else {
        cairo_fill(cr);
    }

}
