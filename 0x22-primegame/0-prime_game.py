#!/usr/bin/python3
"""
0x22. Prime Game
"""


def prime_or_not(n, numbers):
    """prime or not"""

    number = numbers[-1]

    if n > number:
        for i in range(number + 1, n + 1):
            if auxiliar(i):
                numbers.append(i)
            else:
                numbers.append(0)


def auxiliar(n):
    """+1 numbers"""

    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False

    return True


def isWinner(x, nums):
    """win"""

    player_arr = {"Maria": 0, "Ben": 0}
    numbers = [0, 0, 2]
    prime_or_not(max(nums), numbers)

    for round in range(x):
        total = sum((i != 0 and i <= nums[round])
                    for i in numbers[:nums[round] + 1])

        if (total % 2):
            player_win = "Maria"
        else:
            player_win = "Ben"
        if player_win:
            player_arr[player_win] += 1

    if player_arr["Maria"] > player_arr["Ben"]:
        return "Maria"
    if player_arr["Maria"] < player_arr["Ben"]:
        return "Ben"
    else:
        return None
