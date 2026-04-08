#include <stdio.h>

int main() {

    printf("[Exercise 40]\n\n");

    int choice;
    float balance = 0;
    float amount;

    do {
        printf("\nATM MENU\n");
        printf("1. Check balance\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Current balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if(amount > 0) {
                    balance += amount;
                    printf("Deposit successful\n");
                } else {
                    printf("Invalid amount\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful\n");
                } else {
                    printf("Insufficient balance or invalid amount\n");
                }
                break;

            case 0:
                printf("Exiting ATM\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}
