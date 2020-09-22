#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    n_byte = 0
    for number in data:
        mask = 1 << 0b111
        if n_byte == 0:
            while mask & number:
                n_byte += 1
                mask = mask >> 1
            if n_byte == 0:
                continue
            if n_byte == 1 or n_byte > 4:
                return False
        else:
            if n_byte >> 6 != 0b10:
                return False
        n_byte -= 1
    return n_byte == 0
