#include <stdio.h>

int main(){

    printf("[Exercise 14]\n\n");

    int n;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

        for(int i = 1; i <= n; i++){

            sum = sum + i;

        }

        printf("The sum of 1 to %d is %d\n", n, sum);

    return 0;

}