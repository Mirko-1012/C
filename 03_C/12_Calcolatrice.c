#include <stdio.h>

void printMenu() {
    printf("------ MENU ------");
    printf("\n1) Somma");
    printf("\n2) Differenza");
    printf("\n3) Moltiplicazione");
    printf("\n4) Divisione");
    printf("\n5) Resto");
    printf("\n0) Esci");
    printf("\n-------------------");
}

int readChoice(char prompt[]) {
    int choice;

    while (1){
        printf("\n\n%s", prompt);
        if(scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF){} // Clear the input buffer to handle invalid input 
            printf("\nScelta non consentita");
            continue;
        }
        return choice;
    }
}

float readFloat(char prompt[]) {
    float value;

    while (1){
        printf("\n\n%s", prompt);
        if(scanf("%f", &value) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF){}
            printf("\nScelta non consentita");
            continue;
        }
        return value;
    }
}

float sum(float a, float b) {
    return (float)a + b;
}

float difference(float a, float b) {
    return (float)a - b;
}

float multiplication(float a, float b) {
    return (float)a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("\nErrore: divisione per zero!");
        return 0;
    }
    return (float)a / b;
}

int mod(int a, int b) {
    if (b == 0) {
        printf("\nErrore: divisione per zero!");
        return 0;
    }
    return a % b;
}



void validateChoice(int value){
    if(value == 0) {
        printf("\nExit\n");
        return;
    }

    if(value < 1 || value > 5) {
        printf("\nScelta non consentita\n");
        return;
    }

    float value1 = readFloat("Inserisci il primo valore: ");
    float value2 = readFloat("Inserisci il secondo valore: ");

    switch (value)
    {
    case 1: {
        printf("\nHai scelto la Somma...\n");
        float sumValue = sum(value1, value2);
        printf("La somma dei valori dati è: %.2f", sumValue);
        break;
    }
    case 2: {
        printf("\nHai scelto la Differeenza...\n");
        float diffValue = difference(value1, value2);
        printf("La differenza dei valori dati è: %.2f", diffValue);
        break;
    }
    case 3: {
        printf("\nHai scelto la Moltiplicazione...\n");
        float mulValue = multiplication(value1, value2);
        printf("La moltiplicazione dei valori dati è: %.2f", mulValue);
        break;
    }
    case 4: {
        printf("\nHai sceltto la Divisione...\n");
        float divValue = division(value1, value2);
        printf("La divisione dei valori dati è: %.2f", divValue);
        break;
    }
    case 5: {
        printf("\nHai scelto il Resto...\n");
        int modValue = mod((int)value1, (int)value2);
        printf("Il resto dei valori dati è: %d", modValue);
        break;
    }
    default: 
        printf("\nScelta non consentita");
    }
}

void loopChoice() {
    int choice;
    do{
        printf("\n\n");
        printMenu();
        choice = readChoice("Scegli: ");
        validateChoice(choice);
    } while (choice != 0);
}


int main(){    
    loopChoice();
}
