#include "binary_trees.h"
#include <stdio.h>

/**
 * array_to_heap - Create a binary heap from an array
 * @array: An array of integers
 * @size: The number of elements in the array
 *
 * Return:
 * This function returns a pointer to the root node of the created binary heap.
 * If the array is NULL or the size is less than 1, the function returns NULL.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i = 0;

	if (!array || size < 1)
		return (NULL);

	heap_insert(&tree, array[0]);

	for (i = 1; i < size; i++)
		heap_insert(&tree, array[i]);

	return (tree);

}
