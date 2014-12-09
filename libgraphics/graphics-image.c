/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-image.c
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
#include "graphics-image.h"


static void graphics_image_class_init(GraphicsImageClass *klass);
static void graphics_image_init(GraphicsImage *gobject);
static void graphics_image_painter_interface_init (GraphicsPainterIfaceInterface *iface);

G_DEFINE_TYPE_WITH_CODE (GraphicsImage, graphics_image, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GRAPHICS_TYPE_PAINTER_IFACE,
                                                graphics_image_painter_interface_init))

static void
graphics_image_class_init(GraphicsImageClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

	graphics_image_parent_class = g_type_class_peek_parent (klass);
}

/* painter interface */
/* ************************************************************************* */
static void
graphics_image_painter_interface_init (GraphicsPainterIfaceInterface *iface)
{
    iface->to_context = (GraphicsPainterToContext) graphics_image_to_context;
}

static void
graphics_image_init (GraphicsImage *object)
{
    object->x = 0.0;
    object->y = 0.0;

    object->scale   = FALSE;
    object->scale_x = 1.0;
    object->scale_y = 1.0;

    object->resize = FALSE;
    object->width  = -1;
    object->height = -1;

    object->surface = NULL;
    object->w = -1;
    object->h = -1;

    object->clip    = NULL;
    object->pattern = NULL;
    object->uri     = NULL;

}

/* painter interface */
/* ************************************************************************* */
void graphics_image_to_context(GraphicsImage *image, cairo_t* cr, gboolean preserve)
{
    cairo_scale (cr, image->scale_x, image->scale_y);
    cairo_translate (cr, image->x/image->scale_x, image->y/image->scale_y);
    //rotate/matrix
    cairo_set_source_surface (cr, image->surface, 0, 0);
}

void graphics_image_surface(GraphicsImage *image, cairo_surface_t* surface)
{
    surface = image->surface;
}

/*cairo_surface_t* graphics_image_get_surface(GraphicsImage *image)
{
    cairo_surface_t* surface = g_new(cairo_surface_t, 1);
    memcpy(surface, image->surface, sizeof(cairo_surface_t));
    return surface;
}*/

GraphicsImage *
graphics_image_new ()
{
    GraphicsImage *image = g_object_new (graphics_image_get_type (), NULL);
    return image;
}

GraphicsImage *
graphics_image_new_from_uri (gchar *uri)
{
    GraphicsImage *image = g_object_new (graphics_image_get_type (), NULL);
    if(uri)
        graphics_image_set_uri(image, uri);

    return image;
}

void
graphics_image_set_uri(GraphicsImage *image, gchar* uri)
{
    image->surface = cairo_image_surface_create_from_png (uri);
    image->w = cairo_image_surface_get_width (image->surface);
    image->h = cairo_image_surface_get_height (image->surface);
    if (image->resize && image->width>0 && image->height>0) {
        image->scale_x = image->width / image->w;
        image->scale_y = image->height / image->h;
    }
}

void
graphics_image_resize(GraphicsImage *image, gint width, gint height)
{
    if (!image->surface)
        return;
    if (width<1)
        width = 0;
    image->scale_x  = (gdouble) width / (gdouble) image->w;

    if (height<1)
        height = 0;
    image->scale_y = (gdouble) height / (gdouble) image->h;

    image->scale  = FALSE;
    image->resize = TRUE;
}

void
graphics_image_scale(GraphicsImage *image, gdouble scale_x, gdouble scale_y)
{
    if (scale_x<0.0)
        scale_x = 0.0;
    if (scale_x>1.0)
        scale_x = 1.0;
    image->scale_x = scale_x;

    if (scale_y<0.0)
        scale_y = 0.0;
    if (scale_y>1.0)
        scale_y = 1.0;
    image->scale_y = scale_y;

    image->scale  = TRUE;
    image->resize = FALSE;
}
