#include "binary_trees.h"

/**
 * insert_bst - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
bst_t *insert_bst(bst_t **tree, int value)
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

/**
 * avl_insert -  inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the
 * AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL otherwise.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newnode, *cursor;
	int bf;

	if (tree == NULL)
		return (NULL);
	newnode = insert_bst(tree, value);
	cursor = newnode;
	while (cursor)
	{
		bf = binary_tree_balance(cursor);
		if (bf != 0 && bf != 1 && bf != -1)
		{
			if (value > cursor->n &&
			    value > cursor->right->n)
				binary_tree_rotate_left(cursor);
			else if (value < cursor->n &&
				 value < cursor->left->n)
				binary_tree_rotate_right(cursor);
			else if (value < cursor->n && value > cursor->left->n)
			{
				binary_tree_rotate_left(cursor->left);
				binary_tree_rotate_right(cursor);
			}
			else if (value > cursor->n && value < cursor->right->n)
			{
				binary_tree_rotate_right(cursor->right);
				binary_tree_rotate_left(cursor);
			}
			if (cursor->parent->parent == NULL)
				*tree = cursor->parent;

		}
		cursor = cursor->parent;
	}
	return (newnode);
}
