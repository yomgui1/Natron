################################################################################
## libtess
################################################################################

libtess_setup_target = custom_target('libtess.mk',
									 input: 'libtess.pro',
									 output: 'libtess.mk',
									 command: qmake_cmd)

libtess_lib = custom_target('libtess',
 							input: libtess_setup_target,
 							output: 'libtess.a',
 							command: make_cmd)

libtess_dep = declare_dependency(link_with: libtess_lib,
								 include_directories: include_directories('.'))
