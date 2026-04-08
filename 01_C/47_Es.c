#include <stdio.h>

int main() {

    printf("[Exercise 47]\n\n");

    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(i == j) {

                    printf("1 ");

                } else {

                    printf("0 ");

                }

            }

            printf("\n");
            
        }

    return 0;
}