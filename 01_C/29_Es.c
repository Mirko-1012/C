#include <stdio.h>

int main() {

    printf("[Exercise 29]\n\n");

    int password;

    printf("Enter a password: ");
    scanf("%d", &password);

        while (password != 1234){
            printf("Error, password wrong. Try again: ");
            scanf("%d", &password);
        }
        
        printf("Password correct\n");

    return 0;

}