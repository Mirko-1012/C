#include <stdio.h> 

int main() { 
    int a = 7;
    int b = 5; 
    int max;

    if(a >= b){
        max = a;
    } else {
        max = b;
    }

    printf("The number %d is the greater\n", max);

    return 0; 
}