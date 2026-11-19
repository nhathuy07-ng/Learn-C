#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Some examples
0 → zero
1 → one
12 → twelve
123 → one hundred twenty-three
1,234 → one thousand two hundred thirty-four
*/

char* tenths[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char* ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

char* spell_tenths(int a) {
    int tenth = a / 10;
    int oneth = a - tenth*10;

    if (tenth > 9) {
        return NULL;
    }

    if (tenth == 1) {
        return teens[oneth];
    }

    if (oneth == 0) {
        return tenths[tenth-1]; // "ten" is at index 0
    }

    if (tenth == 0) {
        return ones[oneth-1]; // "one" is at index 0
    }

    char* buf = malloc(sizeof(char) * 50);
    sprintf(buf, "%s-%s", tenths[tenth-1], ones[oneth-1]);
    return buf;
}

char* spell_hundreds(int a) {
    int hundredth = a / 100;
    int tenth = a - hundredth*100;

    if (hundredth > 9) {
        return NULL;
    }

    if (hundredth == 0) {
        return spell_tenths(tenth);
    }

    if (tenth == 0) {
        char* buf = malloc(sizeof(char) * 80);
        sprintf(buf, "%s hundred", ones[hundredth-1]);
        return buf;
    }

    char* buf = malloc(sizeof(char) * 80);
    sprintf(buf, "%s hundred %s", ones[hundredth-1], spell_tenths(tenth));
    return buf;
}

char* say(long input) {
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

    long billionth = input / 1000000000;
    long millionth = (input - billionth * 1000000000) / 1000000;
    long thousandth = (input - millionth * 1000000 - billionth * 1000000000) / 1000;
    long hundredth = input - thousandth * 1000 - millionth * 1000000 - billionth * 1000000000;

    char* ans = malloc(sizeof(char) * 400);

    if (input == 0) {
        strcpy(ans, "zero");
        return 0;
    }

    if (input > 999999999999) {
        strcpy(ans, "out of range");
        return ans;
    }

    if (input < 0) {
        return "out of range";
    }
    
    strcpy(ans, "");
    if (billionth > 0) {
        strcat(ans, spell_hundreds(billionth));
        strcat(ans, " billion");
        if (millionth > 0 || thousandth > 0 || hundredth > 0) {
            strcat(ans, " ");
        }
    }
    if (millionth > 0) {
        strcat(ans, spell_hundreds(millionth));
        strcat(ans, " million");
        if (thousandth > 0 || hundredth > 0) {
            strcat(ans, " ");
        }
    }
    if (thousandth > 0) {
        strcat(ans, spell_hundreds(thousandth));
        strcat(ans, " thousand");
        if (hundredth > 0) {
            strcat(ans, " ");
        }
    }
    if (hundredth > 0) {
        strcat(ans, spell_hundreds(hundredth));
    }

    return ans;
    
}


int main() {
    long input = 67;
    printf("%s\n", say(input));
}