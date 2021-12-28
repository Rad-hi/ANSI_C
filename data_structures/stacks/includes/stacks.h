#ifndef __STACKS_H__
#define __STACKS_H__

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

#define IMPOSSIBLE 		(-1)

typedef struct stack{
	int value;
	struct stack * next;
}stack;

bool push_stack(stack** my_stack, int val);
int pop_stack(stack** my_stack);

void print_stack(stack* my_stack);

#endif // __STACKS_H__