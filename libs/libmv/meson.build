################################################################################
## libmv
################################################################################

libmv_setup_target = custom_target('libmv.mk',
								   input: 'libmv.pro',
								   output: 'libmv.mk',
								   command: qmake_cmd)

libmv_lib = custom_target('libmv',
 						  input: libmv_setup_target,
 						  output: 'libLibMV.a',
 						  command: make_cmd)

libmv_dep = declare_dependency(link_with: libmv_lib,
							   include_directories: include_directories('.'),
							   link_args: ['-fopenmp'],
							   dependencies: [ceres_dep])
