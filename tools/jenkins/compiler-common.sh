#!/bin/bash

set -e # Exit immediately if a command exits with a non-zero status
set -u # Treat unset variables as an error when substituting.
#set -x # Print commands and their arguments as they are executed.


if [ "$PKGOS" = "OSX" ]; then
    # Mac compiler
    #
    #
    # 10 -> 10.6
    # 16 -> 10.12
    osxver=$(uname -r)

    # if clang-mp-5.0 or clang-mp-4.0 is available
    if command -v clang-mp-5.0 >/dev/null 2>&1 || command -v clang-mp-4.0 >/dev/null 2>&1; then
        COMPILER=clang-omp
        if grep -q "configure.optflags.*-Os" /opt/local/libexec/macports/lib/port1.0/portconfigure.tcl; then
            echo "Warning: clang-3.9.1 is known to generate wrong code with -Os on openexr, please edit /opt/local/libexec/macports/lib/port1.0/portconfigure.tcl and set configure.optflags to -O2"
            #exit 1
        fi
    fi
    # clang path on homebrew (should always be the latest version)
    if command -v /usr/local/opt/llvm/bin/clang >/dev/null 2>&1; then
        COMPILER=clang-omp
    fi
    #COMPILER=clang-omp
    COMPILER=${COMPILER:-gcc}

    if [ "$COMPILER" != "gcc" -a "$COMPILER" != "clang" -a "$COMPILER" != "clang-omp" ]; then
        echo "Error: COMPILER must be gcc or clang or clang-omp"
        exit 1
    fi
    if [ "$COMPILER" = "clang" ]; then
        case "$osxver" in
            9.*|10.*|11.*|12.*)
                # GXX should be an openmp-capable compiler (to compile CImg.ofx)

                # older version, using clang-3.4
                CC=clang-mp-3.4
                CXX="clang++-mp-3.4 -std=c++11"
                GXX=g++-mp-4.9
                OBJECTIVE_CC=$CC
                OBJECTIVE_CXX=$CXX
                ;;
            *)
                # newer OS X / macOS version link with libc++ and can use the system clang
                CC=clang
                CXX="clang++ -std=c++11"
                OBJECTIVE_CC=$CC
                OBJECTIVE_CXX=$CXX
                ;;
        esac
    elif [ "$COMPILER" = "clang-omp" ]; then
        # newer version (testing) using clang-4.0
        CC=clang-mp-4.0
        CXX="clang++-mp-4.0 -stdlib=libc++ -std=c++11"
        # newer version (testing) using clang
        # if clang-mp-5.0 is available
        if command -v clang-mp-6.0 >/dev/null 2>&1; then
            CC=clang-mp-6.0
            CXX="clang++-mp-6.0 -stdlib=libc++ -std=c++11"
        elif command -v clang-mp-5.0 >/dev/null 2>&1; then
            CC=clang-mp-5.0
            CXX="clang++-mp-5.0 -stdlib=libc++ -std=c++11"
        elif command -v clang-mp-4.0 >/dev/null 2>&1; then
            CC=clang-mp-4.0
            CXX="clang++-mp-4.0 -stdlib=libc++ -std=c++11"
        elif command -v /usr/local/opt/llvm/bin/clang >/dev/null 2>&1; then
            CC=/usr/local/opt/llvm/bin/clang
            CXX="/usr/local/opt/llvm/bin/clang++ -std=c++11"
        fi

        OBJECTIVE_CC=$CC
        OBJECTIVE_CXX=$CXX
    else
        #GCC_VERSION=4.8
        GCC_VERSION=4.9
        #GCC_VERSION=5
        #GCC_VERSION=6
        CC=gcc-mp-${GCC_VERSION}
        CXX=g++-mp-${GCC_VERSION}
        OBJECTIVE_CC=gcc-4.2
        OBJECTIVE_CXX=g++-4.2
    fi

    # SDK root was moved with Xcode 4.3
    MACOSX_SDK_ROOT=/Developer/SDKs
    case "$osxver" in
        10.*)
            MACOSX_DEPLOYMENT_TARGET=10.6
            ;;
        13.*)
            MACOSX_DEPLOYMENT_TARGET=10.9
            MACOSX_SDK_ROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
            ;;
        16.*)
            MACOSX_DEPLOYMENT_TARGET=10.12
            MACOSX_SDK_ROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
            ;;
        17.*)
            MACOSX_DEPLOYMENT_TARGET=10.13
            MACOSX_SDK_ROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
            ;;
        18.*)
            MACOSX_DEPLOYMENT_TARGET=10.14
            MACOSX_SDK_ROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
            ;;
    esac
    export MACOSX_DEPLOYMENT_TARGET
    export MACOSX_SYSROOT="${MACOSX_SDK_ROOT}/MacOSX${MACOSX_DEPLOYMENT_TARGET}.sdk"


elif [ "$PKGOS" = "Linux" ]; then
    COMPILER=gcc
    GCC_VERSION=$($COMPILER --version | head -n1 | awk '{print $3}')
    echo "Found GCC version $GCC_VERSION"

    if [ "${COMPILE_TYPE:-}" = "debug" ]; then
        BF="-g"
    else
        BF="-O2"
    fi

    if [ "$BITS" = "32" ]; then
        BF="$BF -march=i686 -mtune=i686"
    elif [ "$BITS" = "64" ]; then
        BF="$BF -fPIC"
    fi
fi



COMPILER=${COMPILER:-gcc}
CC=${CC:-gcc}
CXX=${CXX:-g++}
OBJECTIVE_CC=${OBJECTIVE_CC:-${CC}}
OBJECTIVE_CXX=${OBJECTIVE_CXX:-${CXX}}

# Local variables:
# mode: shell-script
# sh-basic-offset: 4
# sh-indent-comment: t
# indent-tabs-mode: nil
# End:
