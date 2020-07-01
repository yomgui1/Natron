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

SCRIPT_ARGUMENTS="$@"

. common.sh
LOGDIR=$NATRON_BUILD_DIR/log-sdk

ALL_PACKAGES=(zlib bzip2 expat ffi fontconfig freetype2 libxml2 harfbuzz libxslt \
				   openjpeg png libtiff openssl pixman cairo python2 glib \
				   ilmbase openexr boost dbus qt qtsvg pyside2 oiio ocio)

setup() {
	echo -n "=== Setup 3rd-party libraries build system"
	cd $NATRON_BUILD_DIR
	$NATRON_SRC_DIR/Natron-Deps/bootstrap 1>/dev/null 2>&1 --prefix=$SDK --tarballs=$NATRON_TARBALLS --disable-oiio --disable-ocio && echo " - ok" || (echo " - FAILED"; exit 1)
}

check_setup() {
	[ -f "$NATRON_BUILD_DIR/config.mak" -a -e "$NATRON_BUILD_DIR/Makefile" ] || setup
}

download_clang() {
		echo "=== Downloading clang"
		wget -O "$clang_archive" "http://download.qt.io/development_releases/prebuilt/libclang/libclang-release_80-based-linux-Rhel7.2-gcc5.3-x86_64.7z"
		echo
}

install_clang() {
	local clang_archive="$NATRON_TARBALLS/libclang-release_80-based-linux-Rhel7.2-gcc5.3-x86_64.7z"

	# Install clang 8 pre-build
	if [[ ! -e "$LLVM_INSTALL_DIR/bin/clang" ]]; then
		if [[ ! -f "$clang_archive" ]]; then
			download_clang "$clang_archive"
		fi

		echo "=== Uncompress clang archive"
		7z x -o"$NATRON_BUILD_DIR" "$clang_archive"
		echo
	fi
}

build_sdk() {
	echo "=== Build SDK"
	cd $NATRON_BUILD_DIR
	for pkg in $BUILD_PACKAGES; do
		start_stop_command $pkg make .$pkg $EXTRA_COMMANDS
	done
	echo
}

parse_arguments() {
	BUILD_PACKAGES=${ALL_PACKAGES[@]}
	EXTRA_COMMANDS=$*

	if [[ $# -ge 1 ]]; then
		case "$1" in
		setup)
			install_clang
			setup
			exit 0
			;;
		build)
			if [[ ! $# -eq 1 ]]; then
				EXTRA_COMMANDS=${*:3}
				BUILD_PACKAGES=$2
			else
				EXTRA_COMMANDS=${*:2}
			fi
			;;
		clean)
			if [[ $# -eq 1 ]]; then
				rm -rf "$NATRON_BUILD_DIR/*"
			else
				dirs=${*:2}
				echo "Cleaning $dirs"
				rm -rf "$NATRON_BUILD_DIR/$dirs"
			fi
			exit 0
			;;
		esac
	fi
}

process() {
	parse_arguments $SCRIPT_ARGUMENTS
	install_clang
	check_setup
	build_sdk 
}

main
