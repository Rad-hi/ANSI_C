#include "queues.h"

#define NUM_VALS			2

int main(int argc, char const *argv[]){
	queue * my_queue;

	init_queue(&my_queue);

	for(int i = 1; i <= NUM_VALS; i++) printf("%s %d\n", (enqueue(&my_queue, i) ? "SUCCESS": "FAILURE"), i);	

	/* Remove the two elements that have been added */
	printf("%d\n", dequeue(&my_queue));
	printf("%d\n", dequeue(&my_queue));

	/* Attempt to remove another (non-existing) element */
	printf("%d\n", dequeue(&my_queue));

	/* Add another element */
	enqueue(&my_queue, 69);
	printf("%d\n", dequeue(&my_queue));
	
	return 0;
}