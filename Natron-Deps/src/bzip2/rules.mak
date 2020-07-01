# BZIP2
BZIP2_VERSION := 1.0.6
BZIP2_URL := $SF/bzip2-$(BZIP2_VERSION).tar.gz

ifeq ($(call need_pkg,"bzip2"),)
PKGS_FOUND += bzip2
endif

BZIP2_HOSTVAR = $(HOSTTOOLS)
BZIP2_SO_HOSTVAR = $(HOSTTOOLS)

$(TARBALLS)/bzip2-$(BZIP2_VERSION).tar.gz:
	$(call download,$(BZIP2_URL),bzip2)

.sum-bzip2: bzip2-$(BZIP2_VERSION).tar.gz

bzip2: bzip2-$(BZIP2_VERSION).tar.gz .sum-bzip2
	$(UNPACK)
	$(MOVE)

.bzip2: bzip2
	# Patches/Build from Fedora package
	$(APPLY) $(SRC)/bzip2/set-out-file-to-null.patch
	cd $< && $(MAKE) -f Makefile-libbz2_so $(BZIP2_SO_HOSTVAR)
	cd $< && rm -f *.o
	cd $< && $(MAKE) -f Makefile $(BZIP2_HOSTVAR)
	cd $< && chmod 644 bzlib.h
	cd $< && mkdir -p $(PREFIX)/{bin,lib/pkgconfig,include}
	cd $< && cp -p bzlib.h $(PREFIX)/include
	cd $< && install -m 755 libbz2.so.$(BZIP2_VERSION) $(PREFIX)/lib
	cd $< && install -m 644 $(SRC)/bzip2/bzip2.pc $(PREFIX)/lib/pkgconfig/bzip2.pc
	sed -i -e "s|@prefix@|$(PREFIX)|g" $(PREFIX)/lib/pkgconfig/bzip2.pc
	cd $< && install -m 755 bzip2-shared $(PREFIX)/bin/bzip2
	cd $< && install -m 755 bzip2recover bzgrep bzdiff bzmore $(PREFIX)/bin/
	cd $< && ln -fs bzip2 $(PREFIX)/bin/bunzip2
	cd $< && ln -fs bzip2 $(PREFIX)/bin/bzcat
	cd $< && ln -fs bzdiff $(PREFIX)/bin/bzcmp
	cd $< && ln -fs bzmore $(PREFIX)/bin/bzless
	cd $< && ln -fs bzgrep $(PREFIX)/bin/bzegrep
	cd $< && ln -fs bzgrep $(PREFIX)/bin/bzfgrep
	cd $< && ln -fs libbz2.so.$(BZIP2_VERSION) $(PREFIX)/lib/libbz2.so.1
	cd $< && ln -fs libbz2.so.1 $(PREFIX)/lib/libbz2.s
	touch $@
