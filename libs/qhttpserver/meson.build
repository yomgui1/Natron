################################################################################
## qhttpserver
################################################################################

qhttpserver_setup_target = custom_target('qhttpserver.mk',
										 input: 'qhttpserver.pro',
										 output: 'qhttpserver.mk',
										 command: qmake_cmd)

qhttpserver_lib = custom_target('qhttpserver',
 								input: qhttpserver_setup_target,
 								output: 'libqhttpserver.a',
 								command: make_cmd)

qhttpserver_dep = declare_dependency(link_with: qhttpserver_lib,
									 include_directories: include_directories('src'))
