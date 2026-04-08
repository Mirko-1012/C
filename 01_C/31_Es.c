#include <stdio.h>

int main() {

    printf("[Exercise 31]\n\n");

        for( int n = 2; n <= 100; n++){

            int n_prime = 1;
            
            for(int i = 2; i < n; i++){

                if(n % i == 0){

                    n_prime = 0;
                    break;

                }

            }        

            if(n_prime){
                printf("%d ", n);
                
            }

        }

        printf("\n");

    return 0;

}