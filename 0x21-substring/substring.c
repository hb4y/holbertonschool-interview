#include "substring.h"

/**
 * is_in - is in array
 * @arr: ints
 * @len: len
 * @val: value
 * Return: 0 if is in
 */
int is_in(int *arr, int len, int val)
{
	int i = 0;


	for (i = 0; i < len; i++)
	{
		if (arr[i] == val)
			return (0);
	}

	return (1);
}

/**
 * match - substr
 * @str: str
 * @arr: arr
 * Return: 1 if true
 */
int match(char const *str, char const *arr)
{
	int i = 0;

	for (i = 0; *(arr + i) != '\0'; i++)
	{
		if (*(str + i) != *(arr + i))
			return (0);
	}

	return (1);
}

/**
 * complete - find
 * @s: str
 * @arr: arr
 * @n: len
 * @len: len
 * Return: 1 if match
 */
int complete(char const *s, char const **arr, int n, int len)
{
	int *end;
	int end_len = 0;
	int f = 0;
	int m = 1;
	int j, k, l;
	int no;

	end = malloc(sizeof(int) * n);

	for (l = 0; l < n; l++)
		end[l] = -1;

	for (j = 0; j < n; j++)
	{
		f = 0;
		for (k = 0; k < n; k++)
		{
			no = is_in(end, end_len, k);
			if (no && match((s + (j * len)), arr[k]))
			{
				end[end_len] = k;
				end_len++;
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			m = 0;
			break;
		}
	}

	free(end);

	return (m);
}

/**
 * find_substring - find
 * @s: str
 * @words: arr
 * @nb_words: n words
 * @n: n
 * Return: substr or string
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *r;
	int str_len = 0;
	int w_len = 0;
	int i;

	*n = 0;
	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		str_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		w_len++;

	r = malloc(sizeof(int) * str_len);
	if (r == NULL)
		return (NULL);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (complete(s + i, words, nb_words, w_len))
		{
			r[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(r);
		return (NULL);
	}

	return (r);
}
