#include "hash_table.h"

/* Create the hash-table .. a table of pointers to person objects */
person_t * hash_table[MAX_TABLE_LEN]; 

/* Names for testing */
static const char names[][MAX_NAME_LEN] = {
	"Radhi",
	"Sarra",
	"Saqrb", // This is the same as "Sarra" when it comes to hash
	"Lardm", // This is the same as "Karem" when it comes to hash
	"Jacob",
	"Karem",
};

int main(int argc, char const *argv[]){

	for(int i = 0; i < MAX_TABLE_LEN; i++) insert_in_hash_tab(hash_table, names[i], 15);
	print_hash_table(hash_table);

	delete_from_hash_tab(hash_table, "Radhi");
	
	insert_in_hash_tab(hash_table, "Kamel", 32);

	delete_from_hash_tab(hash_table, "Lardm");
	
	print_hash_table(hash_table);

	return 0;
}