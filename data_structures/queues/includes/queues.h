#ifndef __QUEUES_H__
#define __QUEUES_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_QUEUE			(-1)

typedef struct node{
	int value;
	struct node * next;
}node;

typedef struct{
	node * tail;
	node * head;
}queue;

void init_queue(queue** my_queue);

bool enqueue(queue** my_queue, int val);
int dequeue(queue** my_queue);

void print_queue(queue* my_queue);

#endif // __QUEUES_H__