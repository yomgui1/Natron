# OPENEXR
OPENEXR_VERSION := 2.2.1
OPENEXR_TAR := openexr-${OPENEXR_VERSION}.tar.gz
OPENEXR_URL := http://download.savannah.nongnu.org/releases/openexr/$(OPENEXR_TAR)

ifeq ($(call need_pkg,"openexr"),)
PKGS_FOUND += openexr
endif

DEPS_openexr := ilmbase $(DEPS_ilmbase)

$(TARBALLS)/$(OPENEXR_TAR):
	$(call download,$(OPENEXR_URL))

.sum-openexr: $(OPENEXR_TAR)

openexr: $(OPENEXR_TAR) .sum-openexr
	$(UNPACK)
	$(MOVE)

.openexr: openexr
	cd $< && $(HOSTVARS) ./bootstrap
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
	cd $< && $(MAKE) install
	touch $@
