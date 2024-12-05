#include "binary_trees.h"

/**
 * find_node - searches for a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: pointer to the node containing a value equal to value.
 * or NULL if nothing is found or tree is NULL.
 */
avl_t *find_node(const avl_t *tree, int value)
{
	avl_t *cursor;

	if (tree == NULL)
		return (NULL);
	cursor = (avl_t *)tree;
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

/**
 * delete_2_children - deletes a node in a BST if it has 2 children
 * @to_delete: pointer to the node to be deleted.
 *
 * Return: pointer to the node that replaces the deleted node.
 */
avl_t *delete_2_children(avl_t *to_delete)
{
	int successor_val;
	avl_t *successor, *next, *prev, *cursor;

	cursor = to_delete->right;
	while (cursor->left)
		cursor = cursor->left;
	successor_val = cursor->n;
	successor = find_node(to_delete, successor_val);
	if (successor->parent == to_delete)
	{
		successor->left = to_delete->left;
		to_delete->left->parent = successor;
		successor->parent = to_delete->parent;
		if (to_delete->parent)
		{
			if (to_delete->parent->left == to_delete)
				successor->parent->left = successor;
			else
				successor->parent->right = successor;
		}
		free(to_delete);
		return (successor);
	}
	prev = successor->parent;
	next = successor->right;
	prev->left = next;
	if (next)
		next->parent = prev;
	to_delete->n = successor->n;
	free(successor);
	return (to_delete);
}

/**
 * delete_1_child - deletes a node in a BST that has only 1 child.
 * @to_delete: pointer to node to be deleted.
 *
 * Return: pointer to the node that replaces deleted node.
 */
avl_t *delete_1_child(avl_t *to_delete)
{
	avl_t *prev, *next;

	prev = to_delete->parent;
	next = to_delete->left == NULL ? to_delete->right
		: to_delete->left;
	next->parent = prev;
	if (prev != NULL)
	{
		if (prev->left == to_delete)
			prev->left = next;
		else
			prev->right = next;
	}
	free(to_delete);
	if (prev != NULL)
		return (prev);
	else
		return (next);
}

/**
 * check_balance - checks on the balance of nodes
 * and does rotations accordingly to balance tree.
 * @node: pointer to node to check balance from.
 * @replacement: double pointer to the node that
 * replaces the deleted note after balancing.
 *
 * Return: pointer to node after balancing.
 */
avl_t *check_balance(avl_t *node, avl_t **replacement)
{
	avl_t *cursor;
	int bf_n, bf_l, bf_r;

	(void)replacement;
	cursor = node;
	while (cursor)
	{
		bf_n = binary_tree_balance(cursor);
		if (bf_n != 0 && bf_n != 1 && bf_n != -1)
		{
			bf_l = binary_tree_balance(cursor->left);
			bf_r = binary_tree_balance(cursor->right);

			if (bf_n > 1 && bf_l >= 0)
				binary_tree_rotate_right(cursor);
			else if (bf_n < -1 && bf_r <= 0)
				binary_tree_rotate_left(cursor);
			else if (bf_n > 1 && bf_l < 0)
			{
				binary_tree_rotate_left(cursor->left);
				binary_tree_rotate_right(cursor);
			}
			else if (bf_n < -1 && bf_r > 0)
			{
				binary_tree_rotate_right(cursor->right);
				binary_tree_rotate_left(cursor);
			}
			if (cursor->parent->parent == NULL)
				*replacement = cursor->parent;
		}
		cursor = cursor->parent;
	}
	return (node);
}

/**
 * avl_remove - removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where
 * you will remove a node
 * @value: value to remove in the tree.
 *
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *to_delete = find_node(root, value), *prev, *replacement;

	if (to_delete == NULL || root == NULL)
		return (root);
	if (to_delete->left == NULL && to_delete->right == NULL)
	{			/* delete node with no children */
		prev = to_delete->parent;
		if (prev)
		{
			if (prev->left == to_delete)
				prev->left = NULL;
			else
				prev->right = NULL;
			free(to_delete);
		}
		else
		{
			free(to_delete);
			return (NULL);
		}
		check_balance(prev, &prev);
		if (prev->parent == NULL)
			return (prev);
	} /* delete node with one child only */
	else if ((to_delete->left && to_delete->right == NULL) ||
		(to_delete->right && to_delete->left == NULL))
	{
		replacement = delete_1_child(to_delete);
		check_balance(replacement, &replacement);
		if (replacement->parent == NULL)
			return (replacement);
	} /* delete node with 2 children */
	else if (to_delete->left && to_delete->right)
	{
		replacement = delete_2_children(to_delete);
		check_balance(replacement, &replacement);
		if (replacement->parent == NULL)
			return (replacement);
	}
	return (root);
}
