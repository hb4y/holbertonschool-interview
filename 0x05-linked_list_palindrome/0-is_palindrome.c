#include "lists.h"

/**
 * reverse - reverse a listint_t list
 * @head: pointer to list
 * Return: pointer to the new head
 */
listint_t *reverse(listint_t *head)
{
	listint_t *prev, *next;

	prev = NULL;
	next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * is_palindrome - check if listint_t is palindrome
 * @head: pointer to list
 * Return: 0 is not palindrome 1 if palimdrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast;

	slow = *head;
	fast = *head;

	if (!head || !(*head))
		return (1);

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	slow = reverse(slow);
	fast = *head;

	while (slow)
	{
		if (slow->n != fast->n)
			return (0);
		slow = slow->next;
		fast = fast->next;
	}
	return (1);
}
