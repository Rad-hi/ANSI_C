/*
    PAGE: 129
    ---
    Ex: Implement a simple version of the #define processor (i.e., no arguments)
        suitable for use with C programs, based on the routines of this section. 
        You may also find getch and ungetch helpful.
 */

/* CUSTOM INCLUDES */
#include "input.h"
#include "preprocessor.h"

/* STD INCLUDES */
#include <stdio.h>

struct directives_list * hashtab[HASHSIZE]; /* pointer table */

char * lines[MAX_LINES];

/* Preprocessor that handles "define" statements in C programs */
int main(int argc, char const *argv[]){

    char name[MAX_DIRECTIVE_LEN], val[MAX_VALUE_LEN];

    unsigned int line_num = 0;
    
    line_num = read_input(lines);

    for(unsigned i = 0; i < line_num; i++){
        char * line = lines[i];

        switch(get_directive(line, name, val)){

            case ERR_DIR: 
                printf("%s\n", "SYNTAX ERROR");
                return 0;
            break;
            
            case DEFINE_DIR: /* Found a define macro, install the value */
                install(name, val);
            break;
            
            case UNDEFINE_DIR: /* Found an undef macro, uninstall it */
                uninstall(name);
            break;

            case EMPTY_LINE:
                printf("%s\n", line);
            break;

            case NORMAL_LINE: /* Found a line of code, update it */
                process(line); /* Find defined values and change them if found */
                printf("%s\n", line);
            break;
            
            case UNKNOWN_DIR:
            default :
                printf("%s --> ", "UNKNOWN");
                printf("%s\n", line);
            break;
        }
    }
    
    free_input(lines, line_num);
   

    /* Free the memory allocated for the lookup table*/
    struct directives_list temp;
    struct directives_list * np;

    for(unsigned i = 0; i < HASHSIZE; i++){
        
        if(hashtab[i] != NULL){
            for (np = hashtab[i]; np != NULL; np = temp.next){
                temp.next = np->next;
                free(np);
            }

        }
    }

    return 0;
}