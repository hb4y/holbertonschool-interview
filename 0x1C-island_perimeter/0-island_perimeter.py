#!/usr/bin/python3
"""
0x1C. Island Perimeter
"""


def island_perimeter(grid):
    """
     returns the perimeter of the island described in grid
    """
    is_per = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):

            if grid[row][col] == 1:

                if row == 0 or grid[row - 1][col] == 0:
                    is_per += 1
                if col == 0 or grid[row][col - 1] == 0:
                    is_per += 1
                if row == len(grid) - 1 or grid[row + 1][col] == 0:
                    is_per += 1
                if col == len(grid[row]) - 1 or grid[row][col + 1] == 0:
                    is_per += 1

    return (is_per)
