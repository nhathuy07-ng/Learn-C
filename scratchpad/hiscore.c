
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    output[0] = -1;
    output[1] = -1;
    output[2] = -1;

    for (size_t i = 0; i < scores_len; i++) {
        int32_t score = scores[i];
        if (score >= output[0]) {
            output[2] = output[1];
            output[1] = output[0];
            output[0] = score;
        } else if (score >= output[1]) {
            output[2] = output[1];
            output[1] = score;
        } else if (score >= output[2]) {
            output[2] = score;
        }
        printf("%i %i %i\n", output[0], output[1], output[2]);
    }


    if (output[0] == -1 && output[1] == -1 && output[2] == -1) {
        return 0;
    }

    if (output[1] == -1 && output[2] == -1) {
        return 1;
    }

    if (output[2] == -1) {
        return 2;
    }
    return 3;
    
}

int main() {
    int s[6] = {10, 50, 40, 20, 30, 90};
    int o[3];
    personal_top_three(s, 6, o);

    printf("%i %i %i", o[0], o[1], o[2]);

}