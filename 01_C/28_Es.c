#include <stdio.h>

int main() {

    printf("[Exercise 28]\n\n");

    int n;
    int i = 1;

    printf("Enter a number with which the cycle will end: ");
    scanf("%d", &n);

        while(i <= n){

            printf("%d\n", i);
            i++;

        }

    return 0;

}
