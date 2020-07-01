# Build type can be RELEASE, SNAPSHOT, NATRON_CI, PLUGIN_CI
BUILD_TYPE=${BUILD_TYPE:-"SNAPSHOT"}

# The name identifying the project (e.g: natron_github_master)
BUILD_NAME=${BUILD_NAME:-"docker_build"}

# Where the final build artifacts (binaries) are stored
BUILD_ARCHIVE_DIRECTORY=${BUILD_ARCHIVE_DIRECTORY:-""}

# Set to 1 to also build a online installer for SNAPSHOT and RELEASE builds (only available for Windows and Linux).
WITH_ONLINE_INSTALLER=${WITH_ONLINE_INSTALLER:-""}

# The date at which the build started
CURRENT_DATE=${CURRENT_DATE:-"$(date +%Y%M%d)"}

# If set to 1, deb and rpm packages will never be built. Default is to build when NATRON_BUILD_CONFIG=STABLE.
DISABLE_RPM_DEB_PKGS=${DISABLE_RPM_DEB_PKGS:-""}

# If set to 1, a portable archive will not be built
DISABLE_PORTABLE_ARCHIVE=${DISABLE_PORTABLE_ARCHIVE:-""}

# This mode is useful when debuging scripts: it doesn't remove any cloned repo or binary so that we don't redo
# tasks that take time
DEBUG_SCRIPTS=${DEBUG_SCRIPTS:-""}

# The Natron license (either GPL or COMMERCIAL). When COMMERCIAL, GPL components are not included
NATRON_LICENSE=${NATRON_LICENSE:-"GPL"}
# The Natron build config (SNAPSHOT,ALPHA,BETA,RC,STABLE,CUSTOM)
NATRON_BUILD_CONFIG=${NATRON_BUILD_CONFIG:-"CUSTOM"}
NATRON_BUILD_NUMBER=${NATRON_BUILD_NUMBER:-""}
NATRON_CUSTOM_BUILD_USER_NAME=${NATRON_CUSTOM_BUILD_USER_NAME:-"docker"}

# If set to 1, natron will be built without crash reporting capabilities
DISABLE_BREAKPAD=${DISABLE_BREAKPAD:-""}


# Url of the git that triggered the build
GIT_TRIGGER_URL=${GIT_TRIGGER_URL:-""}
GIT_TRIGGER_BRANCH=${GIT_TRIGGER_BRANCH:-""}
GIT_TRIGGER_COMMIT=${GIT_TRIGGER_COMMIT:-""}

# Urls of the repositories to build
GIT_URL_NATRON=${GIT_URL_NATRON:-""}
GIT_URL_OPENFX_IO=${GIT_URL_OPENFX_IO:-""}
GIT_URL_OPENFX_MISC=${GIT_URL_OPENFX_MISC:-""}
GIT_URL_OPENFX_ARENA=${GIT_URL_OPENFX_ARENA:-""}
GIT_URL_OPENFX_GMIC=${GIT_URL_OPENFX_GMIC:-""}
GIT_URL_OPENFX_OPENCV=${GIT_URL_OPENFX_OPENCV:-""}

NATRON_GIT_BRANCH=${NATRON_GIT_BRANCH:-""}

OPENFX_IO_GIT_BRANCH=${OPENFX_IO_GIT_BRANCH:-""}
OPENFX_MISC_GIT_BRANCH=${OPENFX_MISC_GIT_BRANCH:-""}
OPENFX_ARENA_GIT_BRANCH=${OPENFX_ARENA_GIT_BRANCH:-""}
OPENFX_GMIC_GIT_BRANCH=${OPENFX_GMIC_GIT_BRANCH:-""}
OPENFX_OPENCV_GIT_BRANCH=${OPENFX_OPENCV_GIT_BRANCH:-""}


# Set by checkout-natron.sh
NATRON_GIT_COMMIT=${NATRON_GIT_COMMIT:-""}

NATRON_VERSION_MAJOR=${NATRON_VERSION_MAJOR:-""}
NATRON_VERSION_MINOR=${NATRON_VERSION_MINOR:-""}
NATRON_VERSION_REVISION=${NATRON_VERSION_REVISION:-""}

# Major.Minor
NATRON_VERSION_SHORT=${NATRON_VERSION_SHORT:-""}

# Major.Minor.Rev
NATRON_VERSION_FULL=${NATRON_VERSION_FULL:-""}

# Used to decorate installer name
NATRON_VERSION_STRING=${NATRON_VERSION_STRING:-""}

# Set by build-plugins.sh
OPENFX_IO_GIT_COMMIT=${OPENFX_IO_GIT_COMMIT:-""}
OPENFX_MISC_GIT_COMMIT=${OPENFX_MISC_GIT_COMMIT:-""}
OPENFX_ARENA_GIT_COMMIT=${OPENFX_ARENA_GIT_COMMIT:-""}
OPENFX_GMIC_GIT_COMMIT=${OPENFX_GMIC_GIT_COMMIT:-""}
OPENFX_OPENCV_GIT_COMMIT=${OPENFX_OPENCV_GIT_COMMIT:-""}


# Either [relwithdebinfo, release, debug]
COMPILE_TYPE=${COMPILE_TYPE:-"relwithdebinfo"}

# Extra qmake flags
NATRON_EXTRA_QMAKE_FLAGS=${NATRON_EXTRA_QMAKE_FLAGS:-""}

# Extra Python modules install script
EXTRA_PYTHON_MODULES_SCRIPT=${EXTRA_PYTHON_MODULES_SCRIPT:-""}

# OS name
PKGOS=${PKGOS:-""}

# 32, 64 or universal
BITS=${BITS:-"64"}

# Pretty architecture/platform identifier
PKGOS_BITS="$PKGOS-x86_${BITS}bit"


# Temporary directory where the binaries are built
TMP_PATH=${TMP_PATH:-""}

# The basename of the installer
INSTALLER_BASENAME=${INSTALLER_BASENAME:-""}

# Path where binaries are stored after compilation.
# The build-plugin and build-natron scripts copy binaries to this folder
# which is then read by build-$PKGOS-installer to produce the portable install directory
TMP_BINARIES_PATH=${TMP_BINARIES_PATH:-""}

# Directory name of the portable installation
PORTABLE_DIRNAME=${PORTABLE_DIRNAME:-""}

# Path of the portable installation where we can launch the unit tests
# in a safe environment
TMP_PORTABLE_DIR=${TMP_PORTABLE_DIR:-""}

# The name of the host where to upload the online installer. This will be used
# to configure the online installer to select the location where to check for updates.
REMOTE_URL=${REMOTE_URL:-""}

# The user that should connect to the REMOTE_URL when uploading with rsync
REMOTE_USER=${REMOTE_USER:-""}

# The prefix location on the server where to upload the artifacts, relative to
# REMOTE_USER@REMOTE_URL
REMOTE_PREFIX=${REMOTE_PREFIX:-""}
