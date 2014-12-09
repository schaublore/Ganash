/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-fill.h
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


#ifndef __GRAPHICS_FILL_H__
#define __GRAPHICS_FILL_H__


G_BEGIN_DECLS

#define GRAPHICS_TYPE_FILL            (graphics_fill_get_type())
#define GRAPHICS_FILL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_FILL, GraphicsFill))
#define GRAPHICS_FILL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_FILL, GraphicsFillClass))
#define GRAPHICS_IS_FILL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_FILL))
#define GRAPHICS_IS_FILL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_FILL))
#define GRAPHICS_FILL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_FILL, GraphicsFillClass))

typedef struct _GraphicsFillClass GraphicsFillClass;

struct _GraphicsFillClass {
	GObjectClass parent_class;
};

GType graphics_fill_get_type();

G_END_DECLS

#endif /* __GRAPHICS_FILL_H__ */

