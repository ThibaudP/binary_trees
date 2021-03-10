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
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: a pointer to the root node of the tree to check
  *
  * Return: if tree is NULL, return 0
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

/*if leaf node*/
	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);
/*if node and one child is empty*/
	if ((tree->left == NULL) || (tree->right == NULL))
		return (0);

	if (height_sub(tree->left) != height_sub(tree->right))
		return (0);

	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
