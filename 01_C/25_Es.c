#include <stdio.h>

int main() {

    printf("[Exercise 25]\n\n");

    int number;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

        while(number > 0){

            int digit = number % 10;
            sum = sum + digit;
            number  = number / 10;

        }

        printf("The sum is: %d\n", sum);

    return 0;

}