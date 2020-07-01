# Qt5Svg

QTSVG_VERSION_MAJOR := 5.12
QTSVG_VERSION := $(QTSVG_VERSION_MAJOR).2
# Insert potential -betaX suffix here:
QTSVG_VERSION_FULL := $(QTSVG_VERSION)
QTSVG_URL := https://download.qt.io/official_releases/qt/$(QTSVG_VERSION_MAJOR)/$(QTSVG_VERSION_FULL)/submodules/qtsvg-everywhere-src-$(QTSVG_VERSION_FULL).tar.xz

ifdef HAVE_LINUX
PKGS += qtsvg
endif
ifdef HAVE_MACOSX
#PKGS += qtsvg
endif
ifdef HAVE_WIN32
PKGS += qtsvg
DEPS_qtsvg = fxc2 $(DEPS_fxc2)
ifdef HAVE_CROSS_COMPILE
DEPS_qtsvg += wine-headers
endif
endif

DEPS_qtsvg += qt $(DEPS_qt)

ifeq ($(call need_pkg,"Qt5Svg >= 5.12"),)
PKGS_FOUND += qtsvg
endif

$(TARBALLS)/qtsvg-everywhere-src-$(QTSVG_VERSION_FULL).tar.xz:
	$(call download,$(QTSVG_URL),qt)

.sum-qtsvg: qtsvg-everywhere-src-$(QTSVG_VERSION_FULL).tar.xz

qtsvg: qtsvg-everywhere-src-$(QTSVG_VERSION_FULL).tar.xz .sum-qtsvg
	$(UNPACK)
	$(MOVE)

.qtsvg: qtsvg
	cd $< && $(HOSTVARS) qmake
	cd $< && $(HOSTVARS) $(MAKE) install
	touch $@
