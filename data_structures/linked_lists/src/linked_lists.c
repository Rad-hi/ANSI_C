#include "linked_lists.h"

/* ---------------------------------------------------------------------- */
/* -------------------------- ADDING FUNCTIONS -------------------------- */
/* ---------------------------------------------------------------------- */

void add_head(node_t ** head, int val){
	node_t * temporary = (node_t *)malloc(sizeof(node_t));

	temporary->value = val;

	if(*head == NULL) temporary->next = NULL; // If we're creating the first element
	else temporary->next = *head;

	*head = temporary;
}

void add_tail(node_t * head, int val){
	node_t * temporary;
	
	/* Reach the end of the linked list */
	for(temporary = head; temporary->next; temporary = temporary->next);
	
	temporary->next = (node_t *)malloc(sizeof(node_t));
	temporary->next->value = val;
	temporary->next->next = NULL;
}

/* ZERO INDEXED */
void add_at(node_t * head, int val, int index){
	if(head == NULL) return; /* Already empty */
	if(index <= 0) return; /* To add at 0, we need a double pointer to the head */

	unsigned int i;
	node_t * temporary;

	/* Traverse the linked list until we either reach the end of it OR we reach the desired index */
	for(temporary = head, i = 0; i < index-1 && temporary->next; temporary = temporary->next, i++);

	if(i != index-1) return; /* Index out of range */

	node_t * new_node = (node_t *)malloc(sizeof(node_t));
	
	new_node->value = val;

	/* The next two instructions must be in order */ 
	new_node->next = temporary->next;
	temporary->next = new_node;	
}

/* ---------------------------------------------------------------------- */
/* -------------------------- REMOING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void remove_head(node_t ** head){
	if(head == NULL) return; /* Already empty */
	
	node_t * temporary = *head;

	*head = (*head)->next;
	free(temporary);
}

void remove_tail(node_t * head){
	node_t * temporary;

	if(head == NULL) return; /* Already empty */

	/* traverse the linked list until we reach the before-last item */
	for(temporary = head; temporary->next->next; temporary = temporary->next);

	node_t * to_remove = temporary->next;
	temporary->next = NULL;
	free(to_remove);
}

/* ZERO INDEXED */
void remove_at(node_t * head, int index){
	if(head == NULL) return; /* Already empty */

	if(index <= 0) return; /* To remove at 0, we need a double pointer to the head */

	unsigned int i;
	node_t * temporary;

	/* traverse the linked list until we reach the before-last item */
	for(temporary = head, i = 0; i < index-1 && temporary->next->next; temporary = temporary->next, i++);

	if(i != index-1) return; /* Index out of range */

	node_t * to_remove = temporary->next;
	temporary->next = temporary->next->next;
	free(to_remove);

}

/* ---------------------------------------------------------------------- */
/* -------------------------- FINDING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

node_t* find_at_value(node_t * head, int val){
	if(head == NULL) return NULL;
	node_t * temporary = head;
	do{ if(temporary->value == val) return temporary; } while((temporary = temporary->next));
	return NULL;
}

node_t* find_at_index(node_t * head, int index){
	if(head == NULL) return NULL;
	
	unsigned int i;
	node_t * temporary;

	for(temporary = head, i = 0; i < index && temporary->next; temporary = temporary->next, i++);

	if(i != index) return NULL; /* Index out of range */
	return temporary;
}

/* ---------------------------------------------------------------------- */
/* ------------------------- PRINTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void print_linked_list(node_t * head){
	node_t * temporary = head;
	
	while(temporary != NULL){
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

/* ---------------------------------------------------------------------- */
/* -------------------------- SORTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

								/* TODO */