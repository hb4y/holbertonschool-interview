#!/usr/bin/python3
"""
Determines if all the boxes can be opened.
Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    openBoxes = [0]

    if boxes and len(boxes) > 0:
        for openBox in openBoxes:
            for key in boxes[openBox]:
                if (key not in openBoxes) and (key < len(boxes)):
                    openBoxes.append(key)
                if len(openBoxes) == len(boxes):
                    return True
    return False
