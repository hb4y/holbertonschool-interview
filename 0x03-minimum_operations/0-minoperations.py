#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste.
Given a number n, write a method that calculates
the fewest number of operations needed to result
in exactly n H characters in the file.
"""


def minOperations(n):
    number_op = 0
    number_chars = 1
    paste = 0
    if (n <= 1):
        return (number_op)

    while (number_chars != n):
        if (n % number_chars == 0):
            paste = number_chars
            number_chars = number_chars + paste
            number_op = number_op + 2
        else:
            number_chars = number_chars + paste
            number_op = number_op + 1
    return (number_op)
