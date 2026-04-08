#include <stdio.h>

int main(){

    printf("[Exercise 5]\n\n");
    
    int eta;

    printf("Enter a person's age: ");
    scanf("%d", &eta);

        if(eta >= 65){

            printf("Age of an elderly person\n");

        } else if(eta >= 18 && eta < 65){

            printf("Age of an adult\n");

        } else {

            printf("Age of a minor\n");

        }

    return 0;

}
