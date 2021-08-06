#!/usr/bin/python3

"""
The N queens puzzle:

Challenge of placing N non-attacking queens on an N×N chessboard.

Solves the N queens problem.
"""

import sys

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    try:
        n_queen = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)

    if n_queen < 4:
        print('N must be at least 4')
        sys.exit(1)

    chest_board = [[0 for col in range(n_queen)] for row in range(n_queen)]
    def main():
        b = [[0 for j in range(n_queen)] for i in range(n_queen)]
        recursive_func(b, 0)
        return
    def recursive_func(b, c):
        if (c == n_queen):
            solution(b)
            return True
        ret = False
        for i in range(n_queen):
            if (validate_pos(b, i, c)):
                b[i][c] = 1
                ret = recursive_func(b, c + 1) or ret
                b[i][c] = 0
        return ret

    def validate_pos(b, r, c):
        for i in range(c):
            if (b[r][i]):
                return False
        i = r
        j = c
        while i >= 0 and j >= 0:
            if(b[i][j]):
                return False
            i = i - 1
            j = j - 1
        i = r
        j = c
        while j >= 0 and i < n_queen:
            if(b[i][j]):
                return False
            i = i + 1
            j = j - 1
        return True
    def solution(b):
        solve = []
        for i in range(n_queen):
            for j in range(n_queen):
                if(b[i][j] == 1):
                    solve.append([i, j])
        print(solve)
        solve.clear()
    main()
