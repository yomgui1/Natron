# BOOST
BOOST_VERSION := 1.67.0
BOOST_TAR := boost_$(subst .,_,$(BOOST_VERSION)).tar.bz2
BOOST_URL := "https://dl.bintray.com/boostorg/release/${BOOST_VERSION}/source/$(BOOST_TAR)"

ifeq ($(call need_pkg,"boost"),)
PKGS_FOUND += boost
endif

DEPS_boost := python2 $(DEPS_python2)

BOOST_CONF = -s --prefix="$(PREFIX)" cflags="$(CFLAGS)" cxxflags="$(CXXFLAGS)" install -j$(shell nproc) threading=multi link=shared

$(TARBALLS)/$(BOOST_TAR):
	$(call download,$(BOOST_URL),"boost")

.sum-boost: $(BOOST_TAR)

boost: $(BOOST_TAR) .sum-boost
	$(UNPACK)
	$(MOVE)

.boost: boost
	cd $< && $(HOSTVARS) ./bootstrap.sh --prefix=$(PREFIX)
	cd $< && $(HOSTVARS) ./b2 $(BOOST_CONF)
	touch $@
