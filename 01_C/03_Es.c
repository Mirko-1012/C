#include <stdio.h>

int main() {

    printf("[Exercise 3]\n\n");

    int a = 7;
    int b = 4;
    int c = 9;
    int max;

        if (a >= b && a >= c) {

            max = a;

        } else if (b >= a && b >= c){

            max = b;

        } else {

            max = c;
            
        }

    printf("The number %d is the greater\n", max);

    return 0;

}