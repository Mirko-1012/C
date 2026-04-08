#include <stdio.h>

void print_int_array(const int array[], int length) {
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int values[5] = {10, 20, 30, 40, 50};
    print_int_array(values, 5);
    return 0;
}