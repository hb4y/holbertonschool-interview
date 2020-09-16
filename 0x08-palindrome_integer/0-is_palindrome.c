#include "palindrome.h"

/**
 * rev_number - reverse a number
 * @number: number to reverse
 * Return: a number reversed
 */
unsigned long rev_number(unsigned long number)
{
	unsigned long reversed = 0;
	unsigned long copy = number;

	while (copy != 0)
	{
		reversed = reversed * 10;
		reversed = reversed + copy % 10;
		copy = copy / 10;
	}
	return (reversed);
}

/**
 * is_palindrome - check if number is a palindrome
 * @n: number
 * Return: 0 if not palindrome, 1 if is a palindrome
 */
int is_palindrome(unsigned long n)
{
	return (1 ? n == rev_number(n) : 0);
}
