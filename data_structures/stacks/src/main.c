#include "stacks.h"

#define NUM_VALS 		6

int main(int argc, char const *argv[]){
	
	stack * my_stack = NULL;

	for(int i = 1; i <= NUM_VALS; i++)
		push_stack(&my_stack, i*23);

	print_stack(my_stack);

	pop_stack(&my_stack);
	pop_stack(&my_stack);
	pop_stack(&my_stack);

	print_stack(my_stack);

	return 0;
}