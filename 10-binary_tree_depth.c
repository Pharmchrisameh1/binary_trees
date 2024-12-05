#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth.
 *
 * Return: depth of pointer or 0 if node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	if (tree == NULL)
		return (0);
	while (cursor->parent != NULL)
	{
		depth++;
		cursor = cursor->parent;
	}
	return (depth);
}
