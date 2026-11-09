#include <stdio.h>
#include <limits.h>

int main() {
    char c = 120; // from -128 to 127
    int i = 123456789;

    // Int ranges from: -2147483648 to 2147483647
    int i_max = INT_MAX;
    int i_min = INT_MIN;

    // Short ranges from: -32768 to 32767
    short s_min = SHRT_MIN;
    short s_max = SHRT_MAX;

    printf("c = %i\n", c);
    printf("i = %i\n", i);
    printf("Int ranges from: %i to %i (%i bits)\n", i_min, i_max, INT_WIDTH);
    printf("Short ranges from: %i to %i (%i bits)\n", s_min, s_max, SHRT_WIDTH);

    // printf: use %li to interpolate long ints
    // Long ranges from: -9223372036854775808 to 9223372036854775807 (64 bits)
    printf("Long ranges from: %li to %li (%i bits)\n", LONG_MIN, LONG_MAX, LONG_WIDTH);
    
    // printf: use %lu for unsigned long ints
    printf("Unsigned long max value: %lu\n", ULONG_MAX);

    // Overflow
    // Signed case
    int i_of = i_max + 1;
    printf("%i\n", i_of); // int: wraps around to minimum/maximum value
    printf("%i\n", i_min-1);

    // if explicitly incrementing _MAX/_MIN constants 
    // => compiler warning
    // same wraparound behavior for long and short
    printf("%li\n", LONG_MAX+1); 

    short s_of = s_max + 1;
    printf("%d\n", s_of+1); 

    // Format specifier dictates how signed integers are shown
    char c_of = 127;
    c_of += 10;

    // %i - shows "-119", which is the value of c_of
    printf("%i\n", c_of); 
    
    // %u - cast c_of to unsigned int, resulting in astronomical outcome
    // since the negative int's 2's complement binary representation is being interpreted
    // as unsigned int
    printf("%u\n", c_of); 
}