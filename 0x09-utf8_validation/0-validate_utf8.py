#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Pythonistic solution
    """
    try:
        bytes(number & 0xFF for number in data).decode()
        return True
    except UnicodeDecodeError:
        return False
