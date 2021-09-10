#ifndef __Q_SORT_H__
    #define __Q_SORT_H__
    

    static void swap(void *v[], int i, int j);
    void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *));

    /* ----------------------------------------------------------------------- */

    /* qsort: sort v[left]...v[right] into increasing order */
    void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *)){
        int i, last;
        void swap(void *v[], int, int);
        
        if (left >= right) /* do nothing if array contains */
            return; /* fewer than two elements */
        
        swap(v, left, (left + right)/2);
        last = left;
        
        for (i = left+1; i <= right; i++)
            if ((*comp)(v[i], v[left]) < 0)
        
        swap(v, ++last, i);
        swap(v, left, last);
        my_qsort(v, left, last-1, comp);
        my_qsort(v, last+1, right, comp);
    }

    static void swap(void *v[], int i, int j){
        void *temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    } 
#endif // __Q_SORT_H__
    