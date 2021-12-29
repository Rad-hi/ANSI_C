#include "binary_trees.h"

tree_node* my_tree;

int main(int argc, char const *argv[]){
	
	insert_in_bin_tree(&my_tree, 11);
	insert_in_bin_tree(&my_tree, 19);
	insert_in_bin_tree(&my_tree, 8);
	insert_in_bin_tree(&my_tree, 35);
	insert_in_bin_tree(&my_tree, 22);
	insert_in_bin_tree(&my_tree, 1);
	insert_in_bin_tree(&my_tree, 99);

	display_tree(my_tree);

	printf("\nThis value: ---<%-2d>---, is at level: ---<%-2d>---", 99, find_in_bin_tree(my_tree, 99));
	printf("\nThis value: ---<%-2d>---, is at level: ---<%-2d>---", 5 , find_in_bin_tree(my_tree, 5));
	printf("\nThis value: ---<%-2d>---, is at level: ---<%-2d>---", 22, find_in_bin_tree(my_tree, 8));
	printf("\nThis value: ---<%-2d>---, is at level: ---<%-2d>---", 11, find_in_bin_tree(my_tree, 11));

	printf("\n");

	return 0;
}