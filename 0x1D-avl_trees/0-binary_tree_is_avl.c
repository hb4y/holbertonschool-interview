#include "binary_trees.h"

/**
 * binary_tree_is_avl - binary_tree_is_avl
 * @tree: pointer
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h;

	if (!tree)
		return (0);

	return (check_a(tree, INT_MIN, INT_MAX, &h));
}

/**
 * check_a - avl?
 * @tree: pointer
 * @min: min
 * @max: max
 * @h: height
 * Return: 1 or 0
 */
int check_a(const binary_tree_t *tree, int min, int max, int *h)
{
	int h1 = 0, h2 = 0;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!check_a(tree->left, min, tree->n, &h1) ||
		!check_a(tree->right, tree->n, max, &h2))
		return (0);
	*h = MAX(h1, h2) + 1;

	return (ABS(h1 - h2) <= 1);
}
