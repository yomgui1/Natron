# LIBTIFF
LIBTIFF_VERSION := 4.0.9
LIBTIFF_TAR := tiff-$(LIBTIFF_VERSION).tar.gz
LIBTIFF_URL := http://download.osgeo.org/libtiff/$(LIBTIFF_TAR)

ifeq ($(call need_pkg,"libtiff-4"),)
PKGS_FOUND += libtiff
endif

$(TARBALLS)/$(LIBTIFF_TAR):
	$(call download,$(LIBTIFF_URL),libtiff)

.sum-libtiff: $(LIBTIFF_TAR)

libtiff: $(LIBTIFF_TAR) .sum-libtiff
	$(UNPACK)
	$(MOVE)

.libtiff: libtiff
	$(RECONF)
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
	cd $< && $(MAKE) install
	touch $@
