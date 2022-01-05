#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* ------------------------------------------------------------------ */
/* -------------------- BIT MANIPULATION MACROS --------------------- */
/* ------------------------------------------------------------------ */

/* Change the value of the Nth bit in a number (ZERO INDEXED) */
#define SET_NTH_BIT(X, N)   ((X) |= (0x1 << (N)))
#define RESET_NTH_BIT(X, N) ((X) &= ~(0x1 << (N)))

#define SIZE_IN_BITS(X)     (8 * sizeof(X))

/* ------------------------------------------------------------------ */
/* ------------------------ PRINTING MACROS ------------------------- */
/* ------------------------------------------------------------------ */

/* A debug macro for easy debugging code removal,
   Comment the next line if you want to print nothing */
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
    #define DEBUG(X...) printf(X)
#else   
    #define DEBUG(X...) // Nothing
#endif

/* Prints a number in binary format (up to 128 bits) */
#define PRINT_IN_BINARY(X) ({\
    for(int8_t i = SIZE_IN_BITS((X))-1; i >= 0; i--)\
        DEBUG(((X) & (0x1<<i)) ? "1" : "0");\
    DEBUG("\n");\
})

/* ------------------------------------------------------------------ */
/* ----------------------- COMPARING MACROS ------------------------- */
/* ------------------------------------------------------------------ */

#define MIN(A, B) ({\
    typeof(A) _a = (A), _b = (B);\
    _a < _b ? _a : _b;\
})

#define MAX(A, B) ({\
    typeof(A) _a = (A), _b = (B);\
    _a > _b ? _a : _b;\
})

/* ------------------------------------------------------------------ */
/* ------------------- VALUE MANIPULATION MACROS -------------------- */
/* ------------------------------------------------------------------ */

#define SWAP(A, B) ({\
    typeof(A) _temp;\
    _temp = (A), (A) = (B), (B) = _temp;\
})

/* ------------------------------------------------------------------ */
/* ------------------------------ MAIN ------------------------------ */
/* ------------------------------------------------------------------ */

int main(){

    int8_t a, b;
    float c, d;
    uint8_t e, f;

    a = 12, b = 1;
    c = 1.65, d = 1.66;
    e = 'J', f = 'j';

    /* Test :: comparison */
    DEBUG("MIN(%-4d, %-4d) --> %-4d\n", a, b, MIN(a, b));
    DEBUG("MAX(%2.2f, %2.2f) --> %2.2f\n", c, d, MAX(c, d));
    DEBUG("MIN(%-4c, %-4c) --> %-4c\n", e, f, MIN(e, f));

    /* Test :: swapping */
    DEBUG("SWAP(%c, %c) ", e, f);
    SWAP(e, f);
    DEBUG("--> %c, %c\n", e, f);

    /* Test :: bit manipulation */
    uint8_t flag = 0x00;
    PRINT_IN_BINARY(flag);

    for(uint8_t i = SIZE_IN_BITS(flag); i > 0; i--){
        if(i % 2) SET_NTH_BIT(flag, i);
    }
    PRINT_IN_BINARY(flag);

    for(uint8_t i = SIZE_IN_BITS(flag); i > 0; i--){
        if(i % 2) RESET_NTH_BIT(flag, i);
    }
    PRINT_IN_BINARY(flag);

    return 0;
}