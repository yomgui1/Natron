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

extras_build_flags="$@"

. common.sh
LOGDIR=$NATRON_BUILD_DIR/log-natron

setup_natron() {
	echo "=== Setup Natron"
	if [[ -f "$NATRON_BUILD_DIR"/natron/Makefile ]]; then
	   echo " -- Nothing to do --"
	else
		[ -d "$NATRON_BUILD_DIR"/natron ] || mkdir -p "$NATRON_BUILD_DIR"/natron
		export PYTHONHOME=$SDK
		cd "$NATRON_BUILD_DIR"/natron
		start_stop_command "QMake" '$SDK/bin/qmake -r PREFIX="$SDK/Natron" \
				   		   CONFIG+="enforce-gcc8 c++11 debug enable-cairo custombuild" \
				   		   BUILD_USER_NAME="${BUILD_USER_NAME:-docker}" \
				   		   $NATRON_SRC_DIR'
	fi
	echo
}

build_natron() {
	echo "=== Build Natron"
	cd $NATRON_BUILD_DIR/natron
	for pkg in $(ls -1 libs);
	do
		start_stop_command "libs-$pkg" make -C "libs/$pkg" $extras_build_flags
	done
	for pkg in Engine Gui Serialization HostSupport ProjectConverter PythonBin App Renderer Tests;
	do
		start_stop_command "$pkg" make -C "$pkg" $extras_build_flags
	done
	echo
}

package_natron() {
	echo "=== Packaging"
	start_stop_command "packaging" $NATRON_SRC_DIR/tools/docker/scripts/packageNatron.sh
	echo
}

process() {
	setup_natron
	build_natron
	package_natron
}

main
