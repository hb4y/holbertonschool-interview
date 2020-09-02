#!/usr/bin/python3
"""
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:

Total file size: File size: <total size>
where <total size> is the sum of all previous <file size> (see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear, don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order"""

import sys

def _print(file_size, status):
	print("File size: {}".format(file_size[0]))
	for key in sorted(status.keys()):
		if status[key] != 0:
			print("{}: {}".format(key, status[key]))

def parser(log, counter, file_size, status):
	if log[8].isdigit():
		file_size[0] += int(log[8])
	
	if log[7].isdigit():
		status[int(log[7])] += 1
	
	if counter[0] == 9:
		_print(file_size, status)
		counter[0] = 0
	else:
		counter[0] += 1

if __name__ == "__main__":
	counter = [0]
	file_size = [0]
	status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

	while True:
		try:
			log = input().split()
			parser(log, counter, file_size, status)
		except KeyboardInterrupt:
			pass
		finally:
			_print(file_size, status)
