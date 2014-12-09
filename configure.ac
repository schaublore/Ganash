dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(ganash, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([no])

AC_PROG_CC
AM_PROG_CC_C_O




dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=ganash
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])

AM_GLIB_GNU_GETTEXT

LT_INIT


dnl ***************************************************************************
dnl Dependencies
dnl ***************************************************************************

dnl === Program ===============================================================
PKG_CHECK_MODULES(GTK, [gtk+-2.0])

PKG_CHECK_MODULES(GOBJECT,gobject-2.0)

PKG_CHECK_MODULES(CAIRO,cairo)

PKG_CHECK_MODULES(CROCO, libcroco-0.6)

PKG_CHECK_MODULES(XML, libxml-2.0)

PKG_CHECK_MODULES(JS, [javascriptcoregtk-3.0])

PKG_CHECK_MODULES(VTE, [vte])


dnl ***************************************************************************
dnl API Reference
dnl ***************************************************************************
GTK_DOC_CHECK([1.0])


AC_OUTPUT([
Makefile
libgraphics/Makefile
src/Makefile
po/Makefile.in
tests/Makefile
tests/libgraphics/Makefile
docs/reference/libgraphics/Makefile
])
