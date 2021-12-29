/* An implementation for a binary search tree */

#ifndef __BINARY_TREES_H__
#define __BINARY_TREES_H__
	
	#define NOT_FOUND				(-1)

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>

	typedef struct tree_node{
		int value;
		struct tree_node * more;
		struct tree_node * less;
	}tree_node;

	/* Returns the success/failure of creation */
	bool insert_in_bin_tree(tree_node ** node_ptr, const int val);

	/* Returns the level of the value */
	int find_in_bin_tree(tree_node * node_ptr, const int val);

	void display_tree(tree_node* node_ptr);


#endif // __BINARY_TREES_H__