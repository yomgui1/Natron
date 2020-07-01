# PIXMAN
PIXMAN_VERSION := 0.34.0
PIXMAN_TAR := pixman-$(PIXMAN_VERSION).tar.gz
PIXMAN_URL := https://www.cairographics.org/releases/$(PIXMAN_TAR)

ifeq ($(call need_pkg,"pixman"),)
PKGS_FOUND += pixman
endif

$(TARBALLS)/$(PIXMAN_TAR):
	$(call download,$(PIXMAN_URL),pixman)

.sum-pixman: $(PIXMAN_TAR)

pixman: $(PIXMAN_TAR) .sum-pixman
	$(UNPACK)
	$(MOVE)

.pixman: pixman
	$(RECONF)
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
	cd $< && $(MAKE) install
	touch $@
