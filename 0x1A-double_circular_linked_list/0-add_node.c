#include "list.h"

/**
 * n_node - new node
 * @str: string
 * Return: node or null
 */
List *n_node(char *str)
{
	List *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->str = strdup(str);
	node->prev = NULL;
	node->next = NULL;
	if (str && !node->str)
	{
		free(node);
		return (NULL);
	}

	return (node);
}


/**
 * add_node_end - append node
 * @list: list
 * @str: string
 * Return: pointer
 */
List *add_node_end(List **list, char *str)
{
	List *node = NULL;
	List *tail = NULL;
	List *head = NULL;

	if (!list)
		return (NULL);
	node = n_node(str);
	if (!node)
		return (NULL);
	head = *list;
	if (!head)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		tail = head->prev;
		node->next = head;
		tail->next = node;
		node->prev = tail;
		head->prev = node;
	}

	return (node);
}

/**
 * add_node_begin - add node
 * @list: list
 * @str: string
 * Return: pointer
 */
List *add_node_begin(List **list, char *str)
{
	List *node = NULL;

	node = add_node_end(list, str);
	if (!node)
		return (NULL);
	*list = node;

	return (node);
}
