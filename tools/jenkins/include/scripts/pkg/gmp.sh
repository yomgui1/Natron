#!/bin/bash

# Install gmp (used by ruby)
GMP_VERSION=6.1.2
GMP_TAR="gmp-${GMP_VERSION}.tar.bz2"
GMP_SITE="https://gmplib.org/download/gmp"
# version is also set in gcc.sh
# see http://www.linuxfromscratch.org/lfs/view/development/chapter06/gmp.html
if download_step; then
    download "$GMP_SITE" "$GMP_TAR"
fi
if build_step && { force_build || { [ ! -s "$SDK_HOME/include/gmp.h" ]; }; }; then
    REBUILD_RUBY=1
	REBUILD_NETTLE=1
    start_build
    untar "$SRC_PATH/$GMP_TAR"
    pushd "gmp-${GMP_VERSION}"
    env CFLAGS="$BF" CXXFLAGS="$BF" ./configure --prefix="$SDK_HOME" --disable-static --enable-shared --enable-cxx --build="${ARCH}-unknown-linux-gnu"
    make -j${MKJOBS}
    make install
    popd
    rm -rf "gmp-${GMP_VERSION}"
    end_build
fi
