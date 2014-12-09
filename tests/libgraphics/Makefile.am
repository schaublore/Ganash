libgraphics=$(top_builddir)/libgraphics/libgraphics.la
libtests_libgraphics=$(top_builddir)/tests/libgraphics/libtests_libgraphics.la


check_PROGRAMS = tests_libgraphics
check_LTLIBRARIES = libtests_libgraphics.la

libtests_libgraphics_la_SOURCES =   \
    test-suite.h                    \
    test-suite.c                    \
    test-graphics-color.h           \
    test-graphics-color.c           \
    test-graphics-gradient.h        \
    test-graphics-gradient.c        \
    test-graphics-gradient-linear.h \
    test-graphics-gradient-linear.c \
    test-graphics-gradient-radial.h \
    test-graphics-gradient-radial.c \
    test-graphics-solid.h           \
    test-graphics-solid.c           \
    test-graphics-image.h           \
    test-graphics-image.c           \
    test-graphics-pattern.h         \
    test-graphics-pattern.c         \
    test-graphics-painter.h         \
    test-graphics-painter.c         \
    test-graphics-fill.h            \
    test-graphics-fill.c            \
    test-graphics-stroke.h          \
    test-graphics-stroke.c          \
    test-lib.h                      \
    test-lib.c

libtests_libgraphics_la_LIBADD =    \
    $(libgraphics)                  \
    $(CAIRO_LIBS)                   \
    $(GOBJECT_LIBS)

libtests_libgraphics_la_LDFLAGS =   \
    -lm

libtests_libgraphics_la_CFLAGS =                                        \
    -DTEST_GRAPHICS_SHARE_DIR=\"$(abs_top_srcdir)/tests/libgraphics/share/\"   \
    -I$(top_srcdir)                                                     \
    -I$(top_srcdir)/tests/libgraphics                                   \
    $(GOBJECT_CFLAGS)

tests_libgraphics_SOURCES =    \
    main.c

tests_libgraphics_LDFLAGS =    \
    -lm

tests_libgraphics_CFLAGS =          \
    -I$(top_srcdir)                 \
    $(CAIRO_CFLAGS)                 \
    $(GOBJECT_CFLAGS)

tests_libgraphics_LDADD =               \
    $(libgraphics)                      \
    $(libtests_libgraphics)             \
    $(CAIRO_LIBS)                       \
    $(GOBJECT_LIBS)
