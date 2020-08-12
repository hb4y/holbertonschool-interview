#!/usr/bin/python3

def minOperations(n):
	number_op = 0
	number_chars = 1
	paste = 0
	if (n <= 1):
		return (number_op);
	
	while (number_chars != n):
		if (n % number_chars == 0):
			paste = number_chars
			number_chars = number_chars + paste
			number_op = number_op + 2
		else:
			number_chars = number_chars + paste
			number_op = number_op + 1
	return (number_op)