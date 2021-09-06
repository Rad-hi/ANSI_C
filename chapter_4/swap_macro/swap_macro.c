/*
    PAGE: 81
    ---
    Ex: Define a macro swap(t,x,y) that interchanges two arguments 
        of type t. (Block structure will help.) 
 */

#include <stdio.h>

/* A macro to swap the values of X and Y using T */
#define SWAP(T, X, Y) ((T) = (X), (X) = (Y), (Y) = (T))

int main(){

    int x, y, t;

    printf("%s\n", "Enter 1st number (X)");
    scanf("%d", &x);

    printf("%s\n", "Enter 2nd number (Y)");
    scanf("%d", &y);

    SWAP(t, x, y);

    printf("X: %d, Y: %d\n", x, y);

    return 0;
}