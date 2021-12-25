#include "linked_lists.h"

int main(int argc, char const *argv[]){
	
	node_t * head = NULL;
	
	for(int i = 3; i >=0; i--)add_head(&head, i);
	print_linked_list(head);

	add_tail(head, 7);
	print_linked_list(head);

	add_at(head, 9, 2);
	print_linked_list(head);
	
	remove_head(&head);	
	print_linked_list(head);

	remove_tail(head);	
	print_linked_list(head);

	remove_at(head, 2);	
	print_linked_list(head);

	node_t * ret = find_at_value(head, 9);	
	printf("Returned --> %d\n", ret->value);

	ret = find_at_index(head, 3);	
	printf("Returned --> %d\n", ret->value);

	return 0;
}