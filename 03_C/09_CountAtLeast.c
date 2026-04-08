#include <stdio.h>

int count_at_least(const int array[], int length, int threshold){
    int count = 0;
    for(int i = 0; i < length; i++){
        if(array[i] >= threshold) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int votes[5] = {18, 22, 30, 19, 25};
    int count = count_at_least(votes, 5, 24);
    printf("Votes >= 24: %d\n", count);
    return 0;
}