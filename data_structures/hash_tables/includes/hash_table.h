/* External chaining hash-table */

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#define MAX_TABLE_LEN				6
#define MAX_NAME_LEN				20

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>

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
	struct person * next;
}person_t;

/* ------------------------------------------------------------------------------- */
/* ---------------------------------- FUNCTIONS ---------------------------------- */
/* ------------------------------------------------------------------------------- */

/* The hash-table will store pointers to the objects since the same method must function optimally for objects with any size */
bool insert_in_hash_tab(person_t** hash_table, const char* name, int age);
void delete_from_hash_tab(person_t** hash_table, const char* name);
person_t* find_in_hash_tab(person_t** hash_table, const char* name);
person_t* find_no_case_in_hash_tab(person_t** hash_table, char* name);

void print_hash_table(person_t** hash_table);

#endif // __HASH_TABLE_H__