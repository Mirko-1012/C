#include <stdio.h>

int main() {

    printf("[Exercise 49]\n\n");

    int pin = 1234;
    int attempts = 0;

    while (attempts < 3) {

        int input;
        
        printf("Enter your PIN: ");
        scanf("%d", &input);

        if (input == pin) {

            printf("Access granted.\n");
            break;

        } else {

            printf("Incorrect PIN. Try again.\n");
            attempts++;

        }

    }

    return 0;

}