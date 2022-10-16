#!/usr/bin/env python
import random

for filename in ['sudoku_solver/sudoku_solver.hpp']: # , 'sudoku_solver/sudoku_solver.cpp']:
    with open(filename) as file:
        lines = file.read().splitlines()

    percentage = 0.1
    k = int(len(lines) * percentage)

    random_lines = random.sample(lines, k)
    # print("\n".join(random_lines))

    with open(filename, 'w') as output_file:
        output_file.writelines(line + "\n"
                            for line in lines if line not in random_lines or line == '')