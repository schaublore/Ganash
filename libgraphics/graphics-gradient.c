/*
 * graphics-gradient.c
 * Copyright (C) 2013 MY_NAME MY.NAME@CONTACT
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
#include "graphics-gradient.h"


static void graphics_gradient_class_init(GraphicsGradientClass *klass);
static void graphics_gradient_init(GraphicsGradient *gobject);
static void graphics_gradient_painter_interface_init (GraphicsPainterIfaceInterface *iface);

G_DEFINE_TYPE_WITH_CODE (GraphicsGradient, graphics_gradient, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GRAPHICS_TYPE_PAINTER_IFACE,
                                                graphics_gradient_painter_interface_init))

/* GObject interface */
/* ************************************************************************* */
static void
graphics_gradient_finalize (GObject *gobject)
{
    GraphicsGradient *self = GRAPHICS_GRADIENT (gobject);

    if (self->stops)
        g_list_free_full(self->stops, g_object_unref);
    if (self->pattern)
        cairo_pattern_destroy(self->pattern);

    /* Always chain up to the parent class; as with dispose(), finalize()
     * is guaranteed to exist on the parent's class virtual function table
     */
    G_OBJECT_CLASS (graphics_gradient_parent_class)->finalize (gobject);
}

static void
graphics_gradient_class_init(GraphicsGradientClass *klass)
{
	GObjectClass *gobject_class;

    gobject_class = (GObjectClass *) klass;
    gobject_class->finalize = graphics_gradient_finalize;

	graphics_gradient_parent_class = g_type_class_peek_parent (klass);
}

/* painter interface */
/* ************************************************************************* */
static void
graphics_gradient_painter_interface_init (GraphicsPainterIfaceInterface *iface)
{
    iface->to_context = (GraphicsPainterToContext) graphics_gradient_to_context;
}

static void
graphics_gradient_init (GraphicsGradient *object)
{
    object->stops   = NULL;
    object->pattern = NULL;
    object->extend  = CAIRO_EXTEND_PAD;
}

/* public function */
/* ************************************************************************* */
void
graphics_gradient_add_stop(GraphicsGradient *gradient, gdouble offset,
     gdouble red, gdouble green, gdouble blue, gdouble alpha)
{
    GraphicsGradientStop *stop = graphics_gradient_stop_new_init(offset, red, green, blue, alpha);
    gradient->stops = g_list_append(gradient->stops, stop);
}

void
graphics_gradient_to_context(GraphicsGradient *gradient, cairo_t *cr, gboolean preserve)
{
    /*linear/radial*/
    GRAPHICS_GRADIENT_GET_CLASS(gradient)->to_context(gradient, cr, preserve);
}
