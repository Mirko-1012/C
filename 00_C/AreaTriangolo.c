#include <stdio.h> 

int main() { 
    int base = 7;
    int height = 5; 

    float area = (base * height) / 2.0;

    printf("The base is %d and the height is %d\n", base, height);
    printf("The area of triangle is: %.2f\n", area); 
    return 0; 
}