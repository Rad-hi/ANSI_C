/*
    PAGE: 106
    ---
    Ex: Write the program tail, which prints the last n lines of its input. By default, n
        is set to 10, let us say, but it can be changed by an optional argument so that
        tail -n, prints the last n lines. The program should behave rationally no matter 
        how unreasonable the input or the value of n. Write the program so it makes the
        best use of available storage; lines should be stored as in the sorting program 
        of Section 5.6, not in a two-dimensional array of fixed size.
    ---
    getline() from the standard library is slightly changed, so be mindful of the changes.
    new :: getline(&buffer, &size, stdin);
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES           1024
#define MAXLINE             1024

#define DEFAULT_TAIL_FLAG   -1
#define DEFAULT_TAIL        10


/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]){
    
    size_t size;
    char * line;
    char * lines[MAX_LINES];
    
    char num[5] = "0";
    int c, lineno = 0, number = DEFAULT_TAIL_FLAG, tail;

    /* Here we're incrementing argv the pointer to pointers */
    while (--argc > 0 && (*++argv)[0] == '-')
        
        /* Here we're incrementing the pointer in the location argv is pointing at */
        while (c = *++argv[0])
            switch (c) {
                
                /* Read a digit */
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    if(number++ < 4)
                        num[number] = c; /* Fill the number */
                break;
                
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                break;
            }

    /* Either we have a number at input, or we have a default behavior */
    if(number >= 0 || number == DEFAULT_TAIL_FLAG){

        /* Get the tail, either from input or default value */
        tail = number > 0 ? atoi(num) : DEFAULT_TAIL;

        /* allocate memory for a line, add a ref to it in the tab of pointers, then fill it */
        do{
            line = (char *)malloc(MAXLINE * sizeof(char));
            *(lines + lineno) = line;
            lineno++;
        }while(getline(&lines[lineno - 1], &size, stdin) > 0);

        /* Print some numbers for making sure all is working */
        printf("NUM_LINES: %d, TAIL: %d\n ------------------\n", lineno, tail);
        
        /* Print the tail; lines requested */
        for(unsigned char i = (lineno > tail ? lineno - tail : 0); i < lineno; i++)
            printf("%s\n", lines[i]);
        
        /* Free allocated memory */
        for(unsigned i = 0; i < lineno; i++)
            free(lines[i]);
    }

    return 0;
}