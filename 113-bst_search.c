#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: pointer to the node containing a value equal to value.
 * or NULL if nothing is found or tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *cursor;

	if (tree == NULL)
		return (NULL);
	cursor = (bst_t *)tree;
	while (cursor)
	{
		if (value < cursor->n)
			cursor = cursor->left;
		else if (value > cursor->n)
			cursor = cursor->right;
		else
			return (cursor);
	}
	return (cursor);
}
