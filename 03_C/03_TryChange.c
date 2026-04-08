#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

void printSomething(char prompt[]) {
    printf("%s\n", prompt);
}

void tryChange(int x) {
    x = 12345;
}

int tryChangeSuperSayan(int x) {
    x = 54321;
    return x;
}


int main() {
    int value = 200;
    printf("Value before change: %d\n", value);
    tryChangeSuperSayan(value);
    printf("Value after change: %d\n", value);
    

    /*printSomething("Inserisci 2 valori: ");
    int mySum = sum(100, 20);
    printf("The sum is: %d\n", mySum);*/
}