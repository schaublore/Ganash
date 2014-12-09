/*
 * graphics-image.h
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


#ifndef __GRAPHICS_IMAGE_H__
#define __GRAPHICS_IMAGE_H__



G_BEGIN_DECLS

#define GRAPHICS_TYPE_IMAGE            (graphics_image_get_type())
#define GRAPHICS_IMAGE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_IMAGE, GraphicsImage))
#define GRAPHICS_IMAGE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_IMAGE, GraphicsImageClass))
#define GRAPHICS_IS_IMAGE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_IMAGE))
#define GRAPHICS_IS_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_IMAGE))
#define GRAPHICS_IMAGE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_IMAGE, GraphicsImageClass))

typedef struct _GraphicsImageClass GraphicsImageClass;

struct _GraphicsImageClass {
	GObjectClass parent_class;
};

GType graphics_image_get_type();


G_END_DECLS

#endif /* __GRAPHICS_IMAGE_H__ */

