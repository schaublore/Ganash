dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(ganash, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([no])

AC_PROG_CC




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

dnl === Gtk ===================================================================
PKG_CHECK_MODULES(GANASH, [gtk+-3.0 ])



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
])
