#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: the pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if (tree == NULL)
		return (NULL);
	newroot = tree->right;
	tree->right = newroot->left;
	newroot->left = tree;
	newroot->parent = tree->parent;
	if (newroot && newroot->parent)
	{
		if (newroot->parent->left == tree)
			newroot->parent->left = newroot;
		else
			newroot->parent->right = newroot;
	}
	tree->parent = newroot;
	if (tree->right)
		tree->right->parent = tree;
	return (newroot);
}
