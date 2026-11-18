#include <stdio.h>

typedef enum {A, B, C} t_test;

int main() {
    
    // enums are auto-numbered from 0 onwards (as unsigned int)
    printf("%d %d %d\n", A, B, C);

    // out-of-bound int (does NOT raise error)
    t_test t = -1;
    printf("%d\n", t);

    // enums can be of any unsigned int
    
    // in this case, SIX = 6, SEVEN and EIGHT are autoincremented (7, 8)
    typedef enum {SIX = 6, SEVEN, EIGHT} number_enum_2;
    printf("%d %d %d\n", SIX, SEVEN, EIGHT);

    typedef enum {D_ZERO = 0, D_ONE = 1, D_TWO = 10} binary;
    printf("%d %d %d\n", D_ZERO, D_ONE, D_TWO);

    // CAN'T redeclare enums within the same scope 
    // will get: error: redeclaration of enumerator for each redeclared enum value
    // typedef enum {D_ZERO = 0, D_ONE = 1, D_TWO = 2} bin_2;


}