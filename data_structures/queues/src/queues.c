#include "queues.h"

void init_queue(queue** my_queue){
	if(*my_queue == NULL) return;

	(*my_queue)->head  = NULL;
	(*my_queue)->tail  = NULL;
}

bool enqueue(queue** my_queue, int val){
	node * temporary = (node*)malloc(sizeof(node));

	if(temporary == NULL) return false;

	temporary->value = val;
	temporary->next = NULL;

	/* If not the first one, chain it in */
	if((*my_queue)->tail != NULL)
		(*my_queue)->tail->next = temporary;
	
	/* Put the new node always at last */
	(*my_queue)->tail = temporary;

	if((*my_queue)->head == NULL)
		(*my_queue)->head = temporary; // Only one element
	
	return true;
}

int dequeue(queue** my_queue){
	if((*my_queue)->head == NULL) return EMPTY_QUEUE;

	node * temporary = (*my_queue)->head;

	int res = temporary->value;

	(*my_queue)->head = (*my_queue)->head->next;

	if((*my_queue)->head == NULL) // Empty queue
		(*my_queue)->tail = NULL;

	free(temporary);
	return res;
}