#include "lists.h"

/**
 * insert_node - insert the node in order
 * @head: pointer to head of list
 * @number: value of the node
 * Return: number of nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *current;
new = malloc(sizeof(listint_t));
if (!new)
	return (NULL);
new->n = number;
new->next = NULL;
if (!head || !(*head))
{
	*head = new;
	return (new);
}
if (new->n < (*head)->n)
{
	new->next = *head;
	*head = new;
	return (new);
}
for (current = *head; current->next; current = current->next)
{
	if (new->n < (current->next)->n)
	{
		new->next = current->next;
		current->next = new;
		return (new);
	}
}
current->next = new;
return (new);
}
