#include <stdio.h>

int main() {
    int rows;
    int row = 1;

    printf("Insert the number of rows: ");
    scanf("%d", &rows);

    while (row <= rows) {
        printf("%d\n", row * row);
        row++;
    }
}
