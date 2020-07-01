# ILMBASE
ILMBASE_VERSION := 2.2.1
ILMBASE_TAR := ilmbase-${ILMBASE_VERSION}.tar.gz
ILMBASE_URL := http://download.savannah.nongnu.org/releases/ilmbase/$(ILMBASE_TAR)

ifeq ($(call need_pkg,"ilmbase"),)
PKGS_FOUND += ilmbase
endif

$(TARBALLS)/$(ILMBASE_TAR):
	$(call download,$(ILMBASE_URL))

.sum-ilmbase: $(ILMBASE_TAR)

ilmbase: $(ILMBASE_TAR) .sum-ilmbase
	$(UNPACK)
	$(MOVE)

.ilmbase: ilmbase
	cd $< && $(HOSTVARS) ./bootstrap
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
	cd $< && $(MAKE) install
	touch $@
