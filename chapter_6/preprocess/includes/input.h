#ifndef __INPUT_H__
	#define __INPUT_H__
	
	/* STD INCLUDES */
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stddef.h>
	
	#define MAX_LINES           256
	#define MAXLINE             1024
	#define MAX_VALUE_LEN		1000
	#define MAX_DIRECTIVE_LEN	24

	/* These are the directives to be detected "#define" and "#undef" */
	enum{ERR_DIR, EMPTY_LINE, NORMAL_LINE, UNKNOWN_DIR, DEFINE_DIR, UNDEFINE_DIR};

	unsigned char get_directive(char * s, char * name, char * val);
	unsigned int  read_input(char * lines[]);
	void free_input(char * lines[], unsigned int how_many);

#endif // __INPUT_H__