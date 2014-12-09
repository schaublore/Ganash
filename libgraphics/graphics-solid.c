/*
 * graphics-solid.c
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
#include "graphics-solid.h"


static void graphics_solid_class_init(GraphicsSolidClass *klass);
static void graphics_solid_init(GraphicsSolid *gobject);

G_DEFINE_TYPE (GraphicsSolid, graphics_solid, G_TYPE_OBJECT)

static void
graphics_solid_finalize(GObject *gobject)
{
    GraphicsSolid *solid = GRAPHICS_SOLID(gobject);
    if (solid->color)
        g_object_unref(solid->color);

    G_OBJECT_CLASS (graphics_solid_parent_class)->finalize (gobject);
}

static void
graphics_solid_class_init(GraphicsSolidClass *klass)
{
	GObjectClass *gobject_class;

    gobject_class = (GObjectClass *) klass;
    gobject_class->finalize = graphics_solid_finalize;

	graphics_solid_parent_class = g_type_class_peek_parent (klass);
}

static void
graphics_solid_init (GraphicsSolid *object)
{
    object->color   = NULL;
}

GraphicsSolid *
graphics_solid_new (void)
{
    return g_object_new (graphics_solid_get_type (),
                         NULL);
}

GraphicsSolid *
graphics_solid_new_init (gdouble red, gdouble green, gdouble blue, gdouble alpha)
{
    GraphicsSolid *solid = g_object_new (graphics_solid_get_type (), NULL);
    solid->color = graphics_color_new_rgba(red, green, blue, alpha);

    return solid;
}

void graphics_solid_to_context(GraphicsSolid *solid, cairo_t *cr)
{
    GraphicsColor *color;

    g_return_if_fail(GRAPHICS_IS_SOLID(solid));
    if (!solid->color)
        return;
    color = solid->color;
    if (color->alpha<1.0) {
        cairo_set_source_rgba(cr,
                              color->red,
                              color->green,
                              color->blue,
                              color->alpha);
    } else {
        cairo_set_source_rgb(cr,
                              color->red,
                              color->green,
                              color->blue);
    }

}
