#include <stdio.h>

int main() {

    printf("[Exercise 17]\n\n");

    int n;
    int sum = 0;
    
    printf("Enter a positive number: ");
    scanf("%d", &n);

        printf("The first %d natural numbers are:\n", n);

        for(int i = 1; i <= n; i++){
            printf("%d", i);
            sum = sum + i;
    
        }

       printf("\nSum = %d\n", sum);

    return 0;

}
