#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *, int);
binary_tree_t *binary_tree_insert_left(binary_tree_t *, int);
binary_tree_t *binary_tree_insert_right(binary_tree_t *, int);
void binary_tree_delete(binary_tree_t *);
int binary_tree_is_leaf(const binary_tree_t *);
int binary_tree_is_root(const binary_tree_t *);
void binary_tree_preorder(const binary_tree_t *, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *);
size_t binary_tree_depth(const binary_tree_t *);
size_t binary_tree_size(const binary_tree_t *);
size_t binary_tree_leaves(const binary_tree_t *);
size_t binary_tree_nodes(const binary_tree_t *);
int binary_tree_balance(const binary_tree_t *);
int binary_tree_is_full(const binary_tree_t *);
int binary_tree_is_perfect(const binary_tree_t *);
binary_tree_t *binary_tree_sibling(binary_tree_t *);
binary_tree_t *binary_tree_uncle(binary_tree_t *);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *,
		const binary_tree_t *);
void binary_tree_levelorder(const binary_tree_t *, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *);
int binary_tree_is_bst(const binary_tree_t *);
bst_t *bst_insert(bst_t **, int);
bst_t *array_to_bst(int *, size_t);
bst_t *bst_search(const bst_t *, int);
bst_t *bst_remove(bst_t *, int);
int binary_tree_is_avl(const binary_tree_t *);
avl_t *avl_insert(avl_t **, int);
avl_t *array_to_avl(int *, size_t);
avl_t *avl_remove(avl_t *, int);
avl_t *sorted_array_to_avl(int *, size_t);
int binary_tree_is_heap(const binary_tree_t *);
heap_t *heap_insert(heap_t **, int);
heap_t *array_to_heap(int *, size_t);
int heap_extract(heap_t **);
int *heap_to_sorted_array(heap_t *, size_t *);

#endif /* _BINARY_TREES_H_ */
