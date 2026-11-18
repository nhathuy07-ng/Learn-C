#include <stdio.h>
#include <string.h>

int main() {
    // declare a char array of length 5 (4 string chars + 1 terminator)
    // otherwise, certain functions would read thru adjacent memory objects until a terminator is reached
    char name[5] = {'S', 't', 'e', 'w'};
    char adj[4] = {'W', 'e', 't'};

    // alternatively
    char name_2[] = "Stew"; // name_2[5]
    char adj_2[] = "Wet"; // adj_2[4]

    printf("%s\n", name);

    int n = strlen(name);
    char name_cpy[n+1];
    strcpy(name_cpy, name);
    printf("%s\n", name_cpy);
    
    n = strlen(name) + strlen(adj);
    char name_adj[n+2]; // this initializes to random garbles (not empty string arr)
    
    // concatenation
    strcpy(name_adj, adj);
    strcat(name_adj, " ");
    strcat(name_adj, name);
    printf("%s\n", name_adj);

    // string comparison
    // for first i such that ord(A[i]) < ord(B[i]) --> A < B
    // if for i: A[i] terminates & B[i] non-terminating string --> A < B. 

    // in ASCII: A-Z has smaller index than that of a-z
    printf("%d\n", strcmp("abc", "abg")); // -1: string "abc" < string "abg"
    printf("%d\n", strcmp("abce", "abc")); // +1: string "abce" > string "abc"
    printf("%d\n", strcmp("stew", "stew")); // -1: string "stew" == string "stew"
    printf("%d\n", strcmp("Abc", "ab")); // -1: string "Abc" < string "ab"

}