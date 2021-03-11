#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 *
 * @tree: pointer to root of BST
 * @value: value to look for
 *
 * Return: pointer to the found node if it exists, NULL otherwise
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	tmp = (bst_t *)tree;

	while (tmp)
	{
		if (tmp->n == value)
			return (tmp);
		if (tmp->n < value)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}

	return (NULL);
}
