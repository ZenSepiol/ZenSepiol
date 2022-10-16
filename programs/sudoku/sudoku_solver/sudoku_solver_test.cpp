#include "sudoku_solver.hpp"
#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("Sudoku", "[]")
{
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, //
                      {0, 0, 0, 0, 0, 3, 0, 8, 5}, //
                      {0, 0, 1, 0, 2, 0, 0, 0, 0}, //
                      {0, 0, 0, 5, 0, 7, 0, 0, 0}, //
                      {0, 0, 4, 0, 0, 0, 1, 0, 0}, //
                      {0, 9, 0, 0, 0, 0, 0, 0, 0}, //
                      {5, 0, 0, 0, 0, 0, 0, 7, 3}, //
                      {0, 0, 2, 0, 1, 0, 0, 0, 0}, //
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}};

    SudokuSolver solver;
    solver.Solve(grid);

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            std::cout << grid[row][col] << "  ";
        std::cout << std::endl;
    }

    int result[9][9] = {{9, 8, 7, 6, 5, 4, 3, 2, 1}, //
                        {2, 4, 6, 1, 7, 3, 9, 8, 5}, //
                        {3, 5, 1, 9, 2, 8, 7, 4, 6}, //
                        {1, 2, 8, 5, 3, 7, 6, 9, 4}, //
                        {6, 3, 4, 8, 9, 2, 1, 5, 7}, //
                        {7, 9, 5, 4, 6, 1, 8, 3, 2}, //
                        {5, 1, 9, 2, 8, 6, 4, 7, 3}, //
                        {4, 7, 2, 3, 1, 9, 5, 6, 8}, //
                        {8, 6, 3, 7, 4, 5, 2, 1, 9}};
    ;

    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
        {
            CAPTURE(row);
            CAPTURE(col);
            REQUIRE(grid[row][col] == result[row][col]);
        }
}