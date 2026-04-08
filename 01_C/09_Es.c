#include <stdio.h>

int main() {

    printf("[Exercise 9]\n\n");

    char carattere;

    printf("Enter a letter: ");
    scanf(" %c", &carattere);

        if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u' ||
            carattere == 'A' || carattere == 'E' || carattere == 'I' || carattere == 'O' || carattere == 'U') 
        
        {

            printf("The letter entered is a vowel\n");

        } else {

            printf("The inserted letter is a consonant\n");
            
        }

    return 0;
}
