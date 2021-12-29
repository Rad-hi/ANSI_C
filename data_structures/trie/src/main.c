#include "trie.h"

trie_node* my_trie;

int main(int argc, char const *argv[]){
	insert_in_trie(&my_trie, "radhi");
	insert_in_trie(&my_trie, "cattle");
	insert_in_trie(&my_trie, "dance");
	insert_in_trie(&my_trie, "radix");
	insert_in_trie(&my_trie, "run");
	insert_in_trie(&my_trie, "cat");

	print_trie(my_trie);

	return 0;
}