#include <stdio.h>

int main(){

    printf("[Exercise 15]\n\n");

    int n;
    int product = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

        for(int i = 1; i <= n; i++){

            product = product * i;

        }

        printf("The product of 1 to %d is %d\n", n, product);

    return 0;

}