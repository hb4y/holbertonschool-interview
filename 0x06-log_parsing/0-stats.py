#!/usr/bin/python3
"""
Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C), print.
Total file size: File size: <total size>
format: <status code>: <number>
"""

import sys


def _print(file_size, status):
    print("File size: {}".format(file_size[0]))
    for key in sorted(status.keys()):
        if status[key] != 0:
            print("{}: {}".format(key, status[key]))


def parser(log, counter, file_size, status):
    try:
        if log[8].isdigit():
            file_size[0] += int(log[8])

        if log[7].isdigit():
            status[int(log[7])] += 1

        if counter[0] == 9:
            _print(file_size, status)
            counter[0] = 0
        else:
            counter[0] += 1
    except:
        pass

if __name__ == "__main__":
    counter = [0]
    file_size = [0]
    status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    while True:
        try:
            log = input().split()
            parser(log, counter, file_size, status)
        except (KeyboardInterrupt, EOFError):
            _print(file_size, status)
            exit()
