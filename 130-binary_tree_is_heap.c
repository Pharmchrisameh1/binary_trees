#include "binary_trees.h"

/**
 * get_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of the binary tree or 0 if node is NULL.
 */
size_t get_size(const binary_tree_t *tree)
{
	size_t size = -1;

	if (tree == NULL)
		return (0);
	size += 1 + get_size(tree->left);
	size += 1 + get_size(tree->right);
	return (size);
}

/**
 * check_complete - checks if a tree is complete based on
 * the index of a node (left child is 2*IdxOfParent + 1) or
 * (right child is 2*IdxOfParent + 2).
 * @tree: pointer to the root note of the tree to check.
 * @nodes_count: size of the binary tree.
 * @node_index: the current node of the index starting 0 at root.
 *
 * Return: 1 if tree is complete and 0 if not.
 */
int check_complete(const binary_tree_t *tree, size_t nodes_count,
		   size_t node_index)
{
	int is_complete_flag = 1;

	if (tree == NULL)
		return (1);
	if (node_index >= nodes_count)
		is_complete_flag = 0;
	is_complete_flag &= check_complete(tree->left, nodes_count,
					   (2 * node_index) + 1);
	is_complete_flag &= check_complete(tree->right, nodes_count,
					   (2 * node_index) + 2);
	return (is_complete_flag);
}

/**
 * is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is complete, otherwise 0.
 */
int is_complete(const binary_tree_t *tree)
{
	int is_complete_flag;
	size_t nodes_count, node_index;

	nodes_count = get_size(tree);
	node_index = 0;
	is_complete_flag = check_complete(tree, nodes_count, node_index);
	return (is_complete_flag);
}

/**
 * is_heap - checks if a tree and all subtrees are valid
 * max heaps.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is head, otherwise 0.
 */
int is_heap(const binary_tree_t *tree)
{
	int is_heap_flag = 1;

	if (tree == NULL)
		return (1);
	if (tree->parent)
	{
		if (tree->parent->n < tree->n)
			return (0);
	}
	is_heap_flag &= is_heap(tree->left);
	is_heap_flag &= is_heap(tree->right);
	return (is_heap_flag);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * and is complete.
 * @tree:  pointer to the root node of the tree to check.
 *
 * Return: 1 if valid max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_heap_flag = 1;

	if (tree == NULL)
		return (0);
	is_heap_flag &= is_complete(tree);
	is_heap_flag &= is_heap(tree);

	return (is_heap_flag);
}
