
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
