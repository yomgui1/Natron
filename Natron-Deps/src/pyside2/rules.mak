# PYSIDE2
PYSIDE2_HASH := 8689054da961be4cede5cfae7c6a6f9d6efc36a4
PYSIDE2_BRANCH := 5.12
PYSIDE2_GITURL := https://code.qt.io/pyside/pyside-setup
PYSIDE2_BASENAME := $(PYSIDE2_HASH)

ifeq ($(call need_pkg,"pyside2"),)
PKGS_FOUND += pyside2
endif

PYSIDE2_DEPS := python2 $(DEPS_python2) qt $(DEPS_qt) qtsvg $(DEPS_qtsvg)

#MKJOBS := $(shell nproc)
MKJOBS := 12

PYSIDE2_CONF := --prefix=$(PREFIX) --qmake=$(PREFIX)/bin/qmake --parallel=$(MKJOBS)
PYSIDE2_CONF += --qt-src-dir=$(BUILDPREFIX)/qt --rpath=$(PREFIX)/lib --skip-docs

ifeq ($(V),1)
PYSIDE2_CONF += --verbose-build
endif

$(TARBALLS)/pyside2-$(PYSIDE2_BASENAME).tar.xz:
	$(call download_git,$(PYSIDE2_GITURL),$(PYSIDE2_BRANCH),$(PYSIDE2_HASH))

.sum-pyside2: $(TARBALLS)/pyside2-$(PYSIDE2_BASENAME).tar.xz
	$(call check_githash,$(PYSIDE2_HASH))
	touch $@

pyside2: pyside2-$(PYSIDE2_BASENAME).tar.xz .sum-pyside2
	rm -Rf $@ $@-$(PYSIDE2_BASENAME)
	mkdir -p $@-$(PYSIDE2_BASENAME)
	tar xvJf "$<" --strip-components=1 -C $@-$(PYSIDE2_BASENAME)
	$(MOVE)

.pyside2: pyside2
	# We forcing system-wide ld config to cache our installed libraries to be found
	ldconfig $(SDK)/lib
	cd $< && $(HOSTVARS) python2 setup.py install $(PYSIDE2_CONF)
	touch $@
