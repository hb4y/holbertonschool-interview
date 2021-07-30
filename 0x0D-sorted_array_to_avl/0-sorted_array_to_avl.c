#include "binary_trees.h"

/**
 * new_alv_node - new node
 * @n: value to insert in the node
 * Return: NULL on fail Node on success
 */
avl_t *new_alv_node(int n)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * new_bt - new binary tree
 * @array: list to convert to b_tree
 * @initial: index of first
 * @last: index of last
 * @parent: pointer with the parent address
 * @pos: neutro left or right
 * Return: a pointer head of the tree in succes, NULL otherwise
 */
avl_t *new_bt(int *array, size_t initial, size_t last,
	avl_t *parent, char pos)
{
	avl_t *new_node = NULL, *last_node = NULL;

	if (last - initial > 1)
	{
		new_node = new_alv_node(array[(int)((last + initial) / 2) - 1]);
		new_node->parent = parent;
		if (pos == 'l')
			parent->left = new_node;
		else if (pos == 'r')
			parent->right = new_node;
		new_bt(array, initial, (int)((last + initial) / 2) - 1, new_node, 'l');
		new_bt(array, (int)((last + initial) / 2) + 1, last, new_node, 'r');
	}
	else if (last - initial == 1)
	{
		new_node = new_alv_node(array[last - 1]);
		last_node = new_alv_node(array[initial - 1]);
		if (pos == 'l')
		{
			parent->left = last_node, last_node->parent = parent;
			new_node->parent = last_node, last_node->right = new_node;
		}
		else if (pos == 'r')
		{
			parent->right = last_node, last_node->parent = parent;
			new_node->parent = last_node, last_node->right = new_node;
		}
	}
	else
	{
		new_node = new_alv_node(array[last - 1]);
		new_node->parent = parent;
		if (pos == 'l')
			parent->left = new_node;
		else if (pos == 'r')
			parent->right = new_node;
	}
	return (new_node);
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL, *last_node = NULL;

	if (!array || size == 0)
		return (NULL);
	if (size == 1)
	{
		new_node = new_alv_node(array[0]);
		return (new_node);
	}
	if (size == 2)
	{
		new_node = new_alv_node(array[1]);
		last_node = new_alv_node(array[0]);
		last_node->right = new_node, new_node->parent = last_node;
		return (last_node);
	}
	return (new_bt(array, 1, size, NULL, 'n'));
}
