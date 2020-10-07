#include "menger.h"

/**
 * _char - char to print by coordenate (' ' or '#').
 * @col: column.
 * @row: row.
 * Return: (' ' or '#')
 */
char _char(int col, int row)
{
	for (; col && row; col /= 3, row /= 3)
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
	return ('#');
}

/**
 * menger - https://en.wikipedia.org/wiki/Menger_sponge.
 * @level:  Sponge level.
 */
void menger(int level)
{
	int col, row, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (col = 0; col < size; col++)
		{
			for (row = 0; row < size; row++)
				putchar(_char(col, row));
			putchar('\n');
		}
	}
}
