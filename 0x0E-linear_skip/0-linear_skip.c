#include "search.h"
/**
 * linear_skip - function that searches for a value
 * in a sorted skip list of integers.
 * @list: is a pointer to the head of the skip list to search in
 * @value:  value to search for
 * Return: pointer on success NULL on error
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp_list = list, *p_n_ex = NULL;

	if (!list)
		return (NULL);

	if (tmp_list->express && (tmp_list->index == tmp_list->express->index))
		return (printf("Value checked at index [%u] = [%d]\n",
					   (unsigned int)tmp_list->index, tmp_list->n),
				(tmp_list->n == value) ? tmp_list : NULL);
	while (tmp_list->express)
	{printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)tmp_list->express->index, tmp_list->express->n);
		if (value >= tmp_list->n && value <= tmp_list->express->n)
		{
			printf("Value found between indexes [%u] and [%u]\n",
				   (unsigned int)tmp_list->index, (unsigned int)tmp_list->express->index);
			break;
		}
		tmp_list = tmp_list->express;
	}
	if (!tmp_list->express)
	{
		p_n_ex = tmp_list;
		while (p_n_ex->next)
			p_n_ex = p_n_ex->next;
		printf("Value found between indexes [%u] and [%u]\n",
			   (unsigned int)tmp_list->index, (unsigned int)p_n_ex->index);
	}
	p_n_ex = tmp_list->express;
	while (tmp_list)
	{
		printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)tmp_list->index, tmp_list->n);
		if (tmp_list == p_n_ex || tmp_list->n == value)
			break;
		tmp_list = tmp_list->next;
	}
	if (!tmp_list || (tmp_list == p_n_ex && tmp_list->n != p_n_ex->n))
		return (NULL);
	return (tmp_list);
}
