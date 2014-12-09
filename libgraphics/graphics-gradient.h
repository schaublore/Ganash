/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient.h
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


#ifndef __GRAPHICS_GRADIENT_H__
#define __GRAPHICS_GRADIENT_H__


G_BEGIN_DECLS

#define GRAPHICS_TYPE_GRADIENT            (graphics_gradient_get_type())
#define GRAPHICS_GRADIENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_GRADIENT, GraphicsGradient))
#define GRAPHICS_GRADIENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_GRADIENT, GraphicsGradientClass))
#define GRAPHICS_IS_GRADIENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_GRADIENT))
#define GRAPHICS_IS_GRADIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_GRADIENT))
#define GRAPHICS_GRADIENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_GRADIENT, GraphicsGradientClass))


typedef struct _GraphicsGradientClass GraphicsGradientClass;

struct _GraphicsGradientClass {
	GObjectClass parent_class;

    void (*to_context) (GraphicsGradient *gradient, cairo_t *cr, gboolean preserve);
};

GType graphics_gradient_get_type();



G_END_DECLS

#endif /* __GRAPHICS_GRADIENT_H__ */
