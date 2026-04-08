#include <stdio.h>

int main() {

    printf("[Exercise 50]\n\n");

    int n;
    int sum = 0;
    int count = 0;

    printf("Enter a positive number: ");

        while (sum <= 100){
            scanf("%d", &n);
            sum += n;
            count++;
        }

        printf("The sum is: %d\n", sum);
        
    return 0;
}
