################################################################################
## Google glog
################################################################################

glog_setup_target = custom_target('glog.mk',
								  input: 'glog.pro',
								  output: 'glog.mk',
								  command: qmake_cmd)

glog_lib = custom_target('glog',
 						 input: glog_setup_target,
 						 output: 'libglog.a',
 						 command: make_cmd)

glog_dep = declare_dependency(link_with: glog_lib,
							  include_directories: include_directories('src'),
								dependencies: [gflags_dep])
