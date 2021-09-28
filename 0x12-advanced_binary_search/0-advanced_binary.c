#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: arr of values
 * @size: size
 * @value: value to find in arr
 * Return: pos on success or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int head = 0, tail = size - 1;

	if (!array || size == 0)
		return (-1);

	return (b_search(array, head, tail, value));

}

/**
 * b_search - Binary search
 * @array: Array to make search
 * @first: First position of @array
 * @last: Last position of @array
 * @value: Value toi find
 * Return: pos or -1
 */
int b_search(int *array, int first, int last, int value)
{
	int m = (first + last) / 2;

	if (first > last)
		return (-1);

	print_array(array, first, last);

	if (array[m] < value)
		return (b_search(array, m + 1, last, value));
	else if (array[m] >= value)
		last = m;

	if (array[first] == value && first == m)
		return (first);

	return (b_search(array, first, last, value));
}

/**
 * print_array - print
 * @array: arr
 * @head: head
 * @tail: tail
 */
void print_array(int *array, int head, int tail)
{
	int iterator;

	printf("Searching in array: ");
	for (iterator = head; iterator <= tail; iterator++)
	{
		if (iterator != head)
			printf(", ");
		printf("%d", array[iterator]);
	}
	putchar('\n');
}
