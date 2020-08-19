#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - prints the array
 * @grid1: 3x3 array to print
 */
void print_grid(int grid1[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * unstable_grid - if unstable
 * @grid1: 3x3 array to check
 * Return: if unstable 1
 */
int unstable_grid(int grid1[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (1);
	return (0);
}

/**
 * sandpiles_sum - computes the final stable sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}

	while (unstable_grid(grid1))
	{
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (i > 0)
						grid2[i - 1][j] += 1;
					if (j > 0)
						grid2[i][j - 1] += 1;
					if (i < 2)
						grid2[i + 1][j] += 1;
					if (j < 2)
						grid2[i][j + 1] += 1;
					grid1[i][j] -= 4;
				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{	grid1[i][j] += grid2[i][j];
				grid2[i][j] = 0;
			}
		}
	}
}
