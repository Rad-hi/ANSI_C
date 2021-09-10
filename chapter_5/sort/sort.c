/*
    PAGE: 108
    ---
    Ex: --- No specific ex to follow --- I kept adding options as I like from
        the various exercises from the end of 5.11 section.
    ---
    Exercise 5-14:
        Modify the sort program to handle a -r flag, which indicates sorting 
        in reverse (decreasing) order. Be sure that -r works with -n.
    
    Exercise 5-15:
        Add the option -f to fold upper and lower case together, so that case
        distinctions are not made during sorting; for example, a and A compare equal.
    
    Exercise 5-16:
        Add the -d (``directory order'') option, which makes comparisons only on
        letters, numbers and blanks. Make sure it works in conjunction with -f. 
 */

/* ------ CUSTOM INCLUDES ------ */

#include "my_qsort.h"
#include "numcmp.h"

/* ------ STD LIB INCLUDES ------ */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Input sizes */
#define MAXLINES            1024 /* Maximum number of lines to sort */
#define MAXLINE             1024 /* Maximum length of a line */

static char * lineptr[MAXLINES]; /* Array of pointers to text lines */

/* Functions' prototypes */
static int readlines(char *lineptr[], size_t nlines);
static void release_lines(char * lines[], int lineno);
static void writelines(char *lineptr[], int nlines);

void my_qsort(void **, int, int, unsigned char, int (*)(void *, void *));

/* sort input lines */
int main(int argc, char *argv[]){

    int nlines; /* number of input lines read */
    int c; /* Input char holder */
    register unsigned char flag = 0x00; /* This would hold flags for different options */

 
    
    /* Parse the input arguments -- Here we're incrementing argv (the pointer to pointers) */
    while (--argc > 0 && (*++argv)[0] == '-') /* Find all dashes; '-'s  */
        
        /* Here we're incrementing the pointer in the location argv is pointing at */
        while ((c = *++argv[0])) /* Find all arguments after the dash; '-' */
            switch (c) {
                
                case 'n': /* Numeric sort */
                    flag |= NUMERIC_BMSK;
                break;

                case 'r': /* Reversed sort */
                    flag |= REVERSE_BMSK;
                break;
                
                case 'f': /* Fold -- doesn't care for case; 'a' == 'A' */
                    flag |= FOLDING_BMSK;
                break;

                case 'd':
                    flag |= DIRECTORY_BMSK;
                break;

                default:
                    printf("Found: illegal option %c\n", c);
                    argc = 0;
                break;
            }

    /* There are lines to read */
    if((nlines = readlines(lineptr, (size_t)MAXLINES)) >= 0){
        
        my_qsort((void**) lineptr, 0, nlines-1, flag,
                (int (*)(void*,void*))(flag & NUMERIC_BMSK ? (void *)numcmp : strcmp));

        writelines(lineptr, nlines);
        
        release_lines(lineptr, nlines);
        return 0;
    }
    else{
         printf("input too big to sort\n");
         return 1;
    }
}

/* Read lines from the std input */
static int readlines(char * lines[], size_t size){
    int lineno = 0;
    char * line; /* POinter to a line */

    /* allocate memory for a line, add a ref to it in the tab of pointers, then fill it */
    do{
        line = (char *)malloc(MAXLINE * sizeof(char));
        *(lines + lineno) = line;
    }while(getline(&lines[lineno++], &size, stdin) > 0); /* Fill the current line, and advance */

    return lineno;
}

/* Release allocated memory for the lines */
static void release_lines(char * lines[], int lineno){
    /* Free allocated memory */
    for(unsigned i = 0; i < lineno; i++)
        free(lines[i]);
}

/* Write the sorted lines to the std output */
static void writelines(char *lineptr[], int nlines){
    for(unsigned i = 0; i < nlines; i++)
        printf("%s", *(lineptr + i));
}