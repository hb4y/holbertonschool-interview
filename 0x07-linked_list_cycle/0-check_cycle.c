#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - check if a list have a cicle
 * @list: pointer to list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (!list || !(list->next))
		return (0);

	fast = list;
	slow = list;

	while (slow->next && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
