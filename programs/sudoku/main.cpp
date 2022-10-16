#include "sudoku_solver/sudoku_solver.hpp"

int main(int argc, char const *argv[])
{
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}}; 

    SudokuSolver solver(10);
    // solver.solve();
    
    return 0;
}
