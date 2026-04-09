#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char brand[NAME_LENGTH];
    char category[NAME_LENGTH];
    float price;
    int quantity;
    int warranty;
    bool status;

} Product;

//By Mirko Di Natale
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

// By Pierfrancesco Blancato
int readInt(const char prompt[]) {
    int value;
    while (1) {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1) {
            return value;
        }

        clearBuffer();
        printf("Input not valid. Try again.\n");
    }
}

// By Pierfrancesco Blancato
float readFloat(const char prompt[]) {
    float value;
    while (1) {
        printf("%s", prompt);

        if (scanf("%f", &value) == 1) {
            return value;
        }

        clearBuffer();
        printf("Input not valid. Insert a real number.\n");
    }
}

// By Pierfrancesco Blancato
int readRange(const char prompt[], int min_value, int max_value) {
    int value;
    while (1){
        value = readInt(prompt);
        if (value >= min_value && value <= max_value) {
            return value;
        }

        printf("Error: Value out of range  (%d - %d).\n", min_value, max_value);
    }
}

// By Mirko Di Natale
void printMenu() {
    int choice;
    printf("\n--- ELECTRONICS STORE MANAGEMENT ---\n");
    printf("1. Insert new product\n");
    printf("2. Show all products\n");
    printf("3. Search product by code\n");
    printf("4. Update price\n");
    printf("5. Update available quantity\n");
    printf("6. Update product status\n");
    printf("7. Register sale\n");
    printf("8. Add stock\n");
    printf("9. Calculate total warehouse value\n");
    printf("10. Count products by category\n");
    printf("11. Find product with longest warranty\n");
    printf("12. Calculate average price\n");
    printf("13. Exit\n");
}

// N1 - By Mirko Di Natale - Inserimento nuovo prodotto
int addProduct(Product products[], int position) {
    if (position >= MAX_PRODUCTS) {
        printf("\nERROR: Warehouse is full!\n");
        return position;
    }

    printf("\n--- INSERT NEW PRODUCT ---\n");
    products[position].id = readInt("Code ID: ");

    printf("Name: ");
    scanf("%49s", products[position].name);
    clearBuffer();

    printf("Brand: ");
    scanf("%49s", products[position].brand);
    clearBuffer();

    printf("Category: ");
    scanf("%49s", products[position].category);
    clearBuffer();

    products[position].price = readFloat("Price: ");
    products[position].quantity = readInt("Quantity: ");
    products[position].warranty = readInt("Warranty (months): ");

    int statusChoice = readRange("Status (1 for Available, 0 for Not Available): ", 0, 1);
    products[position].status = (bool)statusChoice;

    printf("\n>>> Product '%s' added successfully!\n", products[position].name);

    return position + 1;
}

// N2 - By Pierfrancesco Blancato
void printAllProducts(Product products[], int countProduct) {
    if (countProduct == 0){
        printf("No products available.\n");
        return;
    }

    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    printf("| Cod | Name                 | Brand           | Cat          | Price    | Qty Avail. | Warr. (Mo) | Status     |\n");
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");

    for (int i = 0; i < countProduct; i++){
        printf("| %-3d | %-20s | %-15s | %-12s | %-8.2f | %-10d | %-10d | %-10s |\n",
               products[i].id,
               products[i].name,
               products[i].brand,
               products[i].category,
               products[i].price,
               products[i].quantity,
               products[i].warranty,
               products[i].status ? "Avb" : "Not Avb.");
    }
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
}


// N5 - By Pierfrancesco Blancato
/*void addQuantity(Product products[], int countProduct) {
    int index = searchProduct(products, countProduct);

    if (index == -1) {
        printf("\nProduct not found\n");
        return;
    }

    printf("\nSelected Product -> Code: %d, Name: %s, Actual Quantity: %d\n", products[index].id, products[index].name, products[index].quantity);

    int newQuantity = readInt("Enter a new quantity: ");
    products[index].quantity = newQuantity;

    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n", products[index].id, products[index].name, products[index].quantity);
}

// N10 - By Pierfrancesco Blancato
void countProductForCategory(Product products[], int countProduct) {
    if (countProduct == 0) {
        printf("No products available.\n");
        return;
    }
    char searchCategory[50];
    printf("Enter the category you wish to search: ");
    scanf("%49s", &searchCategory);
    int counter = 0;

    for (int i = 0; i <= countProduct; i++){
        if (strcmp(products[i].category, searchCategory) == 0) {
            counter++;
        }
    }
    printf("\nCategory '%s' contains %d product(s).\n", searchCategory, counter);
}*/

// By Mirko Di Natale
void runApplication() {
    Product products[MAX_PRODUCTS];
    int currentCount = 0;
    int choice;

    do {
        printMenu();
        choice = readInt("Choice: ");

        switch (choice) {
            case 1:
                currentCount = addProduct(products, currentCount);
                break;

            case 2:
                printAllProducts(products, currentCount);
                break;

            case 13:
                printf("Exiting system. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != 13);
}

int main() {

    runApplication();
    return 0;
}