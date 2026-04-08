#include <stdio.h>

int main() {

    printf("[Exercise 16]\n\n");

    int number = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

        for(int i = 0; i <= 10; i++){

            int prodotto = number * i;
            printf("%d x %d = %d\n", number, i, prodotto);

        }

    return 0;
}
