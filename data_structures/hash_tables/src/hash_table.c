#include"hash_table.h"

/* This is a hash function that I came up with based purely on intuition, I have no idea about its distribution */
static unsigned int hash_function(const char * str){
	unsigned int res, i;

	// The counter i is added as a safety measure for in case the string isn't '\0' terminated
	for(res=0, i = 0; *str++ && i < MAX_NAME_LEN; res += (unsigned int)(*str / 2) * 7, i++);

	return res % MAX_TABLE_LEN;
}

bool insert_in_hash_tab(person_t** hash_table, const char* name, int age){
	unsigned int index = hash_function(name);

	/* Since we're chaining, we'll "almost" always find a place for a new comer */
	person_t * p = (person_t*)malloc(sizeof(person_t));

	if(p != NULL){ /* We allocated memory */

		strncpy(p->name, name, MAX_NAME_LEN);
		p->next = hash_table[index];
		hash_table[index] = p;
		return true;
	}

	/* Couldn't add a person */
	return false;
}

void delete_from_hash_tab(person_t** hash_table, const char* name){
	unsigned int index = hash_function(name);

	person_t * temporary = hash_table[index];
	person_t * prev = NULL;

	do{
		if(strncmp(temporary->name, name, MAX_NAME_LEN) == 0){
			if(prev == NULL){ // Start of the linked-list
				hash_table[index] = temporary->next;
			}
			else{
				prev->next = temporary->next;
			}
		}
		else prev = temporary;
	}while((temporary = temporary->next));

	free(temporary);
}

void print_hash_table(person_t** hash_table){

	person_t * temporary;

	printf("%s\n", "START");

	for(unsigned int i = 0; i < MAX_TABLE_LEN; i++){
		temporary = hash_table[i];
		printf("\t%d\t---\t", i);
		if(temporary != NULL)
			do 
				printf("%s - ", temporary->name);
			while((temporary = temporary->next));
		printf("\n");
	}
	
	printf("%s\n", "END");
}