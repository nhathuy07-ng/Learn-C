#include <stdio.h>

int steps(int start) {
    int cur = start;
    int steps = 0;
    while (cur != 1) {
        if (cur % 2 ==0) {
            cur /= 2;
        } else {
            cur *= 3;
            cur += 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    printf("%i", steps(12));
}