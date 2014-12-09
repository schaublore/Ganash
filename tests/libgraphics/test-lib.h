/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * test-lib.h
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


#ifndef __TEST_LIB_H__
#define __TEST_LIB_H__

#include <glib-object.h>


G_BEGIN_DECLS

typedef void (*toContext) (cairo_t *cr, gboolean preserve);

void test_lib_graphics_assert_cmpsurface(toContext to_context, gchar *filename, gboolean preserve, gboolean generate);


G_END_DECLS

#endif /* __TEST_LIB_H__ */

