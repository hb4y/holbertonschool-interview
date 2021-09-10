#!/usr/bin/python3
"""
Given a list of non-negative integers representing the
heights of walls with unit width 1, as if viewing the
cross-section of a relief map, calculate how many square
units of water will be retained after it rains.
"""


def rain(walls):
    """
    How many square units of water will be retained after it rains.
    """
    n = len(walls)

    if n == 0:
        return 0

    l = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        l = l + (min(left, right) - walls[i])

    return l
