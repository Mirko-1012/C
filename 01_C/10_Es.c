#include <stdio.h>

int main() {

    printf("[Exercise 10]\n\n");

    int side1;
    int side2;
    int side3;

    printf("Insert three sides:\n");
    scanf("%d %d %d", &side1, &side2, &side3);

        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {

            printf("It's not a triangle\n");

        } else if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {

            printf("It's a triangle\n");

        } else {

            printf("It's not a triangle\n");
        }

    return 0;
}
