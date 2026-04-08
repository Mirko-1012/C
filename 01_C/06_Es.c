#include <stdio.h>

int main(){

    printf("[Exercise 6]\n\n");

    int vote;

    printf("Enter a vote: ");
    scanf("%d", &vote);

        if(vote >= 0 && vote < 18){

            printf("The vote is insufficient\n");

        } else if(vote >= 18 && vote < 24){

            printf("The vote is enough\n");

        } else if(vote >= 24 && vote < 27){

            printf("The rating is good\n");

        } else if(vote >= 27 && vote <= 30){

            printf("The rating is excellent\n");

        } else {

            printf("The vote entered is invalid\n");

        }

    return 0;

}