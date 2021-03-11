#include "binary_trees.h"
/**
 * binary_tree_check - check if all values greater than a value
 *
 *@value: a value to compare
 *@tree: a pointer to the root node
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_check(const binary_tree_t *tree, int value)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if ((tree->n > value) || (tree->n < value))
	{
		left = binary_tree_check(tree->left, value);
		right = binary_tree_check(tree->right, value);
		if (left && right)
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((binary_tree_check(tree->left, tree->n)) &&
			(binary_tree_check(tree->right, tree->n)))
	{
		if ((tree->left == NULL) || (binary_tree_is_bst(tree->left)))
		{
			if ((tree->right == NULL) || (binary_tree_is_bst(tree->right)))
				return (1);
		}
	}
	return (0);
}
