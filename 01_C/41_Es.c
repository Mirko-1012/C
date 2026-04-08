#include <stdio.h>

int main() {

    printf("[Exercise 41]\n\n");

    int n;
    int sum = 0;
    float average;


    printf("How many numbers do you want to enter: ");
    scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int num;
            printf("Enter number %d: ", i + 1);
            scanf("%d", &num);
            sum += num;
        }

        average = sum / n;

    printf("Average = %.2f\n", average);

    return 0;

}