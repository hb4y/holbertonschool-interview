#!/usr/bin/python3
"""
Determines if all the boxes can be opened.
Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    openBoxes = set()
    openBoxes.add(0)

    def unlockBox(box):
        for key in box:
            if (key not in openBoxes) and (key < len(boxes)):
                openBoxes.add(key)
                unlockBox(boxes[key])
    if boxes:
        unlockBox(boxes[0])
    else:
        return True
    if len(openBoxes) == len(boxes):
        return True
    return False
