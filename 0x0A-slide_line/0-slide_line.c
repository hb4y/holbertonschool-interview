#include "slide_line.h"

/**
 * slide_left - Slides left.
 * @line: Array of int.
 * @size: Size of the array.
 */
void slide_left(int *line, size_t size)
{
	int prev, curr, i, j;

	i = j = 0;
	prev = curr = 0;

	for (; j < (int) size; j++)
	{
		curr = line[j];

		if (curr == 0)
			continue;
		if (prev == 0)
			prev = curr;
		else if (prev == curr)
		{
			line[i++] = curr << 1;
			prev = 0;
		}
		else
		{
			line[i++] = prev;
			prev = curr;
		}
	}
	if (prev)
		line[i++] = prev;
	for (;i < (int) size; i++)
		line[i] = 0;
}

/**
 * slide_right - Slides right.
 * @line: Array of int.
 * @size: Size of the array.
 */
void slide_right(int *line, size_t size)
{
	int prev, curr, i, j;

	prev = curr = 0;
	i = j = size - 1;

	for (; j >= 0; j--)
	{
		curr = line[j];
		if (curr == 0)
			continue;
		if (prev == 0)
			prev = curr;
		else if (prev == curr)
		{
			line[i--] = curr << 1;
			prev = 0;
		} else
		{
			line[i--] = prev;
			prev = curr;
		}
	}
	if (prev)
		line[i--] = prev;
	for (;i >= 0; i--)
		line[i] = 0;
}

/**
 * slide_line - Slide & merge it to the left or to the right.
 * @line: Array of int.
 * @size: Size of the array.
 * @direction: L to left R to right.
 * Return: 1 upon success, or 0 upon failure.
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	if (direction == SLIDE_RIGHT)
		slide_right(line, size);

	return (1);
}
