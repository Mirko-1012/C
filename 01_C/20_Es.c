#include <stdio.h>

int main() {

    printf("[Exercise 20]\n\n");

    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            printf("*");
        }

        printf("\n");

    return 0;

}