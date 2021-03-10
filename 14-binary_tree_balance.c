#include "binary_trees.h"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * height_sub - measures the height of a sub-tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the height
 */
int height_sub(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (MAX(height_sub(tree->left), height_sub(tree->right)) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: if tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height_sub(tree->left) - height_sub(tree->right));
}
