#include <stdio.h>

int main() {

    printf("[Exercise 34]\n\n");

    int a, b, mcd;
    int x, y;

    printf("Enter two number\n");
    scanf("%d %d", &a, &b);

    x = a;
    y = b;

        while(y != 0){

            int rest = x % y;
            x = y;
            y = rest;
            
        }

        mcd = x;

        int mcm = (a * b) / mcd;

        printf("MCM = %d\n", mcm);

    return 0;

}