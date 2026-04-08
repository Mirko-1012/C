#include <stdio.h>

int main() {

    printf("[Exercise 38]\n\n");

    int choice;

        do {
            printf("\nMENU\n");
            printf("1. Option 1\n");
            printf("2. Option 2\n");
            printf("0. Exit\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You selected option 1\n");
                    break;

                case 2:
                    printf("You selected option 2\n");
                    break;

                case 0:
                    printf("Exiting the program\n");
                    break;

                default:
                    printf("Invalid choice\n");
            }

        } while(choice != 0);

    return 0;
}
