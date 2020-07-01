# EXPAT
EXPAT_VERSION := 2.2.6
EXPAT_DL_VERSION := 2_2_6
EXPAT_URL := https://github.com/libexpat/libexpat/archive/R_$(EXPAT_DL_VERSION).tar.gz

ifeq ($(call need_pkg,"expat"),)
PKGS_FOUND += expat
endif

$(TARBALLS)/libexpat-R_$(EXPAT_DL_VERSION).tar.gz:
	$(call download,$(EXPAT_URL),expat)

.sum-expat: libexpat-R_$(EXPAT_DL_VERSION).tar.gz

expat: libexpat-R_$(EXPAT_DL_VERSION).tar.gz .sum-expat
	$(UNPACK)
	$(MOVE)

.expat: expat
	cd $</expat && ./buildconf.sh
	cd $</expat && $(HOSTVARS) ./configure $(HOSTCONF) --without-docbook --without-xmlwf
	cd $</expat && $(MAKE) install
	touch $@
