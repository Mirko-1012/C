#include <stdio.h>
#define N 2

void printArray(int array[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%d  ", array[i]);
    }
}

void readArray(int array[], int length) {
    printf("Inserire gli elementi interi di un array \n");
    for(int i = 0; i < length; i++){
        printf("inserisci il %d° elemento: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int summarize(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum;
}

float avg(int sum, float elements) {
    return sum / elements;
}

int searchArrayLength() {
    int dim;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &dim);
    return dim;
}

int main() {
    //int votes[] = {2, 3, 1, 0, 4, 5, 6};
    //int length = sizeof(votes) / sizeof(votes[0]);

    int votes[N];
    int lengthArray = searchArrayLength();
    readArray(votes, lengthArray);
    printArray(votes, lengthArray);
    int sum = summarize(votes, lengthArray);
    float average = avg(sum, lengthArray);

    printf("\n");
} 