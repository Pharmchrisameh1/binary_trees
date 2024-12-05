#include "binary_trees.h"

/**
 * binary_tree_insert_right -  inserts a node as the right-child
 * of another node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: is the value of the n member in the new node.
 *
 * Return: pointer to the newly inserted node or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;

	newnode->left = NULL;
	if (parent->right != NULL)
	{
		newnode->right = parent->right;
		newnode->right->parent = newnode;
		parent->right = newnode;
	}
	else
	{
		newnode->right = NULL;
		parent->right = newnode;
	}
	return (newnode);
}
