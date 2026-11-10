#include <stdio.h>

// one way to define constant: using #define. 
// compiler infers type from value specified
#define GREET "Welcome to year %i.\n" // GREET's type is char*

int main() {
    // constants convention: use upper-case
    const int YEAR = 2026;
    const char* MONTH = "November";

    // Modifying constants would raise compiler error
    // AGE = 2027; >> error: assignment of read-only variable ‘YEAR’

    // This will also lead to the same error (GREET is a const defined with #define)
    // GREET = "This is year %i.";

    printf(GREET, YEAR);
    printf("We're in %s.\n", MONTH);
    
}