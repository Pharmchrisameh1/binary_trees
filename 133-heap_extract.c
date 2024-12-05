#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Calculate the height of a binary tree (heap)
 * @tree: A pointer to the root of the binary tree (heap)
 *
 * Return:
 * This function returns the height of the binary tree (heap). If the tree is
 * NULL, the function returns 0, indicating an empty tree. Otherwise, it
 * returns the height of the tree.
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * tree_size_h - Measures the sum of heights of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return:
 * This function returns the sum of heights of the binary tree. If the tree is
 * NULL, indicating an empty tree, the function returns 0. If the tree has only
 * one node (the root), the function returns 1, indicating a tree with a single
 * level.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - Recursive function to traverse a binary tree in preorder.
 * @tree: Pointer to the root node of the binary tree.
 * @node: Pointer to a pointer that will be updated with the found node.
 * @height: The remaining height to traverse before updating the node.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}


/**
 * heapify - Heapify a binary tree rooted at the specified node.
 * @root: Pointer to the root node of the binary tree.
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - Extract the root value from a max heap.
 * @root: Pointer to the root node of the max heap.
 *
 * Return:
 * The extracted root value (maximum value) or 0 if the heap is empty.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
