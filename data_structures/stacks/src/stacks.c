#include "stacks.h"

bool push_stack(stack** my_stack, int val){
	stack * temporary = (stack*)malloc(sizeof(stack));
	if(temporary == NULL) return NULL;

	temporary->value = val;
	temporary->next = *my_stack;
	*my_stack = temporary;
	return true;
}

int pop_stack(stack** my_stack){
	if(*my_stack == NULL) return IMPOSSIBLE;

	int res = (*my_stack)->value;
	stack * temporary = *my_stack;
	*my_stack = temporary->next;
	free(temporary);

	return res;
}

void print_stack(stack* my_stack){
	if(my_stack == NULL) return;

	stack * temporary = my_stack;
	do{
		printf("%d - ", temporary->value);
	}while((temporary = temporary->next));
	printf("\n");
}