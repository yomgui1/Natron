#!/bin/bash
## ***** BEGIN LICENSE BLOCK *****
## This file is part of Natron <https://natrongithub.github.io/>,
## Copyright (C) 2019 Guillaume Roguez
##
## Natron is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## Natron is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
## ***** END LICENSE BLOCK *****

if [ ! -d "$NATRON_SRC_DIR" ]; then
	echo "** NATRON_SRC_DIR environment variable must be set on Natron sources root directory **"
	exit -1
fi

if [ ! -d "$SDK" ]; then
	echo "** SDK environment variable must be set on Natron SDK root directory **"
	exit -1
fi

set -eu

# Shiboken2 uses clang to parse files
export LLVM_INSTALL_DIR="$NATRON_BUILD_DIR/libclang"
LD_LIBRARY_PATH="$LLVM_INSTALL_DIR/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

cd $NATRON_SRC_DIR
rm -rf Engine/NatronEngine_Qt5 Gui/NatronGui_Qt5

PYSIDE_PREFIX="$SDK/lib/python2.7/site-packages/PySide2/"

shiboken2="$SDK/lib/python2.7/site-packages/shiboken2_generator/shiboken2"
shiboken2_options="-std=c++14 --generator-set=shiboken --avoid-protected-hack --enable-pyside-extensions -T${PYSIDE_PREFIX}/typesystems"
shiboken2_includes="-I. -IGlobal -Ilibs/OpenFX/include -I${PYSIDE_PREFIX}/include $(pkg-config --cflags-only-I python2 Qt5Core Qt5Gui Qt5Widgets)"

$shiboken2 $shiboken2_options $shiboken2_includes --output-directory=Engine Engine/Pyside2_Engine_Python.h Engine/typesystem2_engine.xml

$shiboken2 $shiboken2_options $shiboken2_includes -IEngine -TEngine --output-directory=Gui Gui/Pyside2_Gui_Python.h Gui/typesystem2_natronGui.xml

./tools/utils/runPostShiboken2.sh

# Separation of Qt4/Qt5 wrappers
mv Engine/NatronEngine Engine/NatronEngine_Qt5
mv Gui/NatronGui Gui/NatronGui_Qt5
