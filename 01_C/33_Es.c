#include <stdio.h>

int main() {

    printf("[Exercise 33]\n\n");

    int a, b;
    int rest;

    printf("Enter two number\n");
    scanf("%d %d", &a, &b);

        while(b != 0){
            
            rest = a % b;
            a = b;
            b = rest;

        }

        printf("MCD = %d\n", a);

    return 0;

}