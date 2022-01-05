#include <stdio.h>
#include <stdlib.h>

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

    printf("MIN(%-4d, %-4d) --> %-4d\n", a, b, MIN(a, b));
    printf("MAX(%2.2f, %2.2f) --> %2.2f\n", c, d, MAX(c, d));
    printf("MIN(%-4c, %-4c) --> %-4c\n", e, f, MIN(e, f));

    printf("SWAP(%c, %c) ", o, t);
    SWAP(o, t);
    printf("--> %c, %c\n", o, t);

    return 0;
}