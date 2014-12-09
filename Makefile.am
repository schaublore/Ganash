## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = libgraphics
SUBDIRS += src po
SUBDIRS += tests
SUBDIRS += docs

ganashdocdir = ${prefix}/doc/ganash
ganashdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(ganashdoc_DATA) \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(ganashdocdir)
