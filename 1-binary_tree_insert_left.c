#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node to the left of the binary tree
 * If the parent already has a left child, the new node replaces it and
 * drops the preexisting left child to be a left child of the new node
 * 
 * @parent: parent node of the node to create
 * @value: integer value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);
	left_child = binary_tree_node(parent, value);
	
	if (left_child == NULL)
		return (NULL);
	
	left_child->left = parent->left;

	if (left_child->left != NULL)
		left_child->left->parent = left_child;
	
	parent->left = left_child;

	return (left_child);
}
