libmath=$(top_builddir)/libmath/libmath.la
libgeom=$(top_builddir)/libgeom/libgeom.la
libgraphics=$(top_builddir)/libgraphics/libgraphics.la
librenderer=$(top_builddir)/librenderer/librenderer.la
libmotion=$(top_builddir)/libmotion/libmotion.la
libsvg=$(top_builddir)/libsvg/libsvg.la

libtests_libmath=$(top_builddir)/tests/libmath/libtests_libmath.la
libtests_libgeom=$(top_builddir)/tests/libgeom/libtests_libgeom.la
libtests_libgraphics=$(top_builddir)/tests/libgraphics/libtests_libgraphics.la
libtests_librenderer=$(top_builddir)/tests/librenderer/libtests_librenderer.la
libtests_libmotion=$(top_builddir)/tests/libmotion/libtests_libmotion.la
libtests_libsvg=$(top_builddir)/tests/libsvg/libtests_libsvg.la


SUBDIRS =        \
    libmath      \
    libgeom      \
    libgraphics  \
    librenderer  \
    libmotion    \
    libsvg       \
    libsvg-js


check_PROGRAMS = tests

tests_SOURCES = \
    main.c

tests_CFLAGS =          \
    -I$(top_srcdir)     \
    -I$(top_srcdir)/src \
    $(GTHREAD_CFLAGS)   \
    $(GTK_CFLAGS)       \
    $(XML_CFLAGS)       \
    $(CROCO_CFLAGS)

#    $(GEGL_CFLAGS)

#    $(GEGL_LIBS)

tests_ldadd =                               \
    $(libmath)     $(libtests_libmath)      \
    $(libgeom)     $(libtests_libgeom)      \
    $(libgraphics) $(libtests_libgraphics)  \
    $(librenderer) $(libtests_librenderer)  \
    $(libmotion)   $(libtests_libmotion)    \
    $(libsvg)      $(libtests_libsvg)

tests_LDADD =               \
    $(GTHREAD_LIBS)         \
    $(GTK_LIBS)             \
    $(XML_LIBS)             \
    $(CROCO_LIBS)           \
    $(tests_ldadd)
