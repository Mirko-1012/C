#include <stdio.h>

int main() {

    printf("[Exercise 38]\n\n");

    int n;
    int num;
    int min, max;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    printf("Enter the number/s: ");
    scanf("%d", &num);

    min = num;
    max = num;

        for(int i = 2; i <= n; i++){
            printf("Enter number %d: ", i);
            scanf("%d", &num);

            if(num > max){
                max = num;
            }

            if(num < min){
                min = num;
            }
        }

        printf("Minimum: %d\n", min);
        printf("Maximum: %d\n", max);

    return 0;
}
