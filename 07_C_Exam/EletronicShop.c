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
float intToFloat(int value) {
    return (float)value/100;
}


// By Pierfrancesco Blancato
int readRange(const char prompt[], int min_value, int max_value) {
    int value;
    while (1){  
        value = readInt(prompt);

        if (value >= min_value && value <= max_value){
            return value;
        }
        printf("Error: value must be between %d and %d.\n", min_value, max_value);
    }
}


// By Mirko Di Natale
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


// N1 - By Mirko Di Natale - Add a new product to the warehouse
int addProduct(Product products[], int position) {
    if (position >= MAX_PRODUCTS) {
        printf("\nERROR: Warehouse is full!\n");
        return position;
    }

    printf("\n--- INSERT NEW PRODUCT ---\n");
    products[position].id = readInt("Code ID: ");

    printf("Name: ");
    scanf("%s", products[position].name);
    clearBuffer();

    printf("Brand: ");
    scanf("%s", products[position].brand);
    clearBuffer();

    printf("Category: ");
    scanf("%s", products[position].category);
    clearBuffer();

    int tempPrice = readInt("Price (in cents eg. 1250 for 12.50): ");
    products[position].price = intToFloat(tempPrice);

    products[position].quantity = readInt("Quantity: ");
    products[position].warranty = readInt("Warranty (months): ");

    if (products[position].quantity > 0) {
        products[position].status = true;
    } else {
        products[position].status = false;
    }

    printf("\n--- Product '%s' added successfully! ---\n", products[position].name);
    
    printf("Status set automatically to: ");
    if (products[position].status == true) {
        printf("Available\n");
    } else {
        printf("Not Available\n");
    }

    return position + 1;
}


// N2 - By Pierfrancesco Blancato - Show all products in the warehouse
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


// N4 - By Matteo Ventimiglia - Update the price of a product in the warehouse
void updatePrice(Product products[], int countProduct) {
    // This is for the case in which there are no products in the warehouse, so we can't update any price
    if (countProduct == 0) {
        printf("The warehouse is empty.\n");
        return;
    }

    int search_id;

    printf("Enter the ID of the product: ");
    scanf("%d", &search_id);
   
    for (int i = 0; i < countProduct; i++) {
       
        // If id is found, we print the name and the current price of the product
        if (products[i].id == search_id) {
            printf("Product founfd: %s\n", products[i].name);
            printf("The current price is: %.2f\n", products[i].price);
            printf("Write new price: ");
            scanf("%f", &products[i].price);
            printf("Price updated successfully!");
           
            return;
        }
    }
}

// N5 - By Pierfrancesco Blancato - Update the available quantity of a product in the warehouse
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


// N6 - By Mirko Di Natale - Update the status of a product in the warehouse
void updateProductStatus(Product products[], int countProduct) {
    
    int index = searchProduct(products, countProduct);

    // If index is -1, the product was not found
    do {
        index = searchProduct(products, countProduct);

        if (index == -1) {
            printf("\nError: Product not found. Please try again.\n");
        }
    } while (index == -1);

    printf("\nSelected Product: --> Code: %d, Name: %s\n", products[index].id, products[index].name);
    printf("Current Status: ");
    if (products[index].status == true) {
        printf("Available\n");
    } else {
        printf("Not Available\n");
    }

    int choice = readRange("Enter new status (1 for Available, 0 for Not Available): ", 0, 1);
    
    if (choice == 1) {
        products[index].status = true;
    } else {
        products[index].status = false;
    }
    printf("--- Update completed successfully! ---\n");
}

/*
// N8 - By Gioele Marcinnò - Add Stock
void addStock(int index)= search(product, searchId ){
    int extraQuantity;

    printf(" Add stock: %s\n", products[i].name);
    printf("Current quantity: %d\n", products[i].quantity);

    
    printf("How many units are you adding? ");
    scanf("%d", &extraQuantity);


    if (extraQuantity > 0) {
      
        products[i].quantity += extraQuantity;
        products[i].status = true; 
        
        printf("Update successful! New quantity: %d\n", products[index].quantity);
    } else {
        printf("Error: quantity must be greater than zero.\n");
    }
}


// N9 - By Gioele Marcinnò - Calculate total warehouse value
void calculateTotalValue(){
    float totalValue = 0;
    int i;
        if (count==0){
            printf("The warehouse is empty.The value is not calculate.\n");
            return;
        }
    printf("Calculating total warehouse value..\n")
	
    for (i = 0; i < count; i++) {
    totalValue = totalValue + products[i].price * products[i].quantity;
    }
    printf("Total warehouse value: %.2f\n", totalValue);
}
*/

// N10 - By Pierfrancesco Blancato - Count how many products are in a specific category in the warehouse
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
}


// 12 - By Mirko Di Natale - Calculate the average price of products in the warehouse
void calculateAveragePrice(Product products[], int countProduct) {
    if (countProduct == 0) {
        printf("\nThe warehouse is empty. Average price cannot be calculated.\n");
        return;
    }

    float sumTotalPrice = 0;
    int numberOfItems = 0;

    for (int i = 0; i < countProduct; i++) {
        sumTotalPrice += products[i].price * products[i].quantity;
        numberOfItems += products[i].quantity;
    }

    if (numberOfItems == 0) {
        printf("\nNo items in the warehouse. Average price cannot be calculated.\n");
        return;
    }

    float averagePrice = sumTotalPrice / numberOfItems;

    printf("\nThe average price of items in the warehouse is: %.2f\n", averagePrice);
}


// By Mirko Di Natale - Main application loop
void runApplication() {
    Product products[MAX_PRODUCTS];
    int currentCount = 0;
    int choice;

    do {
        printMenu();
        choice = readRange("Choice: ", 1, 13);

        switch (choice) {
            case 1:
                currentCount = addProduct(products, currentCount);
                break;

            case 2:
                printAllProducts(products, currentCount);
                break;

            case 5: 
                updateQuantity(products, currentCount);
                break;

            case 6:
                updateProductStatus(products, currentCount);
                break;

            case 10: 
                countProductForCategory(products, currentCount);
                break;
            
            case 12:
                calculateAveragePrice(products, currentCount);
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