#include <stdio.h>

int main() {

    printf("[Exercise 19]\n\n");

    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

        if(n <=0){

            printf("Error: N must be positive.\n");
            return 1;

        }

        printf("The squares of numbers from 1 to %d are:\n", n);

        for(int i = 1; i <= n; i++){
            int square = i * i;
            printf("%d^2 = %d\n", i, square);
        }
    return 0;
}