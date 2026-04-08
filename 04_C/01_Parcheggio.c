#include <stdio.h>

int calculateParkingCost(int minutes) {
    if (minutes <= 30) {
        return 1;
    } else if (minutes <= 120) {
        return 3;
    } else {
        return 3 + (minutes - 120 + 59) / 60; // Aggiunge 1 euro per ogni ora o frazione di ora oltre le prime 2 ore
    }
}

int main() {
    int minutes;
    int euro;

    printf("Insert minutes: ");
    scanf("%d", &minutes);
    
    euro = calculateParkingCost(minutes);
        
    printf("The parking cost is %d euros.\n", euro);
}