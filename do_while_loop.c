#include <stdio.h>

int main() {
    // Calculate factorial using for loop

    int n = 5;
    long long result = 1;

    if (n < 0) {
        printf("Non-negative integers only.\n");
        return 1;
    }

    printf("%i! = ", n);
    int i = (n>0) ? n : 1;
    do {
        result *= i;
        printf("%i", i);
        
        if (i > 1) {
            printf("*");
        }
        i--;
    } while (i >= 1);
    printf(" = %lli\n", result);

}