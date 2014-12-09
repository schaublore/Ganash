/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-painter-iface.h
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


#ifndef __GRAPHICS_PAINTER_IFACE_H__
#define __GRAPHICS_PAINTER_IFACE_H__



G_BEGIN_DECLS

#define GRAPHICS_TYPE_PAINTER_IFACE                 (graphics_painter_iface_get_type ())
#define GRAPHICS_PAINTER_IFACE(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_PAINTER_IFACE, GraphicsPainterIface))
#define GRAPHICS_IS_PAINTER_IFACE(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_PAINTER_IFACE))
#define GRAPHICS_PAINTER_IFACE_GET_INTERFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), GRAPHICS_TYPE_PAINTER_IFACE, GraphicsPainterIfaceInterface))


typedef struct _GraphicsPainterIface  GraphicsPainterIface; /* dummy object */
typedef struct _GraphicsPainterIfaceInterface  GraphicsPainterIfaceInterface;

typedef void (*GraphicsPainterToContext) ( GraphicsPainterIface *self, cairo_t *cr, gboolean preserve);

struct _GraphicsPainterIfaceInterface
{
	GTypeInterface parent_iface;
    void (*to_context) ( GraphicsPainterIface *self, cairo_t *cr, gboolean preserve);
};

GType  graphics_painter_iface_get_type (void);
void graphics_painter_iface_to_context (GraphicsPainterIface *self, cairo_t *cr, gboolean preserve);

G_END_DECLS

#endif /* __GRAPHICS_PAINTER_IFACE_H__ */

