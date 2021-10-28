#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins
needed to meet a given amount.
"""


def makeChange(coins, total):
    """
    Return: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1
    coins = sorted(coins)
    coins = coins[::-1]
    n_coins = 0
    left = total
    for c in coins:
        while (left - c >= 0):
            left = left - c
            n_coins = n_coins + 1
    if left != 0 and left - coins[-1] < 0:
        return -1

    return n_coins
