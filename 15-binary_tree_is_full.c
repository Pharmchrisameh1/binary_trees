#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full and 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_flag = 1;

	if (tree == NULL)
		return (0);
	/* leaf encountered */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* a node is found with only 1 child */
	if ((tree->left && !(tree->right)) ||
	    (tree->right && !(tree->left)))
		is_full_flag = 0;

	/* recursive calls to left and right sides with & operator */
	is_full_flag &= binary_tree_is_full(tree->left);
	is_full_flag &= binary_tree_is_full(tree->right);

	return (is_full_flag);
}
