#include <stdio.h>

int main() {


    // If odd: counts from current number down to 5
    // If even: counts from current number down to 0

    int n = 9;

    while (n >= 0) {
        printf("%i ", n);
        if (n == 5) {
            break;
        }
        n -= 2;
    }

    printf("\n");

}