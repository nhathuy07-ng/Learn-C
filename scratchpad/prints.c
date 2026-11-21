#include <stdio.h>
void update(int x, int *pointer) {
    *pointer = x - 4;
    printf("Print 3: x = %d\n", x);
}
int modify(int x, int *pointer) {
    int old = *pointer;
    printf("Print 1: x = %d\n", x);
    *pointer = x + 5;
    printf("Print 2: x = %d\n", x);
    return old + *pointer + 2;
}
int main(void) {
    int x = 7;
    int *pointer = &x;
    update(modify(x, pointer), pointer);
    printf("Print 4: x = %d\n", x);
    return 0;
}
