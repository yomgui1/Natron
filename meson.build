# Top meson build definition file
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
# To build natron from a cloned GIT repository:
#  1) install Docker on you system
#  2) create the development environment by running following script:
#    $ ./tools/docker/natron-sdk/build.sh
#  3) build the SDK:
#    $ docker exec -it natron-builder-qt4.run run.sh bash -c 'cd $NATRON_SRC_DIR/tools/jenkins && ./include/scripts/build-Linux-sdk.sh'
#     Let SDK build until obtaining "Natron SDK Done"
#  4) configure the build system of Natron (meson based):
#    $ docker exec -it natron-builder-qt4.run run.sh bash -c 'meson . $NATRON_SRC_DIR --buildtype release'
#  5) build Natron (ninja builder, configured by meson):
#    $ docker exec -it natron-builder-qt4.run run.sh ninja
#

project('Natron', ['cpp', 'c'],
		default_options: ['cpp_std=c++14', 'b_colorout=auto'])

########################
# Some system variables
#

cpp			= meson.get_compiler('cpp')
natron_sdk	= '/opt/Natron-sdk'
nproc		= run_command('nproc', '--ignore=1', check: true).stdout().strip()
make_jobs	= '-j'+nproc

message('Found '+nproc+' processors for build')

##############################
# Find dependencies and tools
#

qt4				= import('qt4')
qt4_dep			= dependency('qt4', modules: ['Core', 'Gui', 'Network', 'OpenGL'])
python_dep		= dependency('python')
threads_dep		= dependency('threads')
boost_dep		= dependency('boost', modules: ['serialization', 'thread'])
expat_dep		= dependency('expat')
cairo_dep		= dependency('cairo')
pixman1_dep		= dependency('pixman-1')
freetype2_dep	= dependency('freetype2')
fontconfig_dep	= dependency('fontconfig')
shiboken_dep	= dependency('shiboken')
pyside_dep		= dependency('pyside')
x11_dep			= cpp.find_library('X11')
dl_dep			= cpp.find_library('dl')

# Qt/Make tools
qmake			= find_program('qmake', dirs: natron_sdk/'qt4/bin')
qmake_cmd		= [qmake, '@INPUT@', '-o', '@OUTPUT@']
make_cmd		= ['make', make_jobs, '-C', '@OUTDIR@', '-f', '@PLAINNAME@']

############################
# Global compiler arguments
#

global_defines = []
foreach x : 'OFX_SUPPORTS_DIALOG OFX_EXTENSIONS_NUKE OFX_EXTENSIONS_TUTTLE OFX_EXTENSIONS_VEGAS OFX_SUPPORTS_PARAMETRIC OFX_EXTENSIONS_TUTTLE OFX_EXTENSIONS_NATRON OFX_EXTENSIONS_RESOLVE OFX_SUPPORTS_OPENGLRENDER OFX_SUPPORTS_MULTITHREAD QT_NO_CAST_FROM_ASCII NDEBUG NATRON_CONFIG_SNAPSHOT NATRON_BUILD_NUMBER=0 QT_NO_DEBUG QT_NO_KEYWORDS QT_OPENGL_LIB QT_GUI_LIB QT_NETWORK_LIB QT_CORE_LIB QT_SHARED ENFORCE_GCC8'.split()
  global_defines += '-D'+x
endforeach

global_warnings = [
  '-Wno-int-in-bool-context',
  '-Wno-deprecated-declarations',
  '-Wno-misleading-indentation',
]

add_project_arguments(global_defines, language: ['cpp', 'c'])
add_project_arguments(global_warnings, language: ['cpp', 'c'])

#######################
# Global include paths
#

incs = [ include_directories('.') ]

# PySide includes
pyside_inc_dir = pyside_dep.get_variable(pkgconfig: 'includedir')
incs += include_directories(pyside_inc_dir/'QtGui', pyside_inc_dir/'QtCore')

# External libraries includes
incs += include_directories('libs/OpenFX/include',
							'libs/OpenFX/HostSupport/include',
							'libs/OpenFX_extensions',
							'libs/SequenceParsing',
							'libs/Eigen3')



subdir('libs')
subdir('Engine')
subdir('Gui')
subdir('PythonBin')
subdir('App')


######################
# Installation script
#

package_script = files('tools/docker/packageNatron.sh')[0]
meson.add_install_script('@0@'.format(files('tools/docker/packageNatron.sh')[0]))
