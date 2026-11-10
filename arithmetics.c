#include <stdio.h>

int main() {

    /*
    Some stuffs worth noting with C arithmetics
    */

    // dividing two ints a and b returns an int = floor(a/b)
    printf("%d\n", 5 / 2); 

    // to divide 2 ints and get floats -> promote 1 int to float
    printf("%f\n", (float)5 / 2);
    printf("%f\n", 5.0f / 2);

    // double / double = double
    // print double floats with %lf
    double a = 1024.45504543;
    double b = 33.867023032344;
    double c = a / b;
    // when printing doubles, need to specify precision (here, 16 decimals)
    printf("%.16lf\n", c);

    // float / float = float
    float fa = 5.0;
    float fb = 4.0;
    printf("%f\n", fa / fb); // 1.250000

    /* 
    a++ vs ++a 
    */

    int num = 67;
    // a++: use, then increment (same for a--)
    printf("Given num = 67, num++ returns: %d\n", num++);
    printf("num is now %d\n", num);
    int num2 = 67;
    // ++a: increment, then use (same for --a)
    printf("Given num2 = 67, ++num2 returns: %d\n", ++num2);
    printf("num2 is now %d\n", num2);

    /*
    Logical ops
    */

    // Used with booleans
    bool A = true;
    bool B = false;

    printf("A && B: %s\n", (A && B) ? "true" : "false"); // AND - false
    printf("A || B: %s\n", (A || B) ? "true" : "false"); // OR - true
    printf("!A: %s\n", (!A) ? "true" : "false"); // NOT A - false

    // Bitwise ops
    int bin_a = 0b1001;
    int bin_b = 0b0111;

    printf("%i\n", bin_a & bin_b); // 0b0001 = 1
    printf("%i\n", bin_a | bin_b); // 0b1111 = 15
    printf("%i\n", ~bin_a+1); // 1111....0111 = -9

}