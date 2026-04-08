#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("[Exercise 45]\n\n");

    int n;
    int occ[6] = {0};

    printf("How many times do you want to roll the die? ");
    scanf("%d", &n);

    srand(time(NULL));

        for (int i = 0; i < n; i++) {

            int roll = rand() % 6 + 1;
            occ[roll - 1]++;
            printf("%d ", roll);

        }

        printf("\n\nOccurrences:\n");

        for (int i = 0; i < 6; i++) {

            printf("%d appeared %d times\n", i + 1, occ[i]);

        }

    return 0;
}
