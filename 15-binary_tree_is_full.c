#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: a pointer to the root node
 *
 * Return: 1 is tree is full or it's a leaf, 0 if not full or tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (tree && tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	if (left == 0 || right == 0)
		return (0);

	return (1);
}
