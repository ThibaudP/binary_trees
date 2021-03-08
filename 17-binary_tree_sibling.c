#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a given node
 *
 * @node: a pointer to the node we want the sibling of
 *
 * Return: pointer to the sibling, or NULL if no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
