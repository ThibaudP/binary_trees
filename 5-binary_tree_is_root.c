#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of a binary tree
 *
 * @node: the node to check the rootness of
 *
 * Return: 1 if node is root, 0 if it isn't
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
