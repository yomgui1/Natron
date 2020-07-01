# Python2.x

PYTHON2_VERSION := 2.7.16
PYTHON2_URL := https://www.python.org/ftp/python/$(PYTHON2_VERSION)/Python-$(PYTHON2_VERSION).tar.xz
PYTHON2_LOCAL_ARCHIVE := Python-$(PYTHON2_VERSION).tar.xz

PKGS += python2

ifeq ($(call need_pkg,"python2>=$(PYTHON2_VERSION)"),)
PKGS_FOUND += python2
endif

DEPS_python2 = ffi $(DEPS_ffi) openssl $(DEPS_openssl) expat $(DEPS_expat) bzip2 $(DEPS_bzip2) zlib $(DEPS_zlib)

$(TARBALLS)/$(PYTHON2_LOCAL_ARCHIVE):
	$(call download_pkg,$(PYTHON2_URL),python2)

.sum-python2: $(PYTHON2_LOCAL_ARCHIVE)

python2: $(PYTHON2_LOCAL_ARCHIVE) .sum-python2
	$(UNPACK)
	$(MOVE)

.python2: python2
	$(RECONF)
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF) --with-system-ffi --with-system-expat --enable-optimizations --with-ensurepip=yes --enable-unicode=ucs4
	cd $< && $(MAKE) install
	touch $@