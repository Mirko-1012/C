#include <stdio.h>

int main(){

    printf("[Exercise 8]\n\n");

    int a;
    int b;
    char symbol;

    printf("Enter two numbers\n");
    scanf("%d %d", &a, &b);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &symbol);

        if(symbol == '+'){

            printf("The Result is: %d\n", a + b);

        }else if(symbol == '-'){

            printf("The Result is: %d\n", a - b);

        }else if(symbol == '*'){

            printf("The Result is: %d\n", a * b);

        }else if (symbol == '/') {

            if (b != 0)

                printf("The Result is: %d\n", a / b);

            else
            
                printf("Error\n");

        } else {

            printf("Invalid operator.\n");

        }

    return 0;

}