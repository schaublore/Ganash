/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-painter-iface.c
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
#include "graphics-painter-iface.h"



G_DEFINE_INTERFACE(GraphicsPainterIface, graphics_painter_iface, 0)

static void
graphics_painter_default_to_context(GraphicsPainterIface *self, cairo_t *cr, gboolean preserve)
{
    g_message("Not implemented");
}

static void
graphics_painter_iface_default_init(GraphicsPainterIfaceInterface *iface)
{
    /* Add properties and signals to the interface here */
    iface->to_context = graphics_painter_default_to_context;
}

void
graphics_painter_iface_to_context(GraphicsPainterIface *self, cairo_t *cr, gboolean preserve) {
    g_return_if_fail(GRAPHICS_IS_PAINTER_IFACE(self));

    GRAPHICS_PAINTER_IFACE_GET_INTERFACE(self)->to_context(self, cr, preserve);
}
