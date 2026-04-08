#include <stdio.h>

int main() {

    printf("[Exercise 26]\n\n");

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

        while(n % 2 == 0){

            printf("You entered %d, which is even. Enter another number: ", n);
            scanf("%d", &n);

        }
        
        printf("You entered an odd number, cycle terminated\n");

    return 0;    

}