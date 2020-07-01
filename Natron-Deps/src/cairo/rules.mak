# CAIRO
CAIRO_VERSION := 1.14.12
CAIRO_TAR := cairo-$(CAIRO_VERSION).tar.xz
CAIRO_URL := https://www.cairographics.org/releases/$(CAIRO_TAR)

ifeq ($(call need_pkg,"cairo"),)
PKGS_FOUND += cairo
endif

DEPS_cairo := pixman $(DEPS_pixman)

$(TARBALLS)/$(CAIRO_TAR):
	$(call download,$(CAIRO_URL),cairo)

.sum-cairo: $(CAIRO_TAR)

cairo: $(CAIRO_TAR) .sum-cairo
	$(UNPACK)
	$(MOVE)

.cairo: cairo
	$(RECONF)
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
	cd $< && $(MAKE) install
	touch $@
