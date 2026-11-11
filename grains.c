#include "math.h"
#include "stdint.h"

uint64_t square(uint8_t index) {
    return pow(2, index);
}

uint64_t total(void) {
    uint64_t t = 0;
    for (int i = 1; i <= 64; i++) {
        t += square(i);
    }

    return t;
}

int main() {
    
}