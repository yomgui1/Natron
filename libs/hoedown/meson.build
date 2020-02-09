################################################################################
## hoedown
################################################################################

hoedown_setup_target = custom_target('hoedown.mk',
									 input: 'hoedown.pro',
									 output: 'hoedown.mk',
									 command: qmake_cmd)

hoedown_lib = custom_target('hoedown',
 							input: hoedown_setup_target,
 							output: 'libhoedown.a',
 							command: make_cmd)

hoedown_dep = declare_dependency(link_with: hoedown_lib,
								 include_directories: include_directories('src'))

