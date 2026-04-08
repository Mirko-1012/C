#include <stdio.h>

int main() {

    printf("[Exercise 37]\n\n");


    int n, number;
    int positives = 0, negatives = 0, zeros = 0;

    printf("Enter the number of values: ");
    scanf("%d", &n);

        for(int i = 0; i < n; i++){
            printf("Enter number %d: ", i+1);
            scanf("%d", &number);

            if(number > 0) 
                positives++;

            else if(number < 0) 
                negatives++;

            else zeros++;
            
        }

        printf("Positives: %d\n", positives);
        printf("Negatives: %d\n", negatives);
        printf("Zeros: %d\n", zeros);

    return 0;
    
}