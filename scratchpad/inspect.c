#include <stdlib.h>
#include <stdio.h>
#define NUM_READINGS 6

int inspect(void) {
    int readings[NUM_READINGS] = {14, 27, 35, 42, 58, 63};
    int *copy = (int *)malloc(NUM_READINGS * sizeof(int));
    int *cursor;
    for (int i = 0; i < NUM_READINGS; i++) {
        copy[i] = readings[i] + 2;
        cursor = &readings[i];
    }
    cursor -= 2;
    int answer = *cursor;
    free(copy);
    return answer;
}

int main() {
    printf("%i", inspect());
}
