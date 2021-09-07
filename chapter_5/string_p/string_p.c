/*
    PAGE: 96
    ---
    Ex: Write versions of the library functions strncpy, strncat, and strncmp, 
        which operate on at most the first n characters of their argument 
        strings. For example, strncpy(s,t,n) copies at most n characters of t to s. 
        Full descriptions are in Appendix B.
 */

#include <stdio.h>

/* Macro for returning the min of two values */
#define MIN(X, Y)             ((X) < (Y) ? (X) : (Y))

/* Maximum lengths for treated strings */
#define MAX_DESTINATION_LEN   100
#define MAX_SOURCE_LEN        99

/* Our custom functions' prototypes */
void my_strncpy(char * s, char * t, unsigned n);
void my_strncat(char * s, char * t, unsigned n);
int my_strncmp(char * s, char * t, unsigned n);

/* --------------------------------------------------------------------------------- */

int main(){
    char s[MAX_DESTINATION_LEN] = "Hello world!", t[MAX_SOURCE_LEN] = "hello";
    unsigned n = 0;

    printf("--- ORIGINALS --- \nS: %s, T: %s\n", s, t);
    printf("--- TREATED --- \nCOMPARISON: %d\n", my_strncmp(s, t, 6));

    my_strncat(s, t, 6);
    printf("CONCATENATION: %s\n", s);

    my_strncpy(s, t, 6);
    printf("COPY: %s\n", s);

    return 0;
}

/* --------------------------------------------------------------------------------- */

void my_strncpy(char * s, char * t, unsigned n){
    /* Copy the string t into s */
    for(unsigned j = 0; (*s++ = *t++) != '\0' && j < MIN(MAX_DESTINATION_LEN, n); j++);
}

void my_strncat(char * s, char * t, unsigned n){
    /* i will hold the length of the string inside s, 
       j will guarantee we don't try to overflow s with t 
     */
    unsigned i = 0, j = 0;

    /* Skip the original string */    
    while(*s++ != '\0' && i++ < MAX_DESTINATION_LEN); 

    /* We read too far, and we need to step back in order to erase the '\0' char */
    s--;
    
    /* Concatenate the strings */
    for(j = i; (*s++ = *t++) != '\0' && j < MIN(MAX_DESTINATION_LEN, n) + i; j++);
}

int my_strncmp(char * s, char * t, unsigned n){
    unsigned j = 0;

    /* Concatenate the strings */
    for(j; *s++ != *t++ && j < MIN(MAX_DESTINATION_LEN, n); j++);

    /* Compare */
    if(j == n)
        return 0; /* euqal */
    else if(*--s > *--t) 
        return 1; /* s is bigger */
    else
        return -1; /* t is bigger */
}
