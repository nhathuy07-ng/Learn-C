#include <stdio.h>

/*
Some examples
0 → zero
1 → one
12 → twelve
123 → one hundred twenty-three
1,234 → one thousand two hundred thirty-four
*/

int say(long input) {
    /*
    Split into group of three digits

    splitter: use int division and subtraction 

    group_of_3 (XYZ):
        if zero: return NULL
        else:
            if X > 0: spell[X] hundred
            if 11 - 19: plan hardcoded list
            else: spell_tenth[X](Y != 0 ? '-' + spell[Y] : <blank>)
    merged:
        g3_1 billion g3_2 million g3_3 thousand g3_4 
        skip group_of_3 if it's NULL
    */
}

int main() {
    long input = 12;
    say(input);
}