#include "binary_trees.h"

/**
 * tree_greater_than - Checks if all nodes of a tree is greater than a value
 *
 * @tree: root node of the tree
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */

int tree_greater_than(const binary_tree_t *tree, int val)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		left = tree_greater_than(tree->left, val);
		right = tree_greater_than(tree->right, val);
		if (left && right)
			return (1);
	}

	return (0);
}

/**
 * tree_lower_than - Checks if all nodes of a tree is lower than a value
 *
 * @tree: root node of the tree
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */

int tree_lower_than(const binary_tree_t *tree, int val)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		left = tree_lower_than(tree->left, val);
		right = tree_lower_than(tree->right, val);
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

	if ((tree_lower_than(tree->left, tree->n)) &&
	    (tree_greater_than(tree->right, tree->n)))
	{
		if ((tree->left == NULL) || (binary_tree_is_bst(tree->left)))
		{
			if ((tree->right == NULL) || (binary_tree_is_bst(tree->right)))
				return (1);
		}
	}
	return (0);
}
