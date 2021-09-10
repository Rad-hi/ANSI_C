/* This is an edited version of the quicksort algorithm in the book */

/* ----------------------------------------------------------------------- */

#ifndef __Q_SORT_H__
    #define __Q_SORT_H__

    #include <stdio.h>
    #include <ctype.h>
    
    /* Bitmasks */
    #define NUMERIC_BMSK        0x80
    #define REVERSE_BMSK        0x40
    #define FOLDING_BMSK        0x20
    #define DIRECTORY_BMSK      0x10
    
    void my_qsort(void *v[], int left, int right,
                  unsigned char flag, int (*comp)(void *, void *));

#endif // __Q_SORT_H__