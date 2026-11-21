#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_pangram(const char *sentence) {
    // lowercase alphabet ascii code range: 97-122
    // uppercase alphabet ascii code range: 65-90

    bool* letter_exist = malloc(sizeof(bool) * 26); // 0: A/a (65/97), 1: B/b .... 

    char* d = (char*) sentence;

    strlen(sentence);

    while (true) {
        char c = *d;

        if (c == 0) {
            break;
        }

        int ord = c;

        if (ord >= 65 && ord <= 90) {
            letter_exist[ord-65] = 1;
        }

        if (ord >= 97 && ord <= 122) {
            letter_exist[ord-97] = 1;
        }

        d++;

    }

    for (int i = 0; i < 26; i++) {
        if (!letter_exist[i]) {
            return false;
        }
    }

    return true;
    
}

int main() {

    const char *sentence = "the quick brown fox jumps over the lAZy dog."; 
    // should return 1
    
    printf("%i", is_pangram(sentence));
}