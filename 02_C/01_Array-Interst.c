#include <stdio.h>

int main(){

    float balance = 100.0; // Capitale iniziale

    int years; // Numero di anni per cui calcolare l'interesse
    printf("Inserisci il numero di anni: ");
    scanf("%d", &years);

    float interst; // Tasso di interesse annuale
    printf("Inserisci il tasso di interesse: ");
    scanf("%f", &interst);

    double capital[years]; // Array per memorizzare il capitale accumulato ogni anno

    capital[0] = balance * (1 + interst / 100); // Calcolo del capitale dopo il primo anno

        for(int i = 1; i < years; i++){
            capital[i] = capital[i-1] * (1 + interst / 100); // Calcolo del capitale per gli anni successivi, basato sul capitale accumulato dell'anno precedente
        }

        printf("Anno\tCapitale\n");

        for (int i = 0; i < years; i++) {
            printf("%d\t%.2f\n", i+1, capital[i]); // Stampa del numero dell'anno e del capitale accumulato, con due decimali
        }

    return 0;

}
