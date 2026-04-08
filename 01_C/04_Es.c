#include <stdio.h>

int main(){

    printf("[Exercise 4]\n\n");

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

        if(n % 2 == 0){

            printf("The number is even\n");

        } else {

            printf("The number is odd\n");

        }

    return 0;

}