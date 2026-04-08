#include <stdio.h>

int main(void) {
    int values[5];

    for(int i = 0; i < 5; i++){
        printf("Inserire il valore %d: ", i);
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", values[i]);
    }
    
    printf("\n");
    
    return 0;
}