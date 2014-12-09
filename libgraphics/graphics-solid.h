/*
 * graphics-solid.h
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


#ifndef __GRAPHICS_SOLID_H__
#define __GRAPHICS_SOLID_H__


G_BEGIN_DECLS

#define GRAPHICS_TYPE_SOLID            (graphics_solid_get_type())
#define GRAPHICS_SOLID(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_SOLID, GraphicsSolid))
#define GRAPHICS_SOLID_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_SOLID, GraphicsSolidClass))
#define GRAPHICS_IS_SOLID(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_SOLID))
#define GRAPHICS_IS_SOLID_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_SOLID))
#define GRAPHICS_SOLID_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_SOLID, GraphicsSolidClass))

typedef struct _GraphicsSolidClass GraphicsSolidClass;

struct _GraphicsSolidClass {
	GObjectClass parent_class;
};

GType graphics_solid_get_type();


G_END_DECLS

#endif /* __GRAPHICS_SOLID_H__ */
