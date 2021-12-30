#include "trie.h"

#define NUM_SEARCHES			3
char* tests[NUM_SEARCHES] = {
	"radix",
	"run",
	"catie",
};

trie_node* my_trie;

int main(int argc, char const *argv[]){
	insert_in_trie(&my_trie, "radhi");
	insert_in_trie(&my_trie, "cattle");
	insert_in_trie(&my_trie, "dance");
	insert_in_trie(&my_trie, "radix");
	insert_in_trie(&my_trie, "run");
	insert_in_trie(&my_trie, "cat");

	print_trie(my_trie);

	for(unsigned int i = 0; i < NUM_SEARCHES; i++)
		printf("%-11s ---<%-6s>--- in trie.\n", search_in_trie(my_trie, tests[i]) ? "Found" : "Didn't find", tests[i]);

	delete_from_trie(&my_trie, "radix");
	delete_from_trie(&my_trie, "cat");
	delete_from_trie(&my_trie, "dance");

	print_trie(my_trie);

	return 0;
}