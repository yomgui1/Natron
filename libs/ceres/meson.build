################################################################################
## ceres
################################################################################

ceres_setup_target = custom_target('ceres.mk',
								   input: 'ceres.pro',
								   output: 'ceres.mk',
								   command: qmake_cmd)

ceres_lib = custom_target('ceres',
 						  input: ceres_setup_target,
 						  output: 'libceres.a',
 						  command: make_cmd)

ceres_dep = declare_dependency(link_with: ceres_lib,
							   include_directories: include_directories('include'),
							   dependencies: [glog_dep])
