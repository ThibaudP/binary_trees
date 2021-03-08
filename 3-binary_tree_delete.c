#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a whole binary tree
 * 
 * @parent: parent node of the node to create
 * @value: integer value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */

void binary_tree_insert_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
