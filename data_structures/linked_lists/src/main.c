#include "linked_lists.h"

int main(int argc, char const *argv[]){
	
	node_t * head = NULL;
	
	for(int i = 3; i >=0; i--)add_head(&head, i);
	printf("%-15s", "Constructed-->");
	print_linked_list(head);

	add_tail(head, 7);
	printf("%-15s", "Add tail-->");
	print_linked_list(head);

	add_at(head, 9, 1);
	printf("%-15s", "Add at-->");
	print_linked_list(head);
	
	remove_head(&head);
	printf("%-15s", "Remove head-->");	
	print_linked_list(head);

	remove_tail(head);	
	printf("%-15s", "Remove tail-->");
	print_linked_list(head);

	remove_at(head, 1);
	printf("%-15s", "Remove at-->");
	print_linked_list(head);

	node_t * ret = find_at_value(head, 3);	
	printf("%-15s%d\n", "Returned -->", ret->value);

	ret = find_at_index(head, 0);	
	printf("%-15s%d\n", "Returned -->", ret->value);

	return 0;
}