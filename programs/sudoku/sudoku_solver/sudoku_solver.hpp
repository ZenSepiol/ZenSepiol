class SudokuSolver
{
  public:
    SudokuSolver() = default;

    // Solve the sudoku in place
    bool Solve(int grid[9][9])
    {
        // Find the first empty space
        int row = 0;
        int col = 0;
        bool empty_cell_present = FindFirstEmpty(grid, row, col);

        if (!empty_cell_present)
            return true;

        for (int new_number = 1; new_number <= 9; new_number++)
        {
            if (CheckIfBoardIsValid(grid, new_number, row, col))
            {
                grid[row][col] = new_number;
                if (Solve(grid))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    }

    bool CheckIfBoardIsValid(int grid[9][9], int new_number, int row, int col)
    {
        return
            NumberUniqueInRow(grid, new_number, row) &&
            NumberUniqueInCol(grid, new_number, col) &&
            NumberUniqueInSquare(grid, new_number, row, col);
    }

    bool NumberUniqueInRow(int grid[9][9], int new_number, int row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (grid[row][col] == new_number)
                return false;
        }
        return true;
    }

    bool NumberUniqueInCol(int grid[9][9], int new_number, int col)
    {
        for (int row = 0; row < 9; ++row)
        {
            if (grid[row][col] == new_number)
                return false;
        }
        return true;
    }

    bool NumberUniqueInSquare(int grid[9][9], int new_number, int row, int col)
    {
        int square_col_start = col - col % 3;
        int square_row_start = row - row % 3;

        for(int row_local = square_row_start; row_local < square_row_start + 3; ++row_local)
        {
            for(int col_local = square_col_start; col_local < square_col_start + 3; ++col_local)
            {
                if (grid[row_local][col_local] == new_number)
                    return false;
            }
        }
        return true;
    }

    bool FindFirstEmpty(int grid[9][9], int& row, int& col)
    {
        for (row = 0; row < 9; ++row)
        {
            for (col = 0; col < 9; ++col)
            {
                if (grid[row][col] == 0)
                    return true;
            }
        }
        return false;
    }
};
