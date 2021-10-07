#include "lists.h"

/**
 * find_listint_loop - find the loop
 * @head: pointer to head
 * Return: node or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *liebre; 
	listint_t *tortuga;

	tortuga = head;
	liebre = head;

	while (tortuga && liebre && liebre->next)
	{
		tortuga = tortuga->next;
		liebre = liebre->next->next;
		if (tortuga == liebre)
		{
			tortuga = head;
			while (tortuga && liebre)
			{
				if (tortuga == liebre)
					return (tortuga);
				tortuga = tortuga->next;
				liebre = liebre->next;
			}
		}
	}

	return (NULL);
}
