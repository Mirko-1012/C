#include <stdio.h>

int main() {

    printf("[Exercise 27]\n\n");

    int n;
    int inverted = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    int original = n;

        while(n > 0){

            int digit = n % 10;
            inverted = inverted * 10 + digit;
            n = n / 10;
            
        }

        if(inverted == original){

            printf("The number is a palindrome.\n");

        } else {

            printf("The number is not a palindrome.\n");

        }
        

    return 0;

}