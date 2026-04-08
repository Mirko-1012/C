#include <stdio.h>

int main() {

    printf("[Exercise 18]\n\n");

    int count = 0;

        for(int number = 1; number <= 100; number++){

            if(number % 3 == 0){
                count++;
            }
        }

        printf("There are %d numbers divisible by 3 between 1 and 100\n", count);

    return 0;

}
