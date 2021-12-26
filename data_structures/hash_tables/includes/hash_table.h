#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#define MAX_TABLE_LEN				10
#define MAX_NAME_LEN				20

#include<stdlib.h>
#include<stdio.h>

/* 
-- The vertical table is the hash-table.
-- The horizontal table in each line is a linked list for when the hash-function overlaps
	___     ___             ___
   |   |-->|   |--> ... -->|   |-->NULL
    ---     ---             ---
    ___
   |   |-->NULL
    ---
     .
     .
     .
    ___     ___
   |   |-->|   |-->NULL
    ---     ---
*/
typedef struct person{
	char name[MAX_NAME_LEN];
	int age;
	person * next;
}person_t;

static unsigned int hash_function(char * str);

/* The hash-table will store pointers to the objects since the same method must function optimally for objects with any size */
bool insert_hash(person_t** hash_table, char * name, int age);
void delete_hash(person_t** hash_table, char * name);

void print_hash_table(person_t** hash_table);

#endif // __HASH_TABLE_H__