#include "binary_trees.h"

/**
 * calculate_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the binary tree or 0 if tree is NULL.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);
	lheight = 1 + calculate_height(tree->left);
	rheight = 1 + calculate_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: balance factor of node, 0 if node is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (0);
	balance_factor = (calculate_height(tree->left) -
			  calculate_height(tree->right));
	return (balance_factor);
}
