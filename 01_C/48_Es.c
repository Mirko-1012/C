#include <stdio.h>

int main() {

    printf("[Exercise 48]\n\n");

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

        for(int i = 1; i <= n; i++) {

            if (n % i== 0) {

                printf("%d ", i);

            }

        }
        printf("\n");


    return 0;

}
