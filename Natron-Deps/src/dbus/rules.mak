# DBUS
DBUS_VERSION := 1.12.8
DBUS_TAR := dbus-${DBUS_VERSION}.tar.gz
DBUS_URL := https://dbus.freedesktop.org/releases/dbus/$(DBUS_TAR)

ifeq ($(call need_pkg,"dbus-1"),)
PKGS_FOUND += dbus
endif

$(TARBALLS)/$(DBUS_TAR):
	$(call download,$(DBUS_URL),dbus)

.sum-dbus: $(DBUS_TAR)

dbus: $(DBUS_TAR) .sum-dbus
	$(UNPACK)
	$(MOVE)

.dbus: dbus
	cd $< && $(HOSTVARS) ./autogen.sh
	cd $< && $(HOSTVARS) ./configure $(HOSTCONF) --disable-docs --disable-doxygen-docs --disable-xml-docs
	cd $< && $(MAKE) install
	touch $@
