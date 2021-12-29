#ifndef __TRIE_H__
#define __TRIE_H__
	
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define NUM_OF_CHILDREN			265 /* Number of all possible chars */

	typedef struct trie_node{
		struct trie_node * children[NUM_OF_CHILDREN];
		bool terminal;
	}trie_node;

	bool insert_in_trie(trie_node** node, char * text);
	void print_trie(trie_node* node);

#endif // __TRIE_H__