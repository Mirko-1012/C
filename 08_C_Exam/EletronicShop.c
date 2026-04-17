#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCT 100
#define NAME_LENGTH 50

#define MIN_MENU 1
#define MAX_MENU 13


typedef struct {
    int ID;
    char name[NAME_LENGTH];
    char brand[NAME_LENGTH];
    char category[NAME_LENGTH];
    float price;
    int quantity;
    int warranty;
    bool status;
} Product;


int searchProduct(Product products[], int countProduct, int searchCode);


void clearBuffer() { // La funzione utilizza un ciclo while che continua a leggere un carattere alla volta tramite getchar() e lo scarta. Si ferma solo quando incontra il carattere di "a capo" (\n) o la fine del file (EOF, nel caso in cui lo stream di input venga chiuso). In pratica, "mangia" e butta via tutto ciò che è rimasto bloccato nel buffer fino a ripulirlo completamente.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void Pause() {
    printf("Press Enter to continue...");
    getchar();
    printf("\033[H\033[2J");
}


int readInt(const char prompt[]) { // const char prompt[] serve a passare una stringa di testo alla funzione, in modo che la funzione possa stampare un messaggio personalizzato (il "prompt", appunto) prima di chiedere l'input all'utente. Questo rende la funzione estremamente riutilizzabile.
    int value;
    while (1) {
        printf("%d", prompt);

        if (scanf("%d", &value == 1)) {
            clearBuffer();
            return value;
        }

        clearBuffer();
        printf("Intger not valid. Try again.");
    }
}


float intToFloat(int value) {
    return (float)value / 100;
}


int readRange(const char prompt[], int minValue, int maxValue) {
    int value;
    
    while (1) {
        value = readInt(prompt);

        if (value >= minValue && value <= maxValue) {
            return value;
        }

        printf("Error: value must be between %d and %d.\n", minValue, maxValue);
    }
}


void printMenu() {
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


int addProduct(Product products[], int position) { // Position rappresenta due cose contemporaneamente: Il numero totale di prodotti attualmente presenti in magazzino, e l'indice del prossimo spazio libero nell'array products dove inserire il nuovo prodotto.

    if (position >= MAX_PRODUCT) {
        printf("\nWarehouse is full.\n");
        return position;
    }

    printf("\n--- INSERT NEW PRODUCT ---\n");
    products[position].ID = readInt("Code ID: ");

    if (searchProduct(products, position, products[position].ID) != -1) {
        printf("Error: ID %d already exists!\n", products[position].ID);
        return position;
    }

    printf("Name: ");
    scanf("%49s", products[position].name);
    clearBuffer();

    printf("Brand: ");
    scanf("%49s", products[position].brand);
    clearBuffer();

    printf("Category: ");
    scanf("%49s", products[position].category);
    clearBuffer();

    int tempPrice = readRange("Price (in cents - NO DOTS/COMMAS - eg. 1250 for 12.50): ", 0, 9999999);
    products[position].price = intToFloat(tempPrice);
    products[position].quantity = readRange("Quantity: ", 0, 99999);
    products[position].warranty = readRange("Warranty: ", 0, 999);

    if (products[position].quantity > 0) {
        products[position].status = true;
    } 
    
    else {
        products[position].status = false;
    }

    printf("\n--- Product '%s' added successfully! ---\n", products[position].name);

    printf("Status set automatically to: ");

    if (products[position].status = true) {
        printf("Available");
    }

    else {
        printf("Not Available");
    }

    return position + 1;
}


void printAllProducts(Product products[], int countProduct) {

    if (countProduct == 0) {
        printf("No products available.\n");
        return;
    }

    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    printf("| Cod | Name                 | Brand           | Cat          | Price    | Qty Avail. | Warr. (Mo) | Status     |\n");
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");

    for (int i = 0; i < countProduct; i++) {
        printf("| i%-3d | %-20s | %-15s | %-12s | %-8.2f | %-10d | %-10d | %-10s |\n",
            products[i].ID,
            products[i].name,
            products[i].brand,
            products[i].category,
            products[i].price,
            products[i].quantity,
            products[i].warranty,
            products[i].status ? "Avb" : "Not Avb");
    }
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
}

int searchProduct(Product products[], int countProduct, int searchCode) {
    
    for (int i = 0; i < countProduct; i++) {
        if (products[i].ID == searchCode) {
            return i;
        }
    }
    return -1;
}


void printProductByCode (Product products[], int countProduct, int index) {

    if (countProduct == 0)  {
        printf("ERROR: Warehouse is empty\n");
        return;
    }

    if (index != -1 && index < countProduct) {
        printf("--- Product Found ---\n");
        printf("Code ID:    %d\n", products[index].ID);
        printf("Name:       %s\n", products[index].name);
        printf("Brand:      %s\n", products[index].brand);
        printf("Category:   %s\n", products[index].category);
        printf("Price:      €%.2f\n", products[index].price);
        printf("Quantity:   %d\n", products[index].quantity);
        printf("Warranty:   %d months\n", products[index].warranty);
        printf("Status:     %s\n", products[index].status ? "Avb" : "Not Avb");
        printf("---------------------\n");
    }

    else {
        printf("Product not found\n");
    }
}


void updatePrice(Product products[], int countProduct, int searchCode) {
    
    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1) {
        printf("Error: Product ID: %d not found.\n", searchCode);
        return;
    }

    printf("Product found: %s\n", products[index].name);
    printf("Current price: %.2f\n", products[index].price);

    int newPrice = readInt("Enter new price (in cents - NO DOTS/COMMAS - eg. 1250 for 12.50): ");

    products[index].price = intToFloat(newPrice);
    printf("Price updated succesfully!\n");
}


void addQuantity(Product products[], int countProduct, int searchCode) {

    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1) {
        printf("\nProduct not found\n");
        return;
    }

    printf("\nSelected Product -> Code: %d, Name: %s, Actual Quantity: %d\n", products[index].ID, products[index].name, products[index].quantity);

    int newQuantity = readInt("Enter a new quantity: ");
    products[index].quantity = newQuantity;

    if (products[index].quantity > 0) {
        products[index].status = true;
    }

    else {
        products[index].status = false;
    }
    
    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n", products[index].ID, products[index].name, products[index].quantity);
}


void updateProductStatus(Product products[], int countProduct) {

    int searchCode, index;

    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    do {
        searchCode = readInt("Enter the code of product: ");
        index = searchProduct(products, countProduct, searchCode);

        if (index != -1) {
            printf("\nError: Product not found. Try again.\n");
        }

    } while (index == -1);
    
    printf("\nSelected Product: -> Code: %d, Name: %s\n", products[index].ID, products[index].name);
    printf("Current Status: ");

    if (products[index].status == true) {
        printf("Available\n");
    }

    else {
        printf("Not Available\n");
    }

    int choice = readRange("Enter new status (1 for Available, 0 for Not Available): ", 0, 1);

    if (choice == 1) {
        products[index].status = true;
        addQuantity(products, countProduct, searchCode);
    }

    else {
        products[index].status = false;
        products[index].quantity = 0;
    }

    printf("--- Update completed successfully! ---\n");
}


bool registerSale(Product products[], int countProduct, int searchCode, int quantityToSell) {

    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return false;
    }

    if (quantityToSell <= 0) {
        printf("Error: Please enter a valid quantity.\n");
        return false;
    }

    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1) {
        printf("Error: Product ID: %d not found.\n", searchCode);
        return false;
    }

    if (products[index].quantity < quantityToSell) {
        printf("Error: Out of stock for '%s'. Available: %d\n", products[index].name, products[index]. quantity);
        return false;
    }

    float totalAmount = products[index].price * (float)quantityToSell;
    products[index].quantity -= quantityToSell;

    if (products[index].quantity == 0) {
        products[index].status = false;
    }

    printf("--- SALE REGISTERED ---\n");
    printf("Product:    %s\n", products[index].name);
    printf("Quantity:   %d\n", quantityToSell);
    printf("Total:  EUR %.2f\n", totalAmount);
    printf("Remaining:  %d\n", products[index].quantity);
    printf("--------------------------\n");

    return true;
}


void addStock(Product products[], int countProduct, int searchCode, int extraQuantity) {
    
    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    if (extraQuantity > 0) {
        printf("Add stock: %s\n", products[index].name);
        printf("Current quantity: %d\n", products[index].quantity);

        products[index].quantity += extraQuantity;
        products[index].status = true;

        printf("Update successful! New quantity: %d\n", products[index].quantity);
    }

    else {
        printf("Error: quantity must be greater than 0.\n");
    }
}


float calculateTotalValue(Product products[], int countProduct) {
    
    float totaleValue = 0;

    if (countProduct == 0) {
        printf("The warehouse is empty. The valuse is not calculate.\n");
        return 0.0f;
    }

    printf("Calculating total warehouse value...\n");

    for (int i = 0; i < countProduct; i++) {
        totaleValue += products[i].price * products[i].quantity;
    }

    printf("Total warehouse value: %.2f\n", totaleValue);
    return totaleValue;    
}


void coutProductForCategory(Product products[], int countProduct) {

    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    char searchCategory[50];
    printf("Enter the category you wish to search: ");
    scanf("%49s", searchCategory);
    clearBuffer();

    int count = 0;

    for (int i = 0; i < countProduct; i++) {
        if (strcasecmp(products[i].category, searchCategory) == 0) {
            count++;
        }
    }

    printf("\nCategory '%s' contains %d product(s). \n", searchCategory, count);
}


void longestWarrantyProduct(Product products[], int countProduct) {

    if (countProduct == 0) {
        printf("The warehouse is empty. No products to evaluate.\n");
        return;
    }

    int maxWarranty = products[0].warranty;
    int maxIndex = 0;

    for (int i = 1; i < countProduct; i++) {
        if (products[i].warranty > maxWarranty) {
            maxWarranty = products[i].warranty;
            maxIndex = i;
        }
    }

    printf("\nPRODUCT WITH LONGEST WARRANTY\n");
    printf("Name: %s\n", products[maxIndex].name);
    printf("Brand: %s\n", products[maxIndex].brand);
    printf("Warranty (months): %d\n", products[maxIndex].warranty);
}


void calculateAveragePrice(Product products[], int countProduct) {

    if (countProduct == 0) {
        printf("\nThe warehouse is empty. Average price cannot be calculated.\n");
        return;
    }

    int numberOfItems = 0;

    for (int i = 0; i < countProduct; i++) {
        numberOfItems += products[i].quantity;
    }

    if (numberOfItems == 0) {
        printf("\nNo items in stock. Average price cannot be calculated.\n");
        return;
    }

    float sumTotalPrice = calculateTotalValue(products, countProduct);
    float averagePrice = sumTotalPrice / numberOfItems;

    printf("\nThe average price of items in the warehouse is: %.2f\n", averagePrice);
}


void runApplication() {

    system("clear");

    Product products[MAX_PRODUCT];
    int currentCount = 0;
    int choice;

    do {
        printMenu();
        choice = readRange("Choice: ", MIN_MENU, MAX_MENU);

        switch (choice) {
            
            case 1: {
                currentCount = addProduct(products, currentCount);
                pause();
                break;
            }

            case 2: {
                printAllProducts(products, currentCount);
                pause();
                break;
            }

            case 3: {
                int searchCode = readInt("Enter the code you want to search: ");
                int index = searchProduct(products, currentCount, searchCode);
                printProductByCode(products, currentCount, index);
                pause();
                break;
            }

            case 4: {
                int searchCode = readInt("Enter the code you want to search: ");
                updatePrice(products, currentCount, searchCode);
                pause();
                break;
            }

            case 5: {
                int searchCodeForQuantity = readInt("Enter the code of the product you want to update the quantity: ");
                addQuantity(products, currentCount, searchCodeForQuantity);
                pause();
                break;
            }

            case 6: {
                updateProductStatus(products, currentCount);
                pause();
                break;
            }

            case 7: {
                int searchIdForSale = readInt("Enter the code of product you want to sell: ");
                int quantityToSell = readInt("Enter the quantity you want to add: ");
                registerSale(products, currentCount, searchIdForSale, quantityToSell);
                pause();
                break;
            }

            case 8: {
                int searchCodeForStock = readInt("Enter the code of product you want to add stock: ");
                int extraQty = readInt("Enter the quantity you want to add: ");
                addStock(products, currentCount, searchCodeForStock, extraQty);
                pause();
                break;
            }

            case 9: {
                calculateTotalValue(products, currentCount);
                pause();
                break;
            }

            case 10: {
                coutProductForCategory(products, currentCount);
                pause();
                break;
            }

            case 11: {
                longestWarrantyProduct(products, currentCount);
                pause();
                break;
            }

            case 12: {
                longestWarrantyProduct(products, currentCount);
                pause();
                break;
            }

            case 13: {
                printf("Exiting system. Goodbye!\n");
            }

            default: {
                printf("Invalid option. Try again.\n");
                break;
            }
        } 
    } while (choice != 13);
}


int main() {

    runApplication();
    return 0;

}
