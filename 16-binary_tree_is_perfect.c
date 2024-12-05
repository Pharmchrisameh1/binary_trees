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
		return (-1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	lheight = 1 + calculate_height(tree->left);
	rheight = 1 + calculate_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect_flag = 1;

	if (tree == NULL)
		return (0);
	/* a node is found with only 1 child */
	if ((tree->left && !(tree->right)) ||
	    (tree->right && !(tree->left)))
		is_perfect_flag = 0;
	else if (calculate_height(tree->left) !=
		 calculate_height(tree->right))
		is_perfect_flag = 0;
	else if (tree->left == NULL &&
		tree->right == NULL)
		return (1);

	/* recursive calls to left and right sides with & operator */
	is_perfect_flag &= binary_tree_is_perfect(tree->left);
	is_perfect_flag &= binary_tree_is_perfect(tree->right);

	return (is_perfect_flag);

}
