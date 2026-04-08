#include <stdio.h>

int sum = 0;
int count = 0;
int positives = 0;
int negatives = 0;

int countNumbers(){
    int number;

    printf("Insert a number (0 to end): ");
    scanf("%d", &number);

    while(number != 0){
        count++;
        sum += number;

        if(number < 0){
            negatives++;
        } 
        else if(number > 0){
            positives++;
        }

        printf("Insert a number (0 to end): ");
        scanf("%d", &number);
    }
}

int sumNumbers(){
    return sum;
}

int main(){

    countNumbers();

    printf("You have inserted %d numbers\n", count);
    printf("The sum of the inserted numbers is: %d\n", sumNumbers());
    printf("You have inserted %d negative numbers, %d positive numbers\n", negatives, positives);

    return 0;
}