/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics.h
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


#ifndef __GRAPHICS_GRAPHICS_H__
#define __GRAPHICS_GRAPHICS_H__

#include <glib-object.h>
#include <cairo/cairo.h>


G_BEGIN_DECLS


typedef struct  _GraphicsColor              GraphicsColor;
typedef struct  _GraphicsGradientStop       GraphicsGradientStop;
typedef struct  _GraphicsGradientRadial     GraphicsGradientRadial;
typedef struct  _GraphicsGradientLinear     GraphicsGradientLinear;
typedef enum    _GraphicsGradientType       GraphicsGradientType;
typedef struct  _GraphicsGradient           GraphicsGradient;
typedef struct  _GraphicsImage              GraphicsImage;
typedef struct  _GraphicsPattern            GraphicsPattern;
typedef struct  _GraphicsPainter            GraphicsPainter;
typedef struct  _GraphicsSolid              GraphicsSolid;
typedef struct  _GraphicsFill               GraphicsFill;
typedef struct  _GraphicsStroke             GraphicsStroke;
typedef struct  _GraphicsPath               GraphicsPath;


typedef union   _GraphicsPainterData        GraphicsPainterData;
typedef enum    _GraphicsPainterType        GraphicsPainterType;

typedef enum   _GraphicsCapType         GraphicsCapType;
typedef enum   _GraphicsJoinType        GraphicsJoinType;
//typedef enum   _GraphicsSourceType      GraphicsSourceType;
typedef enum   _GraphicsExtendType      GraphicsExtendType;
typedef enum   _GraphicsFillRuleType    GraphicsFillRuleType;



/* enums */
/* ************************************************************************* */
enum _GraphicsGradientType {
    GRAPHICS_GRADIENT_UNKNOW_TYPE,
    GRAPHICS_GRADIENT_LINEAR_TYPE,
    GRAPHICS_GRADIENT_RADIAL_TYPE
};

enum _GraphicsStatusType {
    GRAPHICS_STATUS_UNKNOW,
    GRAPHICS_STATUS_BUFFERED,
    GRAPHICS_STATUS_MODIFIED
};

enum _GraphicsPatternType {
    GRAPHICS_PATTERN_LINEAR  = 16,
    GRAPHICS_PATTERN_RADIAL  = 32,
    GRAPHICS_PATTERN_SURFACE = 64
};

enum _GraphicsPainterType
{
    GRAPHICS_PAINTER_UNKNOW_TYPE   = 0,
    GRAPHICS_PAINTER_SOLID_TYPE    = 2,
    GRAPHICS_PAINTER_GRADIENT_TYPE = 4,
    GRAPHICS_PAINTER_IMAGE_TYPE    = 8,
    GRAPHICS_PAINTER_PATTERN_TYPE  = 16
};

enum _GraphicsSurfaceType {
    GRAPHICS_SURFACE_PIXMAP,
    GRAPHICS_SURFACE_RENDERER
};

enum _GraphicsSourceType {
    GRAPHICS_SOURCE_RGB,
    GRAPHICS_SOURCE_RGBA,
    GRAPHICS_SOURCE_PIXMAP,
    GRAPHICS_SOURCE_PATTERN
};

enum _GraphicsCapType {
    GRAPHICS_CAP_BUTT   = CAIRO_LINE_CAP_BUTT,
    GRAPHICS_CAP_ROUND  = CAIRO_LINE_CAP_ROUND,
    GRAPHICS_CAP_SQUARE = CAIRO_LINE_CAP_SQUARE
};

enum _GraphicsJoinType {
    GRAPHICS_JOIN_MITER = CAIRO_LINE_JOIN_MITER,
    GRAPHICS_JOIN_ROUND = CAIRO_LINE_JOIN_ROUND,
    GRAPHICS_JOIN_BEVEL = CAIRO_LINE_JOIN_BEVEL
};

enum _GraphicsExtendType {
    GRAPHICS_EXTEND_NONE    = CAIRO_EXTEND_NONE,
    GRAPHICS_EXTEND_REPEAT  = CAIRO_EXTEND_REPEAT,
    GRAPHICS_EXTEND_REFLECT = CAIRO_EXTEND_REFLECT,
    GRAPHICS_EXTEND_PAD     = CAIRO_EXTEND_PAD
};

enum _GraphicsFillRuleType {
    GRAPHICS_FILL_WINDING_TYPE  = CAIRO_FILL_RULE_WINDING,
    GRAPHICS_FILL_EVEN_ODD_TYPE = CAIRO_FILL_RULE_EVEN_ODD
};


/* GraphicsColor */
/* ************************************************************************* */
struct _GraphicsColor {
    GObject parent_instance;
    double red;
    double green;
    double blue;
    double alpha;
};
GraphicsColor *graphics_color_new();
//GraphicsColor *graphics_color_free();
GraphicsColor *graphics_color_new_gray(gdouble value);
GraphicsColor *graphics_color_new_rgb(gdouble red, gdouble green, gdouble blue);
GraphicsColor *graphics_color_new_rgba(gdouble red, gdouble green, gdouble blue, gdouble alpha);


/* GraphicsSolid */
/* ************************************************************************* */
struct _GraphicsSolid {
    GObject parent_instance;
    GraphicsColor *color;
};
GraphicsSolid          *graphics_solid_new(void);
//                        graphics_solid_free(GraphicsSolid *solid);
GraphicsSolid          *graphics_solid_new_init(gdouble red, gdouble green, gdouble blue, gdouble alpha);
void                    graphics_solid_to_context(GraphicsSolid *solid, cairo_t *cr);


/* GraphicsGradient */
/* ************************************************************************* */
struct _GraphicsGradient {
    GObject parent_instance;

    /* private */
    GList* stops;
    cairo_pattern_t* pattern;
    cairo_extend_t   extend;
};
void graphics_gradient_add_stop(GraphicsGradient *gradient, gdouble offset, gdouble red, gdouble green, gdouble blue, gdouble alpha);
void graphics_gradient_to_context(GraphicsGradient *gradient, cairo_t *cr, gboolean preserve);

/* GraphicsImage */
/* ************************************************************************* */
struct _GraphicsImage {
    GObject parent_instance;

    gchar* uri;
    cairo_surface_t *surface;
    cairo_pattern_t *pattern;
    cairo_path_t    *clip;
    cairo_matrix_t  *matrix;

    /*position*/
    gdouble x;
    gdouble y;

    /*scale*/
    gboolean scale;
    gdouble scale_x;
    gdouble scale_y;

    /*size*/
    gboolean resize;
    gint width;
    gint height;

    gint w;
    gint h;

};
GraphicsImage *graphics_image_new(void);
GraphicsImage *graphics_image_new_from_uri(gchar *uri);
void graphics_image_set_uri(GraphicsImage *image, gchar* uri);
void graphics_image_resize(GraphicsImage *image, gint width, gint height);
void graphics_image_scale(GraphicsImage *image, gdouble scale_x, gdouble scale_y);
void graphics_image_to_context(GraphicsImage *image, cairo_t* cr, gboolean preserve);
//void graphics_image_to_surface(GraphicsImage *image, cairo_surface_t* surface);// create surface
//cairo_surface_t* void graphics_image_get_surface(GraphicsImage *image);// make copy
//void graphics_image_surface(GraphicsImage *image, cairo_surface_t* surface);// get ref surface


/* GraphicsPattern */
/* ************************************************************************* */
struct _GraphicsPattern {
    GObject parent_instance;

    cairo_pattern_t *pattern;
    /*cairo_path_t    *clip;*/
    cairo_extend_t   extend;

    cairo_matrix_t   matrix;
    gboolean         use_matrix;
};
GraphicsPattern *graphics_pattern_new();
void graphics_pattern_set_surface(GraphicsPattern *source, cairo_surface_t *surface);
void graphics_pattern_set_matrix(GraphicsPattern *source, cairo_matrix_t *matrix);
void graphics_pattern_set_extend(GraphicsPattern *source, cairo_extend_t extend);
void graphics_pattern_to_context(GraphicsPattern *source, cairo_t* cr, gboolean preserve);
void graphics_image_surface(GraphicsImage *image, cairo_surface_t* surface);

/* GraphicsGradientRadial */
/* ************************************************************************* */
struct _GraphicsGradientRadial {
    GraphicsGradient parent_instance;
    double cx0;
    double cy0;
    double radius0;
    double cx1;
    double cy1;
    double radius1;
};
GraphicsGradientRadial *graphics_gradient_radial_new();
//                        graphics_gradient_radial_free(GraphicsGradientRadial *radial);


/* GraphicsGradientLinear */
/* ************************************************************************* */
struct _GraphicsGradientLinear {
    GraphicsGradient parent_instance;
    double x0;
    double y0;
    double x1;
    double y1;
    gboolean relative;
};
GraphicsGradientLinear *graphics_gradient_linear_new();
//                        graphics_gradient_linear_free(GraphicsGradientLinear *linear);


/* GraphicsGradientStop */
/* ************************************************************************* */
struct _GraphicsGradientStop {
    GObject parent_instance;
    GraphicsColor *color;
    gdouble        offset;
};
GraphicsGradientStop *graphics_gradient_stop_new();
GraphicsGradientStop *graphics_gradient_stop_new_init (gdouble offset, gdouble red, gdouble green, gdouble blue, gdouble alpha);

/* GraphicsPainter */
/* ************************************************************************* */
union _GraphicsPainterData {
    GraphicsSolid       *solid;
    GraphicsGradient    *gradient;
    GraphicsImage       *image;
    GraphicsPattern     *pattern;
};
struct _GraphicsPainter {
    GObject parent_instance;

    GraphicsPainterType type;
    GraphicsPainterData data;
};
GraphicsPainter         *graphics_painter_new();
//                        graphics_painter_free(GraphicsPainter *painter);
void                     graphics_painter_to_context (GraphicsPainter *painter, cairo_t* cr, gboolean preserve);
void                     graphics_painter_set_gradient(GraphicsPainter *painter, GraphicsGradient *gradient);
void                     graphics_painter_set_solid(GraphicsPainter *painter, GraphicsSolid *solid);
void                     graphics_painter_set_image(GraphicsPainter *painter, GraphicsImage *image);


/* GraphicsFill */
/* ************************************************************************* */
struct _GraphicsFill {
    GObject parent_instance;
    GraphicsPainter* painter;
    GraphicsFillRuleType* rule;
};
GraphicsFill            *graphics_fill_new(void);
//                        graphics_fill_free(GraphicsFill *fill);
void                     graphics_fill_set_painter(GraphicsFill *fill, GraphicsPainter *painter);
void                     graphics_fill_to_context(GraphicsFill *fill, cairo_t *cr, gboolean preserve);


/* GraphicsStroke */
/* ************************************************************************* */
struct _GraphicsStroke {
    GObject parent_instance;
    GraphicsPainter* painter;
    GraphicsCapType  cap;
    GraphicsJoinType join;
    double           width;
    double           miter_limit;
};
GraphicsStroke          *graphics_stroke_new(void);
//                        graphics_stroke_free(GraphicsStroke *stroke);
void                     graphics_stroke_set_painter(GraphicsStroke *stroke, GraphicsPainter* painter);
void                     graphics_stroke_to_context(GraphicsStroke *stroke, cairo_t *cr, gboolean preserve);

/* GraphicsPaint */
/* ************************************************************************* */

/* GraphicsPath */
/* ************************************************************************* */
struct _GraphicsPath {
    GObject parent_instance;

    cairo_path_t *path;
};
GraphicsPath            *graphics_path_new();
void                     graphics_path_to_context(GraphicsPath *path, cairo_t *cr, gboolean preserve);
void                     graphics_path_bounding_box(GraphicsPath *path, cairo_t *cr, double *x1, double *y1, double *x2, double *y2);
void                     graphics_path_set(GraphicsPath *path, cairo_path_t *c_path);
gboolean                 graphics_path_is_empty(GraphicsPath *path);

G_END_DECLS

#endif /* __GRAPHICS_GRAPHICS_H__ */
