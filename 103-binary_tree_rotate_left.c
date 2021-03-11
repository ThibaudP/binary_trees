#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv1, *piv2;

	if (tree == NULL)
		return (NULL);

	piv1 = tree->parent;
	piv2 = tree->right;
	tree->right = piv2->left;

	if (piv2->left != NULL)
		piv2->left->parent = tree;

	piv2->left = tree;
	tree->parent = piv2;
	piv2->parent = piv1;

	if (piv1 != NULL)
	{
		if (piv1->right == tree)
			piv1->right = piv2;
		else
			piv1->left = piv2;
	}
	return (piv2);
}
