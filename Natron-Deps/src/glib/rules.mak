# GLIB
GLIB_VERSION := 2.58
GLIB_MINOR_VERSION := 2.58.3
GLIB_URL := http://ftp.gnome.org/pub/gnome/sources/glib/$(GLIB_VERSION)/glib-$(GLIB_MINOR_VERSION).tar.xz

ifeq ($(call need_pkg,"glib-2.0 gthread-2.0"),)
PKGS_FOUND += glib
endif

DEPS_glib = python2 $(DEPS_python2) png $(DEPS_png) openjpeg $(DEPS_openjpeg) freetype2 $(DEPS_freetype2)

GLIB_CONF := $(HOSTCONF) --disable-selinux --with-pcre=internal --disable-libmount --disable-man --disable-installed-tests

$(TARBALLS)/glib-$(GLIB_MINOR_VERSION).tar.xz:
	$(call download,$(GLIB_URL),glib)

.sum-glib: glib-$(GLIB_MINOR_VERSION).tar.xz

glib: glib-$(GLIB_MINOR_VERSION).tar.xz .sum-glib
	$(UNPACK)
	$(MOVE)

.glib: glib
	cd $< && $(HOSTVARS) ./autogen.sh $(GLIB_CONF)
	cd $< && $(HOSTVARS) $(MAKE) install
	touch $@
