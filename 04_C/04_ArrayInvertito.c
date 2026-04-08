#include <stdio.h>

void readArray(int arr[], int N) {
    printf("Insert %d elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void invertArray(int arr[], int N) {
    for (int i = 0; i < N / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }
}

int main() {
    int N;

    do {
        printf("Insert the number of elements (1-30): ");
        scanf("%d", &N);
    } while (N < 1 || N > 30);

    int arr[30];

    readArray(arr, N);

    printf("Original array: ");
    printArray(arr, N);

    invertArray(arr, N);

    printf("Inverted array: ");
    printArray(arr, N);
    
    return 0;
}