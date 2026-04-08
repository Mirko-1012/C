#include <stdio.h>

int main(){

    printf("[Exercise 1]\n\n");

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

        if(n > 0){

            printf("The number is positive\n");

        } else if(n == 0){

            printf("The number is equal to 0\n");

        } else {

            printf("The number is negative\n");

        }

    return 0;

}