/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-stroke.h
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


#ifndef __GRAPHICS_STROKE_H__
#define __GRAPHICS_STROKE_H__


G_BEGIN_DECLS

#define GRAPHICS_TYPE_STROKE            (graphics_stroke_get_type())
#define GRAPHICS_STROKE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_STROKE, GraphicsStroke))
#define GRAPHICS_STROKE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_STROKE, GraphicsStrokeClass))
#define GRAPHICS_IS_STROKE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_STROKE))
#define GRAPHICS_IS_STROKE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_STROKE))
#define GRAPHICS_STROKE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_STROKE, GraphicsStrokeClass))


typedef struct _GraphicsStrokeClass GraphicsStrokeClass;

struct _GraphicsStrokeClass {
	GObjectClass parent_class;
};

GType graphics_stroke_get_type();


G_END_DECLS

#endif /* __GRAPHICS_STROKE_H__ */

