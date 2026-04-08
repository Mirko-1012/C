#include <stdio.h>

float average_int_array(const int array[], int length) {
    float sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (float)sum / (float)length;
}

int main(void) {
    int votes[4] = {18, 24, 30, 21};
    float avg = average_int_array(votes, 4);
    printf("Media: %.2f\n", avg);
    return 0;
}