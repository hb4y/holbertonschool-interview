#include "binary_trees.h"

/**
 * sort_max_heap - sort max heap order
 * @new: Pointer to the new node
 * Return: pointer to the node
 */
heap_t *sort_max_heap(heap_t *new)
{
	int tmp;

	tmp = new->n;
	while (new->parent != NULL && new->parent->n < tmp)
	{
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * count_nodes - count nodes in heap
 * @root: Pointer to the root node
 * Return: number of nodes in the heap
 */
int count_nodes(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * heap_insert - Main funtion to insert in heap
 * @root: Pointer to the root node
 * @value: value of the node
 * Return: Pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *current;
	int insert_node, mask;

	insert_node = count_nodes(*root) + 1;
	mask = 0;
	current = *root;
	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);

	new->parent = *root;
	new->n = value;
	new->left = NULL, new->right = NULL;
	if (!root || !(*root))
		return (*root = new);
	for (; 1 << (mask + 1) <= insert_node; mask++)
		;
	mask--;
	for (; mask > 0; mask--)
	{
		if (insert_node & (1 << mask))
			current = current->right;
		else
			current = current->left;
	}
	if (insert_node & 1)
		current->right = new;
	else
		current->left = new;
	new->parent = current;
	return (sort_max_heap(new));
}
