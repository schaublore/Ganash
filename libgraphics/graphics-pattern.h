/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-pattern.h
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


#ifndef __GRAPHICS_PATTERN_H__
#define __GRAPHICS_PATTERN_H__



G_BEGIN_DECLS

#define GRAPHICS_TYPE_PATTERN            (graphics_pattern_get_type())
#define GRAPHICS_PATTERN(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRAPHICS_TYPE_PATTERN, GraphicsPattern))
#define GRAPHICS_PATTERN_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GRAPHICS_TYPE_PATTERN, GraphicsPatternClass))
#define GRAPHICS_IS_PATTERN(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRAPHICS_TYPE_PATTERN))
#define GRAPHICS_IS_PATTERN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRAPHICS_TYPE_PATTERN))
#define GRAPHICS_PATTERN_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GRAPHICS_TYPE_PATTERN, GraphicsPatternClass))

typedef struct _GraphicsPatternClass GraphicsPatternClass;

struct _GraphicsPatternClass {
	GObjectClass parent_class;
};

GType graphics_pattern_get_type();

G_END_DECLS

#endif /* __GRAPHICS_PATTERN_H__ */

