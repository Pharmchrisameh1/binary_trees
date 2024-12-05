#include "binary_trees.h"

/**
 * check_in_tree - traveses and tree and checks if a node is inside it.
 * @tree: pointer to the root of the tree to be traversed.
 * @node: node to be checked if inside root or not.
 *
 * Return: 1 if found, 0 if not found.
 */
int check_in_tree(binary_tree_t *tree, binary_tree_t *node)
{
	int found_flag = 0;

	if (tree == NULL)
		return (0);
	if (tree == node)
		found_flag = 1;
	found_flag |= check_in_tree(tree->left, node);
	found_flag |= check_in_tree(tree->right, node);
	return (found_flag);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the lowest common anscestor of the 2 given nodes.
 * or NULL if no common anscestor found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *cursor;
	int found_flag = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	cursor = (binary_tree_t *)first;
	while (cursor != NULL)
	{
		/* Traverse the tree and check if second is there */
		found_flag = check_in_tree(cursor, (binary_tree_t *)second);
		if (found_flag == 1)
			return (cursor);
		cursor = cursor->parent;
	}
	return (NULL);
}
