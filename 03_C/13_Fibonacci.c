#include <stdio.h>

int readInt(const char prompt[]) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

int main(void) {
    int n = readInt("Enter a number of Fibonacci terms to print: ");

    if (n <= 0) {
        printf("The number of terms is not valid: %d.\n", n);
        return 0;
    }

    int a = 0;
    int b = 1;

    printf("The first %d Fibonacci numbers are: ", n);

    for(int i = 0; i < n; i++){
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
    return 0;
}