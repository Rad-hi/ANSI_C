#ifndef __PREPROCESSOR_H__
	#define __PREPROCESSOR_H__
	
	#include <stdlib.h>
	#include <stddef.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdio.h>

	#define HASHSIZE 		101
	#define MAX_LINE_LEN	1024
	#define MAX_WORD_LEN	24

	struct directives_list{ /* table entry: */
		struct directives_list *next; /* next entry in chain */
		char *name; /* defined name */
		char *defn; /* replacement text */
	};

	struct directives_list * install(char *name, char *defn);
	void uninstall(char * name);
	void process(char * line);

#endif // __PREPROCESSOR_H__