#!/usr/bin/scl enable devtoolset-8 rh-git29 -- bash
# This file is part of Natron.
# Copyright (C) 2019 Guillaume Roguez
#
# Natron is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Natron is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>

set -eu
set -x

D="$NATRON_BUILD_DIR/Natron-snapshot"
rm -rf $D

mkdir -p $D/{bin,lib,Plugins,docs/natron}
mkdir -p $D/Resources/{pixmaps,stylesheets}
mkdir -p $D/Resources/etc/fonts/conf.d

# Natron binaries
cp "$NATRON_BUILD_DIR"/natron/Tests/Tests $D/bin/
cp "$NATRON_BUILD_DIR"/natron/App/Natron $D/bin/
cp "$NATRON_BUILD_DIR"/natron/Renderer/NatronRenderer $D/bin/
cp "$NATRON_BUILD_DIR"/natron/ProjectConverter/NatronProjectConverter $D/bin/
cp "$NATRON_BUILD_DIR"/natron/PythonBin/natron-python $D/bin/

# Documentation
cp "$NATRON_SRC_DIR"/LICENSE.txt $D/docs/natron/

# Resources
cp "$NATRON_SRC_DIR"/Gui/Resources/Stylesheets/mainstyle.qss $D/Resources/stylesheets/
cp "$NATRON_SRC_DIR"/Gui/Resources/Images/natronIcon256_linux.png $D/Resources/pixmaps/
cp "$NATRON_SRC_DIR"/Gui/Resources/Images/natronProjectIcon_linux.png $D/Resources/pixmaps/
cp "$NATRON_SRC_DIR"/Gui/Resources/etc/fonts/fonts.conf $D/Resources/etc/fonts/
cp "$NATRON_SRC_DIR"/Gui/Resources/etc/fonts/conf.d/* $D/Resources/etc/fonts/conf.d/

# 3rd party binaries
for f in exrheader ffmpeg ffprobe iconvert idiff igrep iinfo tiffinfo;
do
	[ -f "$SDK/bin/$f" ] && cp "$SDK/bin/$f" $D/bin/
done

# OS binaries
for f in strings;
do
	[ -f "$SDK/bin/$f" ] && cp "/usr/bin/$f" $D/bin/
done

# Qt plugins
for dir in $(ls "$SDK"/plugins);
do
	cp -a "$SDK/plugins/$dir" $D/bin/
done

# Python
PYVER=2.7
PY_PKG_PATH="$D/lib/python${PYVER}/site-packages/"
cp -a "$SDK/lib/python${PYVER}" "$D/lib/"
rm -rf "${PY_PKG_PATH}/shiboken2_"*
rm -rf "${PY_PKG_PATH}/pip"*
rm -rf "${PY_PKG_PATH}/setuptools"*
rm -rf "${PY_PKG_PATH}/pkg_resources"
rm -rf "$D/lib/python${PYVER}"/{test,config,config-"${PYVER}m"}

if [[ ! -f "$SDK/lib/python27.zip" ]]; then
	pushd "$SDK/lib/python${PYVER}"
	zip -r -m "$SDK/lib/python27.zip" * -x site-packages\* lib-dynload\* lib2to3\* \
		lib-tk\* plat-linux2\* LICENSE.txt pdb.doc wsgiref.egg-info || true
	popd
fi
cp "$SDK/lib/python27.zip" "$D/lib/"

LD_LIBRARY_PATH="${PY_PKG_PATH}/shiboken2:${PY_PKG_PATH}/PySide2${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

# OpenColorIO
cp "$SDK/lib/libOpenColorIO.so.1" "$D/lib/"

# OpenImageIO
cp "$SDK/lib/libOpenImageIO.so.1.8" "$D/lib/"

# Binary Libraries
CORE_DEPENDS=$(ldd $(find "$D/bin" -type f) | grep /opt | awk '{print $3}' | sort -u)
for i in $CORE_DEPENDS;
do
    dep=$(basename "$i")
    if [ ! -f "$D/lib/$dep" ]; then
        cp -f "$i" "$D/lib/"
    fi
done

# Libraries dependencies
LIB_DEPENDS=$(ldd $(find "$D/lib" -maxdepth 1 -type f) | grep /opt | awk '{print $3}' | sort -u)
for i in $LIB_DEPENDS;
do
    dep=$(basename "$i")
    if [ ! -f "$D/lib/$dep" ]; then
        cp -f "$i" "$D/lib/"
    fi
done

PYSIDE_DEPENDS=$(ldd $(find "$SDK/lib/python${PYVER}/site-packages/PySide2" -maxdepth 1 -type f -name "lib*.so*") | grep /opt | awk '{print $3}' | sort -u)
PYSIDE_DEPENDS+=$(ldd $(find "$SDK/lib/python${PYVER}/site-packages/shiboken2" -maxdepth 1 -type f -name "lib*.so*") | grep /opt | awk '{print $3}' | sort -u)
for i in $PYSIDE_DEPENDS; do
    dep=$(basename "$i")
    if [ ! -f "$D/lib/$dep" ]; then
        cp -f "$i" "$D/lib/"
    fi
done

#if [ "$COMPILE_TYPE" != "debug" ]; then
#    strip -s "$D/bin"/* &>/dev/null || true
#    strip -s "$D/lib"/* &>/dev/null || true
#    strip -s "$D/bin"/*/* &>/dev/null || true
#fi

# Archiving
pushd $D/..
rm -rf "$NATRON_BUILD_DIR/Natron.tar.xz"
tar cf "$NATRON_BUILD_DIR/Natron.tar" Natron-snapshot
#xz -T$(nproc) "$NATRON_BUILD_DIR/Natron.tar"
popd
