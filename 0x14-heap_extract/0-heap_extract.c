#include "binary_trees.h"

/**
 * rebuild - rebuild heap
 * @root: pointer to root
 */
void rebuild(binary_tree_t *root)
{
	binary_tree_t *node_c = NULL;
	int n = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			node_c = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				node_c = root->left;
			else
				node_c = root->right;
		}

		if (root->n >= node_c->n)
			break;

		n = root->n;

		root->n = node_c->n;

		node_c->n = n;

		root = node_c;
	}
}

/**
 * n_nodes - n nodes
 * @root: pointer to root
 * Return: n
 */
int n_nodes(heap_t *root)
{
	int h = 0, t = 0;

	if (!root)
		return (0);

	h = n_nodes(root->left);

	t = n_nodes(root->right);

	return (1 + h + t);
}

/**
 * get_last - last node
 * @root: pointer to root
 * Return: pointer to node
 */
binary_tree_t *get_last(heap_t *root)
{
	int n = 0, size = 0;
	binary_tree_t *last = NULL;

	size = n_nodes(root);

	for (n = 1; n <= size; n <<= 1)
		;
	n >>= 2;

	for (last = root; n > 0; n >>= 1)
	{
		if (size & n)
			last = last->right;
		else
			last = last->left;
	}

	return (last);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to root
 * Return: value
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last = NULL;
	binary_tree_t *first = NULL;
	int val = 0;

	if (!root || !*root)
		return (0);

	first = *root;
	if (!first->left && !first->right)
	{val = first->n;
		free(first);
		*root = NULL;
		return (val);
	}
	first = *root;
	val = first->n;
	last = get_last(*root);

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->left = first->left;
	last->right = first->right;
	last->parent = first->parent;

	if (first->left)
		first->left->parent = last;

	if (first->right)
		first->right->parent = last;

	*root = last;
	free(first);

	rebuild(*root);

	return (val);
}
