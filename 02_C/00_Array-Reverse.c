#include <stdio.h>
#define N 10

int main() {
    int a[N];

    printf("Inserisci %d numeri interi\n", N);

        for(int i = 0; i < N; i++) {

            printf("Numero: %d\n", i + 1);
            scanf("%d", &a[i]);

        }

        for(int i = N - 1; i >= 0; i--) {

            printf("%d ", a[i]);

        }

    printf("\n");

    return 0;

}