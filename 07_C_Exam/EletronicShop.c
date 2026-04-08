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

// Robust function that read a user input
// By Pierfrancesco Blancato
int readInt(const char prompt[]) {
    int value;
    while (1) {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1) {
            return value;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
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

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Input not valid. Insert a real number.\n");
    }
}

// By Pierfrancesco Blancato
int readRange(const char prompt[], int min_value, int max_value) {
    int value;
    while (1){
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        if (value >= min_value && value <= max_value) {
            return value;
        }
    }
}

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
    printf("Choice: ");
    scanf("%d", &choice);
}

// N1 - By Mirko Di Natale
void addProduct(Product products[], int position) {

    printf("Code: ");
    scanf("%d", &products[position].id);

    printf("Name: ");
    scanf("%s", &products[position].name);

    printf("Brand: ");
    scanf("%s", &products[position].brand);

    printf("Category: ");
    scanf("%s", &products[position].category);

    printf("Price: ");
    scanf("%f", &products[position].price);

    printf("Quantity: \n");
    scanf("%d", &products[position].quantity);

    printf("Warranty (months): ");
    scanf("%d", &products[position].warranty);

    printf("Status (1 for available, 0 for not available): ");
    scanf("%d", &products[position].status);

}

// N2 - By Pierfrancesco Blancato
/*void printAllProducts(Product products[], int countProduct) {
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
void addQuantity(Product products[], int countProduct) {
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

int main() {

    Product products[MAX_PRODUCTS];
    int count = 0;

    printMenu();

    /*printf("\n--- INITIAL TABLE ---\n");
    printAllProducts(products, count);*/

    printf("\n--- TEST ADD PRODUCT ---\n");
    addProduct(products, count);
    count++;

    /*printf("\n--- TEST MODIFY QUANTITY ---\n");
    addQuantity(products, count);

    printf("\n--- UPDATED TABLE ---\n");
    printAllProducts(products, count);

    printf("\n--- Count for category ---\n");
    countProductForCategory(products, count);*/

    return 0;
}