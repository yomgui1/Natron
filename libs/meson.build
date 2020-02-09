subdir('gflags')
subdir('glog')
subdir('ceres')
subdir('libmv')
subdir('openMVG')
subdir('qhttpserver')
subdir('hoedown')
subdir('libtess')

################################################################################
## HostSupport
################################################################################

sources = [
  'OpenFX/HostSupport/src/ofxhBinary.cpp',
  'OpenFX/HostSupport/src/ofxhClip.cpp',
  'OpenFX/HostSupport/src/ofxhHost.cpp',
  'OpenFX/HostSupport/src/ofxhImageEffect.cpp',
  'OpenFX/HostSupport/src/ofxhImageEffectAPI.cpp',
  'OpenFX/HostSupport/src/ofxhInteract.cpp',
  'OpenFX/HostSupport/src/ofxhMemory.cpp',
  'OpenFX/HostSupport/src/ofxhParam.cpp',
  'OpenFX/HostSupport/src/ofxhPluginAPICache.cpp',
  'OpenFX/HostSupport/src/ofxhPluginCache.cpp',
  'OpenFX/HostSupport/src/ofxhPropertySuite.cpp',
  'OpenFX/HostSupport/src/ofxhUtilities.cpp',
  'OpenFX_extensions/ofxhParametricParam.cpp',
]

HostSupport_lib = static_library('HostSupport',
								 sources,
								 include_directories: incs)

HostSupport_dep = declare_dependency(link_with: HostSupport_lib)
