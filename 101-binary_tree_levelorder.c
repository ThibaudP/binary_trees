#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node
 *
 * Return: height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right, left;

	if (!tree || (tree && tree->left == NULL && tree->right == NULL))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left >= right)
		return (left + 1);

	return (right + 1);
}
/**
 * binary_tree_level - execute a func on a specific level
 *
 * @tree: the root of the tree
 * @level: the level of the tree to use on it a func
 * @func: function to use
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree,
		size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a bt using level-order traversal
 * @tree: root node of the tree to traverse
 * @func: function to call for each node
 * If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, l;

	if ((tree == NULL) || (func == NULL))
		return;

	h = binary_tree_height(tree);

	for (l = 0; l <= h; l++)
		binary_tree_level(tree, l, func);
}
