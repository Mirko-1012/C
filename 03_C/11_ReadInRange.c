#include <stdio.h>

int readInRange(char prompt[], int minValue, int maxValue) {
    int value;

    while(1) {
        printf("%s", prompt);

        if(scanf("%d", &value) != 1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF){}
            continue;
        }

        if(value >= minValue && value <= maxValue){
            return value;
        }
    }
}

int analyzeScanf() { 
    int value;
    return scanf("%d", &value);
}

int main() {
    printf("%d\n", analyzeScanf());
}