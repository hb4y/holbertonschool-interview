#!/usr/bin/python3

"""
The N queens puzzle is the challenge of placing
N non-attacking queens on an N×N chessboard.
"""

import sys

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    try:
        n_qns = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)

    if n_qns < 4:
        print('N must be at least 4')
        sys.exit(1)

    chess_board = [[0 for col in range(n_qns)] for row in range(n_qns)]

    def main():
        aux_b = [[0 for j in range(n_qns)] for i in range(n_qns)]
        recursive_func(aux_b, 0)
        return

    def recursive_func(aux_b, aux_c):
        if (aux_c == n_qns):
            solution(aux_b)

            return True
        ret = False
        for i in range(n_qns):
            if (validate_pos(aux_b, i, aux_c)):
                aux_b[i][aux_c] = 1
                ret = recursive_func(aux_b, aux_c + 1) or ret
                aux_b[i][aux_c] = 0

        return ret

    def validate_pos(aux_b, r, aux_c):
        for i in range(aux_c):
            if (aux_b[r][i]):
                return False

        i = r
        j = aux_c
        while i >= 0 and j >= 0:
            if(aux_b[i][j]):
                return False

            i = i - 1
            j = j - 1
        i = r
        j = aux_c
        while j >= 0 and i < n_qns:
            if(aux_b[i][j]):
                return False
            i = i + 1
            j = j - 1
        return True

    def solution(aux_b):
        solve = []
        for i in range(n_qns):
            for j in range(n_qns):
                if(aux_b[i][j] == 1):
                    solve.append([i, j])
        print(solve)
        solve.clear()
    main()
