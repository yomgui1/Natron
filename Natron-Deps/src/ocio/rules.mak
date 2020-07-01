# OCIO
OCIO_VERSION := 1.1.1
OCIO_TAR := OpenColorIO-${OCIO_VERSION}.tar.gz
OCIO_URL := https://github.com/imageworks/OpenColorIO/archive/v$(OCIO_VERSION).tar.gz

ifeq ($(call need_pkg,"ocio"),)
PKGS_FOUND += ocio
endif

DEPS_ocio := boost $(DEPS_boost) python2 $(DEPS_python2)

OCIO_CMAKE_CONF := -DCMAKE_BUILD_TYPE=Release -DOCIO_BUILD_JNIGLUE=OFF -DOCIO_BUILD_NUKE=OFF -DOCIO_BUILD_SHARED=ON -DOCIO_BUILD_STATIC=OFF -DOCIO_STATIC_JNIGLUE=OFF -DOCIO_BUILD_TRUELIGHT=OFF -DUSE_EXTERNAL_LCMS=OFF -DUSE_EXTERNAL_TINYXML=OFF -DUSE_EXTERNAL_YAML=OFF -DOCIO_BUILD_APPS=OFF -DOCIO_USE_BOOST_PTR=ON -DPYTHON=python2

$(TARBALLS)/$(OCIO_TAR):
	$(call download,$(OCIO_URL))

.sum-ocio: $(OCIO_TAR)

ocio: $(OCIO_TAR) .sum-ocio
	$(UNPACK)
	$(MOVE)

.ocio: ocio
	# Don't treat warnings as error
	cd $< && find . -name CMakeLists.txt -exec sed -e s/-Werror// -i {} \;
	cd $< && $(CMAKE) $(OCIO_CMAKE_CONF)
	cd $< && $(MAKE) install
	touch $@
