#include <stdio.h>

int min_array(const int array[], int length) {
    int tmpMin = array[0];
    for(int i = 1; i < length; i++){
        if(array[i] < tmpMin) {
            tmpMin = array[i];
        }
    }
    return tmpMin;
}


int max(const int array[], int length) {
    int tmpMax = array[0];
    for(int i = 1; i < length; i++){
        if(array[i] > tmpMax) {
            tmpMax = array[i];
        }
    }
    return tmpMax;
}

int main(void) {
    int votes[8] = {2, 3, 3, 6, 4, 5, 7, 4};
    printf("Min: %d\n", min_array(votes, 8));
    printf("Max: %d\n", max(votes, 8));
    return 0;    
}
