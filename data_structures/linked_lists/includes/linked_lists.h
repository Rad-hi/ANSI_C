#ifndef __LINKED_LISTS_H__
#define __LINKED_LISTS_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node * next;
}node_t;

/* ---------------------------------------------------------------------- */
/* -------------------------- ADDING FUNCTIONS -------------------------- */
/* ---------------------------------------------------------------------- */

void add_head(node_t ** head, int val);
void add_tail(node_t * head, int val);
void add_at(node_t * head, int index, int val);

/* ---------------------------------------------------------------------- */
/* -------------------------- REMOING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void remove_head(node_t ** head);
void remove_tail(node_t * head);
void remove_at(node_t * head, int index);

/* ---------------------------------------------------------------------- */
/* -------------------------- FINDING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

node_t* find_at_value(node_t * head, int val);
node_t* find_at_index(node_t * head, int index);

/* ---------------------------------------------------------------------- */
/* ------------------------- PRINTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

void print_linked_list(node_t * head);

/* ---------------------------------------------------------------------- */
/* -------------------------- SORTING FUNCTIONS ------------------------- */
/* ---------------------------------------------------------------------- */

								/* TODO */

#endif // __LINKED_LISTS_H__