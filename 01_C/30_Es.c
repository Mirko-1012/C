#include <stdio.h>

int main() {

    printf("[Exercise 30]\n\n");

    int n;
    int i = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

        do{
            int prodotto = n * i;
            printf("%d x %d = %d\n", n, i, prodotto);
            i++;

        } while(i <= 10);

    return 0;

}