#include <stdio.h>

int readInt(const char prompt[]) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

int main(void) {
    int n = readInt("Inserisci un numero (limite superiore): ");

    if (n < 0) {
        printf("Non esistono termini di Fibonacci non negativi <= %d.\n", n);
        return 0;
    }

    int a = 0;
    int b = 1;

    printf("Fibonacci <= %d: ", n);

    while (a <= n) {
        printf("%d ", a);

        int next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
    return 0;
}