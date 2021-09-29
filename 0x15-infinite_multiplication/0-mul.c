#include <stdlib.h>
#include <stdio.h>

/**
 * _isnumber - check if number
 * @number: char to test
 * Return: 1 if number
 */
int _isnumber(char *number)
{
	int i;

	i = 0;

	while (*(number + i) != '\0')
	{

		if (*(number + i) < '0' || *(number + i) > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * str_lenght - length
 * @my_string: pointer to string
 * Return: string size
 */
int str_lenght(const char *my_string)
{
	int l = 0;

	while (*my_string != '\0')
	{l++;
		my_string++;
	}

	return (l);
}

/**
 * main - main
 * @argc: count
 * @argv: values
 * Return: 0 on sucess or 98
 */
int main(int argc, char *argv[])
{
	int po, r, l, f, last, i, j;
	int *acum;

	if (argc < 3 || argc > 3 || !(_isnumber(argv[1])) || !(_isnumber(argv[2])))
		puts("Error"), exit(98);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{printf("0\n");
		return (0);
	}
	f = str_lenght(argv[1]), last = str_lenght(argv[2]);
	l = f + last;
	acum = calloc(l, sizeof(int *));
	if (acum == NULL)
		puts("Error"), exit(98);
	for (i = (last - 1); i > -1; i--)
	{r = 0;
		for (j = (f - 1); j > -1; j--)
		{
			po = (argv[2][i] - '0') * (argv[1][j] - '0');
			r =  (po / 10);
			acum[(i + j) + 1] += (po % 10);
			if (acum[(i + j) + 1] > 9)
			{
				acum[i + j] += acum[(i + j) + 1] / 10;
				acum[(i + j) + 1] = acum[(i + j) + 1] % 10;
			}
			acum[(i + j)] += r;
		}
	}
	if (acum[0] == 0)
		i = 1;
	else
		i = 0;
	for (; i < l; i++)
		printf("%d", acum[i]);
	printf("\n");
	free(acum);
	return (0);
}
