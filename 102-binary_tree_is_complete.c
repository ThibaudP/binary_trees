#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * (= its number of nodes)
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: the size of the binary tree, or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * is_complete - Recursively checks if a binary tree is complete
 *
 * @tree: pointer to root node of a tree
 * @index: index of node (in flattened representation of the tree)
 * @nodes: number of nodes in the tree
 *
 * Return: 1 if complete, 0 if not or if tree is NULL
 */

int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: pointer to root node of a tree
 *
 * Return: 1 if complete, 0 if not or if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree)
		nodes = binary_tree_size(tree);
	if (nodes)
		return (is_complete(tree, 0, nodes));

	return (0);
}
