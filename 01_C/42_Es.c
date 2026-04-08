#include <stdio.h>

int main() {

    printf("[Exercise 42]\n\n");

    int n;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &n);

        for (int row = 1; row <= n; row++) {

            for (int s = 1; s <= n - row; s++) {
                printf(" ");
            }

            for (int i = 1; i <= row; i++) {
                printf("%d", i);
            }

            for (int i = row - 1; i >= 1; i--) {
                printf("%d", i);
            }

            printf("\n");
            
        }       


    return 0;

}