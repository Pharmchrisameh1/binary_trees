#include "binary_trees.h"


/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted.
 * @size: number of element in the array.
 *
 * Return: pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *rootnode = NULL;
	size_t i;
	int value;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		value = array[i];
		if (bst_insert(&rootnode, value) == NULL)
			continue;
	}
	return (rootnode);
}
