#include <stdio.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0 && n != i) {
            return false;
        }
    }
    return true;
}

int count_primes(int* arr, int n) {
    printf("Primes: ");
    int primes = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (is_prime(num)) {
            printf("%i ", num);
            primes++;
        }
    }
    printf("\n");
    return primes;
}

int main() {
    // C arrays are fixed-size, fixed-type
    int numbers[6] = {2, 10, 23, 51, 79, 112};

    // numbers: pointer to the first array element
    // memory addresses in C on 64-bit systems are of type long (64-bit)
    printf("numbers points to %li, numbers[0] points to %li\n", (long)numbers, (long)&numbers[0]);

    // C arrays are stored sequentially (each taking up 4 1-byte blocks)
    for (int i = 0; i < 5; i++) {
        long mem_addr_i = (long)&numbers[i];
        long mem_addr_root = (long)&numbers;
        printf("numbers[%i] at %li (offset %li from first value)\n", i, mem_addr_i, mem_addr_i - mem_addr_root);
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

    int primes = count_primes(numbers, 6);
    printf("%i prime(s) in the list.\n", primes);


}