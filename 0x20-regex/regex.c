#include "regex.h"

/**
 * regex_match -  regex
 * @str: str
 * @pattern: pattern
 * Return: 1 if match
 */
int regex_match(char const *str, char const *pattern)
{
	int aux = 0;

	if (*str == '\0' && *pattern == '\0')
	{
		return (1);
	}

	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));

	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			aux = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || aux);
	}

	return (0);
}
