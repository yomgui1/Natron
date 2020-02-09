################################################################################
## PythonBin
################################################################################

sources = [
  'python_main.cpp',
  '../Global/FStreamsSupport.cpp',
  '../Global/PythonUtils.cpp',
  '../Global/ProcInfo.cpp',
  '../Global/StrUtils.cpp',
]

exe = executable('natron-python',
				 sources,
				 include_directories: incs,
				 build_rpath: '$ORIGIN/../lib',
				 dependencies: [python_dep, qt4_dep])

test('mytest', exe, args: '--help')
