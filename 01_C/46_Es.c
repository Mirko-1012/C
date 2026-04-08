#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("[Exercise 46]\n\n");

    srand(time(NULL));

    int secret = rand() % 100 + 1;
    int guess = 0;

    printf("Guess the number (between 1 and 100): ");

        while(guess != secret) {
            scanf("%d", &guess);

            if(guess < secret) {

                printf("Too low! Try again: ");

            } else if(guess > secret) {

                printf("Too high! Try again: ");

            } else {

                printf("Congratulations! You guessed the number %d!\n", secret);

            }

        }

    return 0;

}