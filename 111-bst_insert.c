#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newnode, *prev, *current;

	if (tree == NULL)
		return (NULL);
	newnode = malloc(sizeof(bst_t));
	if (newnode == NULL)
		return (NULL);

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->n = value;
	if (*tree == NULL)
	{
		newnode->parent = NULL;
		*tree = newnode;
		return (newnode);
	}
	prev = NULL;
	current = *tree;
	while (current)
	{
		prev = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
		{
			free(newnode);
			return (NULL);
		}
	}
	newnode->parent = prev;
	if (value < prev->n)
		prev->left = newnode;
	else if (value > prev->n)
		prev->right = newnode;
	return (newnode);
}
