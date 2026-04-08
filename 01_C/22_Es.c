#include <stdio.h>

int main() {
    
    printf("[Exercise 22]\n\n");

    int n;
    int max = -1;

    printf("Enter a number: ");
    scanf("%d", &n);

        while(n >= 0){
            if(n > max){
                max = n;
            }

            printf("Enter another number or negative number to stop: ");
            scanf("%d", &n);
        }

            if(max >= 0){
                printf("The greatest number is: %d\n", max);
            } else {
                printf("No non-negative numbers were entered.\n");
            }

    return 0;
}
