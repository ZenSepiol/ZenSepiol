
sudoku_solver_files = files(
    'sudoku_solver_test.cpp',
    'sudoku_solver_test_main.cpp'
)

sudoku_solver_test = executable('sudoku_solver_test', sudoku_solver_files, include_directories : incdir, dependencies : [catch_lib])
test('sudoku_solver_test', sudoku_solver_test)