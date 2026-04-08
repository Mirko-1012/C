#include <stdio.h>

int findPosition(int array[], int length, int value) {
    for(int i = 0; i < length; i++){
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int votes[8] = {2, 3, 3, 6, 4, 5, 7, 4};
    int length = sizeof(votes) / sizeof(votes[0]);
    int idx = findPosition(votes, length, 3);
    printf("La posizione del valore 3 è: %d\n", idx);
    return 0;
}
