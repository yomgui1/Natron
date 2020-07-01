# libxslt

LIBXSLT_VERSION := 1.1.32
LIBXSLT_URL := ftp://xmlsoft.org/libxslt/libxslt-$(LIBXSLT_VERSION).tar.gz

ifeq ($(call need_pkg,"libxslt"),)
PKGS_FOUND += libxslt
endif

DEPS_libxslt += libxml2 $(DEPS_libxml2)

$(TARBALLS)/libxslt-$(LIBXSLT_VERSION).tar.gz:
	$(call download,$(LIBXSLT_URL),libxslt)

.sum-libxslt: libxslt-$(LIBXSLT_VERSION).tar.gz

XSLTCONF = --disable-docs --without-python

libxslt: libxslt-$(LIBXSLT_VERSION).tar.gz .sum-libxslt
	$(UNPACK)
	$(call pkg_static,"libxslt.pc.in")
	$(MOVE)

.libxslt: libxslt
	$(RECONF)
	# this increases the recursion limit in libxslt. This is needed by some packages for their documentation
	cd $< && sed -i s/3000/5000/ libxslt/transform.c doc/xsltproc.{1,xml}
	cd $< && ./configure $(HOSTCONF) $(XSLTCONF)
	cd $< && $(MAKE) install
	touch $@
