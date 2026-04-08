#include <stdio.h>

int main(){

    printf("[Exercise 21]\n\n");

    int n;
    int sum = 0;
    
    printf("Enter a number\n");
    scanf("%d", &n);

        while(n!=0){

            sum += n;
            printf("Enter another number or 0 to stop\n");
            scanf("%d", &n);        
        }

        printf("The sum of the numbers entered is: %d\n", sum);

    return 0;

}