#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a whole binary tree
 *
 * @tree: root node of the tree to delete
 *
 * Return: a pointer to the new node, or NULL on failure
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
