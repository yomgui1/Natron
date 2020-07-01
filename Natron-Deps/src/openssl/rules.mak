# OpenSSL

# Version 1.1.1 is the LTS serie as noticed by OpenSSL team:
#
# "Note: The latest stable version is the 1.1.1 series.
# This is also our Long Term Support (LTS) version, supported until 11th September 2023.
# Our previous LTS version (1.0.2 series) will continue to be supported until 31st December 2019"
#

OPENSSL_VERSION := 1.1.1b
OPENSSL_URL := https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz

ifeq ($(call need_pkg,"openssl >= 1.1"),)
PKGS_FOUND += openssl
endif

OPENSSL_CONF = --prefix="$(PREFIX)" no-shared no-tests

$(TARBALLS)/openssl-${OPENSSL_VERSION}.tar.gz:
	$(call download_pkg,$(OPENSSL_URL),glib)

.sum-openssl: openssl-${OPENSSL_VERSION}.tar.gz

openssl: openssl-${OPENSSL_VERSION}.tar.gz .sum-openssl
	$(UNPACK)
	$(MOVE)

.openssl: openssl
	cd $< && $(HOSTVARS) ./config $(OPENSSL_CONF)
	# No parallel build for openssl (fail with multiple jobs)
	cd $< && $(MAKE) -j1 install
	touch $@
