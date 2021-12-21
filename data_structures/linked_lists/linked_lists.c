#include "linked_lists.h"

/* ---------------------------------------------------------------------- */
/* -------------------------- ADDING FUNCTIONS -------------------------- */
/* ---------------------------------------------------------------------- */

void add_head(node_t ** head, int val){
	node_t * temporary = (node_t *)malloc(sizeof(node_t));

	temporary->value = val;
	temporary->next = *head;

	*head = temporary;
}

void add_tail(node_t * head, int val){
	node_t * temporary;
	
	for(temporary = head; temporary->next; temporary = temporary->next);

	temporary->next = (node_t *)malloc(sizeof(node_t));
	temporary->value = val;
	temporary->next = NULL;
}

void add_at(node_t * head, int val, int index){
	unsigned int i;
	node_t * temporary;

	for(temporary = head, i = 0; temporary->next && i <= index; temporary = temporary->next, i++);

	if(i != index) return; /* Index out of range */

	node_t * new_node = (node_t *)malloc(sizeof(node_t));
	
	/* The next two instructions must be in order */ 
	new_node->next = temporary->next;
	temporary->next = new_node;
	
	new_node->value = val;
}

/* ---------------------------------------------------------------------- */
/* -------------------------- REMOING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void remove_head(node_t * head){

}

void remove_tail(node_t * head){

}

void remove_at(node_t * head, int index){

}

/* ---------------------------------------------------------------------- */
/* -------------------------- FINDING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

unsigned int find_at_value(node_t * head, int val){

}

int find_at_index(node_t * head, int index){

}

/* ---------------------------------------------------------------------- */
/* ------------------------- PRINTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void print_linked_list(node_t * head){

}

/* ---------------------------------------------------------------------- */
/* -------------------------- SORTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

								/* TODO */