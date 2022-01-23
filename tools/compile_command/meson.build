project('compile_commands', 'cpp')

incdir = include_directories('./dependency', './2nd_dependency')

files = files(
    'main.cpp', 
    'dependency/line.cpp'
)

executable('main', files, include_directories : incdir)
