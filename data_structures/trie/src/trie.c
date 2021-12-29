#include "trie.h"

static trie_node* create_trie_node(){
	trie_node* temporary = (trie_node*)malloc(sizeof(trie_node));

	if(temporary == NULL) return NULL;

	for(unsigned int i = 0; i < NUM_OF_CHILDREN; i++){
		temporary->children[i] = NULL;
	}
	temporary->terminal = false;

	return temporary;
}

bool insert_in_trie(trie_node** node, char * text){
	if(*node == NULL) *node = create_trie_node();


	trie_node* temporary = *node;
	unsigned int sz = strlen(text);

	/* Char is signed, we need a non-negative index */
	unsigned char* input_text = (unsigned char*)text;
	
	/* Fill in all nodes for the inserted word */
	for(unsigned int i = 0; i < sz; i++){
		/* Children for this node at this specific char is non-existent --> create a node for it */
		if(temporary->children[input_text[i]] == NULL)
			temporary->children[input_text[i]] = create_trie_node();
		/* Go to that specific child */
		temporary = temporary->children[input_text[i]];
	}

	if(temporary->terminal) /* The word exists in the trie */
		return false;
	
	temporary->terminal = true; /* The nodes for the word exists in the trie, but not necessarely terminated --> representing a substring maybe */
	return true;
}

static void print_trie_rec(trie_node* node, char* prefix, unsigned int len){
	/* 
	   We know that we are going to need a longer prefix, longer by 2 
	   since we need a '\0' and the new char in the "hisory"
	 */
	char new_prefix[len+2]; 
	memcpy(new_prefix, prefix, len);
	new_prefix[len+1] = '\0';

	if(node->terminal)
		printf("Word ---<%-6s>---\n", prefix);

	for(unsigned int c = 0; c < NUM_OF_CHILDREN; c++){
		if(node->children[c] != NULL){
			new_prefix[len] = c; /* Add the current char to the history before going forward */
			print_trie_rec(node->children[c], new_prefix, len+1);
		}
	}
}

void print_trie(trie_node* node){
	if(node == NULL){
		printf("%s\n", "Trie ---<Empty>---");
		return;
	}

	print_trie_rec(node, NULL, 0);
}