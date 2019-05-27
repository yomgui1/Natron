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
#set -x

case "${1:-}" in
--qt4)
	QT4=1
	;;
*)
	# Defaults behavior is Qt5, PySide2 and Shiboken2
	QT4=0
	;;
esac

QT4=1

if [[ $QT4 == 1 ]]; then
	PYSIDEVER=
else
	PYSIDEVER=2
fi

D="$NATRON_BUILD_DIR/dist"
rm -rf $D

mkdir -p $D/{bin,lib,Plugins,docs/natron}
mkdir -p $D/Resources/{pixmaps,stylesheets}
mkdir -p $D/Resources/etc/fonts/conf.d

# Natron binaries
#cp "$NATRON_BUILD_DIR"/Tests/Tests $D/bin/
cp "$NATRON_BUILD_DIR"/App/Natron $D/bin/
#cp "$NATRON_BUILD_DIR"/Renderer/NatronRenderer $D/bin/
##cp "$NATRON_BUILD_DIR"/ProjectConverter/NatronProjectConverter $D/bin/
cp "$NATRON_BUILD_DIR"/PythonBin/natron-python $D/bin/

# Documentation
cp "$NATRON_SRC_DIR"/LICENSE.txt $D/docs/natron/

# Resources
cp "$NATRON_SRC_DIR"/Gui/Resources/Stylesheets/mainstyle.qss $D/Resources/stylesheets/
cp "$NATRON_SRC_DIR"/Gui/Resources/Images/natronIcon256_linux.png $D/Resources/pixmaps/
cp "$NATRON_SRC_DIR"/Gui/Resources/Images/natronProjectIcon_linux.png $D/Resources/pixmaps/
##cp "$NATRON_SRC_DIR"/Gui/Resources/etc/fonts/fonts.conf $D/Resources/etc/fonts/
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
if [[ $QT4 == 1 ]]; then
	QT_PLUGINS_DIR=$SDK/qt4/plugins/
else
	QT_PLUGINS_DIR=$SDK/plugins/
fi

for dir in $(ls "$QT_PLUGINS_DIR");
do
	cp -a "$QT_PLUGINS_DIR/$dir" $D/bin/
done

# Python
PYVER=2.7
PY_PKG_PATH="$D/lib/python${PYVER}/site-packages"
cp -a "$SDK/lib/python${PYVER}" "$D/lib/"

if [[ $QT4 == 1 ]]; then
	cp -a "$SDK/qt4/lib/python${PYVER}" "$D/lib/"
fi

rm -rf "${PY_PKG_PATH}/shiboken${PYSIDEVER}_"*
rm -rf "${PY_PKG_PATH}/pip"*
rm -rf "${PY_PKG_PATH}/setuptools"*
rm -rf "${PY_PKG_PATH}/pkg_resources"
rm -rf "$D/lib/python${PYVER}"/{test,config,config-"${PYVER}m"}

PYZIPFILE="$D/lib/python${PYVER/./}.zip"
if [[ ! -f "$PYZIPFILE" ]]; then
	pushd "$D/lib/python${PYVER}"
	zip -q -r -m "$PYZIPFILE" * -x site-packages\* lib-dynload\* lib2to3\* \
		lib-tk\* plat-linux2\* LICENSE.txt pdb.doc wsgiref.egg-info || true
	popd
fi

LD_LIBRARY_PATH="$SDK/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

# PySide/Shiboken
if [[ $QT4 == 1 ]]; then
	PYSIDE_PKG_BASE="$SDK/qt4/lib/python${PYVER}/site-packages"
	LD_LIBRARY_PATH="${PYSIDE_PKG_BASE}:${PYSIDE_PKG_BASE}/PySide${PYSIDEVER}${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
else
	LD_LIBRARY_PATH="${PY_PKG_PATH}/shiboken${PYSIDEVER}:${PY_PKG_PATH}/PySide${PYSIDEVER}${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
fi

# Binary Libraries
CORE_DEPENDS=$(ldd 2>/dev/null $(find "$D/bin" -type f) | grep /opt | awk '{print $3}' | sort -u)
for i in $CORE_DEPENDS;
do
    dep=$(basename "$i")
    if [ ! -f "$D/lib/$dep" ]; then
        cp -f "$i" "$D/lib/"
    fi
done

# Libraries dependencies
LIB_DEPENDS=$(ldd 2>/dev/null $(find "$D/lib" -maxdepth 1 -type f -a -! -name "*.zip") | grep /opt | awk '{print $3}' | sort -u)
for i in $LIB_DEPENDS;
do
    dep=$(basename "$i")
    if [ ! -f "$D/lib/$dep" ]; then
        cp -f "$i" "$D/lib/"
    fi
done

if [[ $QT4 == 1 ]]; then
	PYSIDE_DEPENDS=$(ldd 2>/dev/null  $(find "$SDK/qt4/lib/python${PYVER}/site-packages/PySide${PYSIDEVER}" -maxdepth 1 -type f -name "*.so") | grep /opt | awk '{print $3}' | sort -u)
	PYSIDE_DEPENDS+=$(ldd 2>/dev/null  "$SDK/qt4/lib/python${PYVER}/site-packages/shiboken.so" | grep /opt | awk '{print $3}' | sort -u)
else
	PYSIDE_DEPENDS=$(ldd 2>/dev/null  $(find "$SDK/lib/python${PYVER}/site-packages/PySide${PYSIDEVER}" -maxdepth 1 -type f -name "lib*.so*") | grep /opt | awk '{print $3}' | sort -u)
	PYSIDE_DEPENDS+=$(ldd 2>/dev/null  $(find "$SDK/lib/python${PYVER}/site-packages/shiboken${PYSIDEVER}" -maxdepth 1 -type f -name "lib*.so*") | grep /opt | awk '{print $3}' | sort -u)
fi
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
pushd $D/.. > /dev/null
rm -rf "$NATRON_BUILD_DIR/Natron.tar.xz"
tar cf "$NATRON_BUILD_DIR/Natron.tar" -P --transform="s|$D|Natron-snapshot|" $D
#xz -T$(nproc) "$NATRON_BUILD_DIR/Natron.tar"
popd > /dev/null

