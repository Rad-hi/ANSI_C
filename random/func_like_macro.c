#include <stdio.h>
#include <stdlib.h>

/* A debug macro for easy debugging code removal,
   Comment the next line if you want to print nothing */
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
    #define DEBUG(X...) printf(X)
#else   
    #define DEBUG(X...) // Nothing
#endif

#define MIN(A, B) ({\
    /* We can assert that type A and type B are the same here */\
    typeof(A) _a = (A), _b = (B);\
    _a < _b ? _a : _b;\
})

#define MAX(A, B) ({\
    /* We can assert that type A and type B are the same here */\
    typeof(A) _a = (A), _b = (B);\
    _a > _b ? _a : _b;\
})

#define SWAP(A, B) ({\
    typeof(A) _temp;\
    _temp = (A), (A) = (B), (B) = _temp;\
})

int main(){

    int a, b;
    float c, d;
    char e, f;
    char o, t;

    a = 12, b = 1;
    c = 1.65, d = 1.66;
    e = 'J', f = 'j';
    o = 'a', t = 'b';

    DEBUG("MIN(%-4d, %-4d) --> %-4d\n", a, b, MIN(a, b));
    DEBUG("MAX(%2.2f, %2.2f) --> %2.2f\n", c, d, MAX(c, d));
    DEBUG("MIN(%-4c, %-4c) --> %-4c\n", e, f, MIN(e, f));

    DEBUG("SWAP(%c, %c) ", o, t);
    SWAP(o, t);
    DEBUG("--> %c, %c\n", o, t);

    return 0;
}