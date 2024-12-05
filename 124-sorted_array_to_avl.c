#include "binary_trees.h"

/**
 * add_recursively - adds elements from an array
 * recursively into an AVL tree.
 * @rootnode: the root of the AVL tree to be added.
 * @array: pointer to the array with values to be added.
 * @begin: beginning index of half of the array.
 * @end: ending index of the half of the array.
 *
 * Return: returns pointer to the rootnode.
 */
avl_t *add_recursively(avl_t *rootnode, int *array, int begin, int end)
{
	int half;
	avl_t *newnode;

	if (begin > end)
		return (NULL);

	half = (begin + end) / 2;

	newnode = binary_tree_node(rootnode, array[half]);
	if (newnode == NULL)
		return (NULL);
	newnode->left = add_recursively(newnode, array, begin, half - 1);
	newnode->right = add_recursively(newnode, array, half + 1, end);

	return (newnode);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array.
 *
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rootnode = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	rootnode = add_recursively(rootnode, array, 0, size - 1);
	return (rootnode);
}
