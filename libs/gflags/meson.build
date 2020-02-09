################################################################################
## Google gflags
################################################################################

sources = [
	'src/gflags.cc',
	'src/gflags_completions.cc',
	'src/gflags_reporting.cc'
]

if build_machine.system() == 'windows'
  sources += 'src/windows_port.cc'
endif

gflags_lib = static_library('gflags', sources,
							include_directories: include_directories('src', 'src/gflags'),
							dependencies: threads_dep)

gflags_dep = declare_dependency(link_with: gflags_lib,
								include_directories: include_directories('src'))

