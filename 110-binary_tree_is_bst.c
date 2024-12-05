#include "binary_trees.h"

/**
 * get_max - get the maximum value of a BST. (very right node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 *
 * Return: the maximum value.
 */
int get_max(const binary_tree_t *tree)
{
	int max_val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	while (cursor->right)
		cursor = cursor->right;
	max_val = cursor->n;
	return (max_val);
}

/**
 * get_min - get the minimum value of a BST. (very left node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 *
 * Return: the minimum value.
 */
int get_min(const binary_tree_t *tree)
{
	int min_val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	while (cursor->left)
		cursor = cursor->left;
	min_val = cursor->n;
	return (min_val);
}

/**
 * is_bst - checks if a valid (NON-NULL) tree is a BST.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid BST and 0 otherwise.
 */
int is_bst(const binary_tree_t *tree)
{
	int bts_flag = 1, min_right, max_left;

	if (tree == NULL)
		return (1);

	/* checking for max and min numbers of subtrees */
	if (tree->left)
	{
		max_left = get_max(tree->left);
		if (max_left >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		min_right = get_min(tree->right);
		if (min_right <= tree->n)
			return (0);
	}

	/* checking if left and right subtrees are BSTs */
	bts_flag &= is_bst(tree->left);
	bts_flag &= is_bst(tree->right);
	return (bts_flag);

}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid BST and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int bts_flag = 1;

	if (tree == NULL)
		return (0);

	else
		bts_flag = is_bst(tree);
	return (bts_flag);
}
