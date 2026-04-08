#include <stdio.h> 

int main() { 
    int a = 7;
    int b = 5; 

    int sum = a + b;
    float average = (sum) / 2.0;

    printf("The sum of %d and %d is: %d\n", a, b, sum);
    printf("The average is: %.2f\n", average);
    return 0; 
}