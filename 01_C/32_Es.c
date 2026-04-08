#include <stdio.h>

int main() {

    printf("[Exercise 32]\n\n");

    int n;
    int n_prime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);
    
        if(n <= 1){

            n_prime = 0;

        } else {

            for(int i = 2; i < n; i++){
                if(n % i == 0){
                    n_prime = 0;
                    break;
                }
            }
        }

        if(n_prime){

            printf("%d is a prime number\n", n);

        } else {

            printf("%d is not a prime number\n", n);

        }

    return 0;

}