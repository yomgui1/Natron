# OIIO
OIIO_VERSION := 1.8.17
OIIO_TAR := oiio-Release-${OIIO_VERSION}.tar.gz
OIIO_URL := https://github.com/OpenImageIO/oiio/archive/Release-$(OIIO_VERSION).tar.gz

OPENJPEG_SHORT_VERSION := 2.3

ifeq ($(call need_pkg,"oiio"),)
PKGS_FOUND += oiio
endif

DEPS_oiio := openexr $(DEPS_openexr) openjpeg $(DEPS_openjpeg) boost $(DEPS_boost) freetype2 $(DEPS_freetype2)

OIIO_CMAKE_CONF := -DCMAKE_BUILD_TYPE=Release -DUSE_OPENCV:BOOL=FALSE -DUSE_OPENSSL:BOOL=FALSE -DOPENEXR_HOME=$(SDK) -DILMBASE_HOME=$(SDK) -DTHIRD_PARTY_TOOLS_HOME=$(SDK) -DUSE_QT:BOOL=FALSE -DUSE_PYTHON:BOOL=FALSE -DUSE_FIELD3D:BOOL=FALSE -DOIIO_BUILD_TESTS=0 -DOIIO_BUILD_TOOLS=1 -DBOOST_ROOT=$(SDK) -DSTOP_ON_WARNING:BOOL=FALSE -DUSE_GIF:BOOL=TRUE -DUSE_FREETYPE:BOOL=TRUE -DFREETYPE_INCLUDE_PATH=$(SDK) -DUSE_FFMPEG:BOOL=FALSE -DLINKSTATIC=0 -DBUILDSTATIC=0 -DOPENJPEG_HOME=$(SDK) -DOPENJPEG_INCLUDE_DIR=$(SDK)/include/openjpeg-$(OPENJPEG_SHORT_VERSION) -DUSE_OPENJPEG:BOOL=TRUE -DUSE_LIBRAW:BOOL=TRUE -DUSE_CPP11:BOOL=FALSE -DUSE_CPP14:BOOL=TRUE -DUSE_CPP17:BOOL=FALSE

$(TARBALLS)/$(OIIO_TAR):
	$(call download,$(OIIO_URL))

.sum-oiio: $(OIIO_TAR)

oiio: $(OIIO_TAR) .sum-oiio
	$(UNPACK)
	$(MOVE)

.oiio: oiio
	cd $< && [ -d ./build ] || mkdir build
	cd $</build && $(subst . ,.. ,$(CMAKE)) $(OIIO_CMAKE_CONF)
	cd $</build && $(MAKE) install
	touch $@
