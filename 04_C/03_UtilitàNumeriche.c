#include <stdio.h>
#include <stdlib.h>

int readNumber(char prompt[]){ // Funzione per leggere un numero intero da input
    int number;
    printf("%s", prompt); // Stampa il prompt per l'utente
    scanf("%d", &number); // Legge un numero intero da input e lo memorizza nella variabile 'number'
    return number; 
}

int isEven(int n){
    if(n % 2 == 0){ // Controlla se il numero è divisibile per 2 (cioè se è pari)
        printf("%d is even.\n", n);
        return 1; // Dato che è pari, restituisce 1 (vero)
    } else {
        printf("%d is odd.\n", n);
        return 0; // Dato che è dispari, restituisce 0 (falso)
    }
}

int absInt(int n){
    return abs(n); // Restituisce il valore assoluto di n utilizzando la funzione abs() della libreria stdlib.h
}

int maxInt(int a, int b){
    if (a > b) {
        return a; // Se a è maggiore di b, restituisce a
    } else {
        return b; // Altrimenti, restituisce b
    }
}

int main(){
    int num1 = readNumber("Insert a number: "); // Chiama la funzione readNumber per leggere un numero intero da input e lo memorizza nella variabile num1
    int num2 = readNumber("Insert another number: "); // Chiama la funzione readNumber per leggere un altro numero intero da input e lo memorizza nella variabile num2

    isEven(num1); // Chiama la funzione isEven per verificare se num1 è pari o dispari
    isEven(num2); // Chiama la funzione isEven per verificare se num2 è pari o dispari

    int absoluteValue1 = absInt(num1); // Chiama la funzione absInt per calcolare il valore assoluto di num1 e lo memorizza nella variabile absoluteValue1
    int absoluteValue2 = absInt(num2); // Chiama la funzione absInt per calcolare il valore assoluto di num2 e lo memorizza nella variabile absoluteValue2
       

    printf("The absolute value of %d is %d.\n", num1, absoluteValue1); // Stampa il valore assoluto di num1 
    printf("The absolute value of %d is %d.\n", num2, absoluteValue2);

    printf("The maximum of %d and %d is %d.\n", num1, num2, maxInt(num1, num2)); // Chiama la funzione maxInt per trovare il massimo tra num1 e num2 e stampa il risultato

}