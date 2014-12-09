/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * graphics-gradient-stops.h
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


#ifndef __GRAPHICS_GRADIENT_STOPS_H__
#define __GRAPHICS_GRADIENT_STOPS_H__


G_BEGIN_DECLS

void graphics_gradient_stops_to_pattern(GList *stops, cairo_pattern_t* pattern);

G_END_DECLS

#endif /* __GRAPHICS_GRADIENT_STOPS_H__ */

