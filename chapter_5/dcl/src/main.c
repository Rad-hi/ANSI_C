/*
    PAGE: 113
    ---
    Ex: Expand dcl to handle declarations with function argument types, 
        qualifiers like const, and so on. 
    ---
    This is a hack AND DOESN'T WORK APPROPRIATELY !
    Braces and brackets aren't recognized as function paramters.
    This was a hard assignment, and I couldn't make it work entirely.
    ---
    Personalizations: Made this into a multifile project, with a Makefile,
    a debug printing macro, and a customization to the reading functionality
    with read_input (gettoken.h).
    Additionally, I made it mandatory that the input ends with a semicolon; ';'
    because I encountered some problems with the original code reading faulty 
    syntax errors.
 */

/* CUSTOM INCLUDES */

#include "gettoken.h"
#include "dcl.h"

/* STD INCLUDES */

#include <stdio.h>
#include <string.h>

/* Functions' prototypes */
void dcl(void);
void dirdcl(void);

/* Variables */
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */

char parameters[MAXTOKEN]; /* Prameters; void, int, .. */

char * line_ptr;
char line[MAX_INPUT_LEN]; /* This is the pointer containing the line */
char out[MAX_OUTPUT_LEN]; /* This is the output line */

/* convert declaration to words */
int main(){

    read_input(line);

    line_ptr = line; /* Point the line_ptr to the first element of the line (char array) */
    
    //while(gettoken() != EOF){ /* 1st token on line */
        gettoken();
        strcpy(datatype, token); /* is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != ';')
            printf("syntax error\n");
        printf("%s: %s %s%s\n", name, out, datatype, parameters);
    //}

    return 0;
}