#include <stdio.h>

int main(){

    printf("[Exercise 7]\n\n");

    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

        if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){

            printf("It's a leap year\n");

        } else {

            printf("The year is not a leap year\n");

        }

    return 0;

}