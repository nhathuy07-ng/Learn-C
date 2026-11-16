#include <stdio.h>

int main() {
    int a = -135;
    
    if (a % 2 == 0) {
        printf("%i is even", a);
    } else {
        printf("%i is odd", a);
    }
    printf("\n");
    if (a > 0) {
        printf("%i is positive", a);
    } else if (a == 0) {
        printf("%i is neither positive nor negative", a);
    } else {
        printf("%i is negative", a);
    }

    printf("\n");
}
