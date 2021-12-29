#include "binary_trees.h"

static tree_node* create_node(int val){
	tree_node* temporary = (tree_node*)malloc(sizeof(tree_node));
	if(temporary == NULL) return NULL;

	temporary->value = val;
	temporary->more  = NULL;
	temporary->less  = NULL;

	return temporary;
}

static char* get_tabs(char* tabs, const int level){
	unsigned int i;
	for(i = 0; i < level; i++)
		tabs[i] = '\t';
	tabs[i] = '\0';
	return tabs;
}

#define MAX_TABS			10
static void display_tree_rec(tree_node* node_ptr, int level){
	
	if(node_ptr == NULL){
		printf("%s","---<end>");
		return;
	}

	char tabs[MAX_TABS];
	printf("\n%s---<%-2d>---<MORE>", get_tabs(tabs, level), node_ptr->value);
	display_tree_rec(node_ptr->more, level+1);

	printf("\n%s---<%-2d>---<LESS>", get_tabs(tabs, level), node_ptr->value);
	display_tree_rec(node_ptr->less, level+1);

}

/* Returns the level of the value */
static int find_in_bin_tree_rec(tree_node * node_ptr, const int val, int level){

	if(node_ptr == NULL) return NOT_FOUND;

	if(val == node_ptr->value) return level;

	level++; /* Went down a level */
	if(val >  node_ptr->value) return find_in_bin_tree_rec(node_ptr->more, val, level);
	else return find_in_bin_tree_rec(node_ptr->less, val, level);

	return level;
}

/* Returns the success/failure of creation */
bool insert_in_bin_tree(tree_node ** node_ptr, const int val){
	if(*node_ptr == NULL){
		*node_ptr = create_node(val);
		return *node_ptr != NULL;
	}

	if(val == (*node_ptr)->value) return false; /* Value is already there */
 
 	if(val >  (*node_ptr)->value) return insert_in_bin_tree(&((*node_ptr)->more), val); 
	if(val <  (*node_ptr)->value) return insert_in_bin_tree(&((*node_ptr)->less), val);

	return true;
}


void display_tree(tree_node* node_ptr){
	printf("%s\n", "<START>");
	display_tree_rec(node_ptr, 0);
	printf("\n\n%s\n", "<END>");
}

int find_in_bin_tree(tree_node* node_ptr, const int val){
	return find_in_bin_tree_rec(node_ptr, val, 0);
}