################################################################################
## openmvg
################################################################################

openmvg_setup_target = custom_target('openmvg.mk',
									 input: 'openMVG.pro',
									 output: 'openmvg.mk',
									 command: qmake_cmd)

openmvg_lib = custom_target('openmvg',
 							input: openmvg_setup_target,
 							output: 'libopenMVG.a',
 							command: make_cmd)

openmvg_dep = declare_dependency(link_with: openmvg_lib,
								 include_directories: include_directories('.'),
								 dependencies: [ceres_dep, boost_dep])
