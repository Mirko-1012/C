#include <stdio.h>

int main() {

    printf("[Exercise 23]\n\n");

    int number;
    int count = 0;

    printf("Enter a positive number: ");
    scanf("%d", &number);

        if (number <= 0) {

            printf("Error\n");

        } else {

            while (number > 0) {
                number = number / 10;
                count++;
            }

            printf("The number has %d digits\n", count);
        }

    return 0;
}
