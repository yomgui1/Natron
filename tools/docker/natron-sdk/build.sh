#!/bin/bash
##
# This file is part of Natron <https://natrongithub.github.io/>,
# Copyright 2019 Guillaume Roguez <yomgui1@gmail.com>
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
##

cd $(dirname "$0")

topsrc=$PWD/../../..
build_os=centos7
docker_image_name=natron/natronsdk-qt4
docker_container_name=natron-builder-qt4.run

# Prepare a development docker image
docker build -t $docker_image_name -f Dockerfile.${build_os}-qt4 .

# Run a docker instance with mounting some volume for loaded archives and build binaries,
# and execute the SDK build script
docker rm -f $docker_container_name 2>/dev/null
docker run -it --name $docker_container_name \
	   -v ${topsrc}:/opt/Natron-src:ro,Z \
	   -v natron-sdk-${build_os}:/opt/Natron-sdk \
	   -v natron-build-${build_os}:/opt/Natron-build \
	   -v natron-ofx-${build_os}:/usr/OFX \
	   -v natron-tarballs:/opt/Natron-tarballs \
	   $docker_image_name \
	   ./include/scripts/build-Linux-sdk.sh
