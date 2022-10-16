project('template', 'cpp')

incdir = include_directories('')

catch_lib = subproject('catch2').get_variable('catch2_dep')

app_files = files(
    'main.cpp'
)

subdir('sudoku_solver')

# executable('app', app_files, include_directories : incdir, dependencies : [] )