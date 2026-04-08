#include <stdio.h>

int main() {

    printf("[Exercise 24]\n\n");

    int number;
    int inverted = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

        while(number >0){

            int digit = number % 10;
            inverted = inverted * 10 + digit;
            number = number / 10;

        }

        printf("The inverted number is: %d\n", inverted);

    return 0;

}
