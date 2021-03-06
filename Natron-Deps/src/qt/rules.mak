# Qt

QT_VERSION_MAJOR := 5.12
QT_VERSION := $(QT_VERSION_MAJOR).2
# Insert potential -betaX suffix here:
QT_VERSION_FULL := $(QT_VERSION)
QT_URL := https://download.qt.io/official_releases/qt/$(QT_VERSION_MAJOR)/$(QT_VERSION_FULL)/submodules/qtbase-everywhere-src-$(QT_VERSION_FULL).tar.xz

ifdef HAVE_MACOSX
#PKGS += qt
endif
ifdef HAVE_WIN32
PKGS += qt
DEPS_qt = fxc2 $(DEPS_fxc2)
ifdef HAVE_CROSS_COMPILE
DEPS_qt += wine-headers
endif
endif

DEPS_qt += glib $(DEPS_glib) openssl $(DEPS_openssl) libxml2 $(DEPS_libxml2)
DEPS_qt += libxslt $(DEPS_libxslt) harfbuzz $(DEPS_harfbuzz) dbus $(DEPS_dbus)

ifeq ($(call need_pkg,"Qt5Core >= 5.12 Qt5Gui Qt5Widgets"),)
PKGS_FOUND += qt
endif

$(TARBALLS)/qtbase-everywhere-src-$(QT_VERSION_FULL).tar.xz:
	$(call download,$(QT_URL),qt)

.sum-qt: qtbase-everywhere-src-$(QT_VERSION_FULL).tar.xz

qt: qtbase-everywhere-src-$(QT_VERSION_FULL).tar.xz .sum-qt
	$(UNPACK)
ifdef HAVE_WIN32
	$(APPLY) $(SRC)/qt/0001-Windows-QPA-prefer-lower-value-when-rounding-fractio.patch
	$(APPLY) $(SRC)/qt/0002-Windows-QPA-Disable-systray-notification-sounds.patch
	$(APPLY) $(SRC)/qt/0004-Fix-PMurHash.c-mingw-clang-64-bit-compilation.patch
ifndef HAVE_WIN64
	$(APPLY) $(SRC)/qt/0001-disable-qt_random_cpu.patch
endif
	$(APPLY) $(SRC)/qt/0006-ANGLE-don-t-use-msvc-intrinsics-when-crosscompiling-.patch
	$(APPLY) $(SRC)/qt/0007-ANGLE-remove-static-assert-that-can-t-be-evaluated-b.patch
	$(APPLY) $(SRC)/qt/0008-ANGLE-disable-ANGLE_STD_ASYNC_WORKERS-when-compiling.patch

ifdef HAVE_CROSS_COMPILE
	$(APPLY) $(SRC)/qt/0003-allow-cross-compilation-of-angle-with-wine.patch
else
	$(APPLY) $(SRC)/qt/0003-fix-angle-compilation.patch
	cd $(UNPACK_DIR); for i in QtFontDatabaseSupport QtWindowsUIAutomationSupport QtEventDispatcherSupport QtCore; do \
		sed -i -e 's,"../../../../../src,"../src,g' include/$$i/$(QT_VERSION)/$$i/private/*.h; done
endif

endif
	$(APPLY) $(SRC)/qt/0001-qmake-Always-split-QMAKE_DEFAULT_LIBDIRS-using-with-.patch
	
	$(APPLY) $(SRC)/qt/0001-generate-different-pkg-config-files-for-debug-and-re.patch
	$(APPLY) $(SRC)/qt/0001-include-MODULE_AUX_INCLUDES-in-the-generated-.pc-fil.patch
	find $(UNPACK_DIR)/mkspecs -name qmake.conf -exec sed -i -e '/QMAKE_LIBDIR_X11/d' -e '/QMAKE_LIBDIR_OPENGL/d' {} \;
	$(MOVE)


ifdef HAVE_WIN32
QT_OPENGL := -angle
else
QT_OPENGL := -opengl desktop
endif

ifdef HAVE_MACOSX
QT_SPEC := darwin-g++
endif

ifdef HAVE_LINUX
ifeq ($(ARCH),x86_64)
QT_SPEC := linux-g++-64
else
QT_SPEC := linux-g++-32
endif
endif

ifdef HAVE_WIN32

ifdef HAVE_CLANG
QT_SPEC := win32-clang-g++
else
QT_SPEC := win32-g++
endif

endif

ifdef HAVE_CROSS_COMPILE
QT_PLATFORM := -xplatform $(QT_SPEC) -device-option CROSS_COMPILE=$(HOST)-
else
ifneq ($(QT_SPEC),)
QT_PLATFORM := -platform $(QT_SPEC)
endif
endif

QT_CONFIG := QMAKE_CFLAGS+="$(CFLAGS)" QMAKE_CXXFLAGS+="$(CXXFLAGS)" QMAKE_LFLAGS+="$(LDFLAGS)" \
		  -c++std c++14 -opensource -confirm-license \
		  -no-compile-examples -nomake examples -nomake tests \
		  -xcb-xlib -qt-xcb -openssl-runtime -sql-sqlite -qt-pcre -glib -dbus-linked \
		  $(QT_OPENGL)

QT_CONFIG += -release

# -pthread needed for glib detection
QT_CONFIG += QMAKE_LFLAGS+="-pthread"

ifeq ($(V),1)
QT_CONFIG += -verbose
endif

ifdef HAVE_MINGW_W64
QT_CONFIG += -no-direct2d
endif

ENV_VARS := $(HOSTVARS) DXSDK_DIR=$(PREFIX)/bin

.qt: qt
	cd $< && $(ENV_VARS) ./configure $(QT_PLATFORM) $(QT_CONFIG) -prefix $(PREFIX) -I $(PREFIX)/include
	# Make && Install libraries
	cd $< && $(ENV_VARS) $(MAKE)
	cd $< && $(MAKE) -j1 -C src \
	   sub-corelib-install_subtargets \
	   sub-gui-install_subtargets \
	   sub-widgets-install_subtargets \
	   sub-platformsupport-install_subtargets \
	   sub-bootstrap-install_subtargets \
	   sub-network-install_subtargets \
	   sub-testlib-install_subtargets \
	   sub-sql-install_subtargets \
	   sub-opengl-install_subtargets \
	   sub-openglextensions-install_subtargets \
	   sub-xml-install_subtargets \
	   sub-concurrent-install_subtargets \
	   sub-dbus-install_subtargets
	# Install tools
	cd $< && $(MAKE) -j1 -C src sub-moc-install_subtargets sub-rcc-install_subtargets sub-uic-install_subtargets sub-qlalr-install_subtargets
	# Install plugins
	cd $< && $(MAKE) -j1 -C src -C plugins \
	   sub-imageformats-install_subtargets \
	   sub-platforms-install_subtargets \
	   sub-styles-install_subtargets
	#$(SRC)/qt/AddStaticLink.sh "$(PREFIX)" Qt5Gui plugins/imageformats libqjpeg
ifdef HAVE_WIN32
	# Add the private include to our project (similar to using "gui-private" in a qmake project)
	sed -i.orig -e 's#-I$${includedir}/QtGui#-I$${includedir}/QtGui -I$${includedir}/QtGui/$(QT_VERSION)/QtGui#' $(PREFIX)/lib/pkgconfig/Qt5Gui.pc
	$(SRC)/qt/AddStaticLink.sh "$(PREFIX)" Qt5Gui plugins/platforms qwindows
	# Vista styling
	$(SRC)/qt/AddStaticLink.sh "$(PREFIX)" Qt5Widgets plugins/styles qwindowsvistastyle
endif
	# Install a qmake with correct paths set
	cd $< && $(MAKE) -j1 sub-qmake-qmake-aux-pro-install_subtargets install_mkspecs
	touch $@
