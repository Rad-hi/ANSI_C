#include "my_qsort.h"

static unsigned char is_directory(char c);
static void swap(void *v[], int i, int j);
    

static char * st, * nd;

/* qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right,
              unsigned char flag, int (*comp)(void *, void *)){

    int i, last;
    
    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    
    swap(v, left, (left + right)/2);
    last = left;
    
    for (i = left+1; i <= right; i++){
        st = (char *)v[i];
        nd = (char *)v[left];


        /* Ignore non alphanumerics, and non blancs <--> symbols */
        if(flag & DIRECTORY_BMSK && !is_directory(*st)) continue;

        /* If we're in folding mode, work with all lowercases */
        char one = (flag & FOLDING_BMSK) ? tolower(*st) : *st;
        char two = (flag & FOLDING_BMSK) ? tolower(*nd) : *nd;

        if(flag & REVERSE_BMSK){ /* Ascending order :: -r */
            if((*comp)((void *)(flag & NUMERIC_BMSK ? st : &one), 
                       (void *)(flag & NUMERIC_BMSK ? nd : &two)) < 0)
                swap(v, ++last, i);
        }
        else{ /* Descending order */
            if((*comp)((void *)(flag & NUMERIC_BMSK ? st : &one), 
                       (void *)(flag & NUMERIC_BMSK ? nd : &two)) > 0)
                swap(v, ++last, i);
        }
    }
    
    swap(v, left, last);
    my_qsort(v, left, last-1, flag, comp);
    my_qsort(v, last+1, right, flag, comp);
}

static void swap(void *v[], int i, int j){
    void * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
} 

static unsigned char is_directory(char c){
    return (isalnum(c) || c == ' ' || c == '\t');
}