#include <stdio.h>

int main() {
    // C arrays are fixed-size, fixed-type
    int numbers[5] = {10, 23, 51, 79, 112};

    // numbers: pointer to the first array element
    printf("numbers points to %i, numbers[0] points to %i\n", numbers, &numbers[0]);

    // C arrays are stored sequentially (each taking up 4 1-byte blocks)
    for (int i = 0; i < 5; i++) {
        int mem_addr_i = (int)&numbers[i];
        int mem_addr_root = (int)&numbers;
        printf("numbers[%i] at %i (offset %i from first value)\n", i, &numbers[i], mem_addr_i - mem_addr_root);
    }

    // loop thru array using index
    for (int i = 0; i < 5; i++) {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    // update value at index
    numbers[3] = 67;
    for (int i = 0; i < 5; i++) {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    // Trying to write out of array's bound leads to a segmentation fault
    const bool TRIGGER_WRITE_OUT_OF_BOUND = false;
    if (TRIGGER_WRITE_OUT_OF_BOUND) {
        numbers[10] = 10;
    }

}