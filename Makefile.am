#SUBDIRS = include lib sample 
#SUBDIRS = include lib sample testunit
SUBDIRS = include lib testunit

devdocsdir = $(datadir)/doc/uhttp-dev
docsdir = $(datadir)/doc/uhttp0

EXTRA_DIST = debian/changelog \
	debian/uhttp0.install \
	debian/uhttp-dev.install \
	debian/compat \
	debian/control \
	debian/copyright \
	debian/rules \
	debian/docs \
	include/cybergarage/upnp/cupnp.h.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = uhttp.pc

dist_docs_DATA = \
	COPYING

dist_devdocs_DATA = \
	ChangeLog \
	COPYING \
	Doxyfile

nobase_devdocs_DATA = \
	doxygen/html/*

doxygen/html/*:
	cd $(srcdir) && doxygen Doxyfile
# scp -r doxygen skonno,uhttp@frs.sourceforge.net:/home/groups/c/cl/uhttp/htdocs

deb: dist
	-mkdir $(top_builddir)/debian-build
	-cp $(top_builddir)/../$(PACKAGE)*.orig.tar.gz $(top_builddir)/debian-build/
	cd $(top_builddir)/debian-build && tar zxf ../$(top_builddir)/$(PACKAGE)-$(VERSION).tar.gz
	cd $(top_builddir)/debian-build/$(PACKAGE)-$(VERSION) && dpkg-buildpackage -rfakeroot -sa -D
	-rm -rf $(top_builddir)/debian-build/$(PACKAGE)-$(VERSION)
