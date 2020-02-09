#!/bin/bash
#
####
# Copyright (C) 2020 Guillaume Roguez
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
####
#
# Authors: 2020 - Guillaume Roguez <yomgui1@gmail.com>
#
# Script file to create suitable Natron SDK environment
#

set -eu -o pipefail

cd $(dirname "$0")

topsrc=${PWD}/../../..
if [ ! -f "${topsrc}/tools/docker/natron-sdk/build.sh" ]; then
	echo "Seems we're not located at the expected place."
	echo "Be sure to have obtained sources from official place."
	exit 1
fi

build_os=centos7
docker_image_name=natron/natronsdk-qt4
docker_container_name=natron-builder-qt4.run
dockerfile=Dockerfile.${build_os}-qt4

# Build the development docker image
docker build -t $docker_image_name -f $dockerfile .

# Run a docker container with mounting some volume for loaded archives and build binaries,
# and execute the SDK build script
! docker rm -f $docker_container_name 2>/dev/null
docker run -td --name $docker_container_name \
	   -v ${topsrc}:/opt/Natron-src:ro,Z \
	   -v natron-sdk-${build_os}:/opt/Natron-sdk \
	   -v natron-build-${build_os}:/opt/Natron-build \
	   -v natron-ofx-${build_os}:/usr/OFX \
	   -v natron-tarballs:/opt/Natron-tarballs \
	   $docker_image_name
