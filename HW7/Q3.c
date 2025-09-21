// GitHub: https://github.com/alitalhq

/*
 * Design a market automation system in C with the following functionalities.
 * The program should use a structure to store product codes and prices. All operations will be performed on the products.txt file.
 * 
 * A) Generate and Save Data
 * Generate 20 products. Each product should have:
 * An 8-character product code: 4 uppercase letters + 4 digits (e.g., ABCD1234)
 * A price between 50 and 500
 * Save the data to products.txt in the format:
 * CODE PRICE
 * ABCD1234 175
 * KLMN8765 320
 * 
 * B) Menu-Based Operations
 * The program should provide a menu:
 *     1 Generate random products and write to file
 *     2 Sort products by price in ascending order and display
 *         Save sorted data to price_sorted.txt
 *     3 Sort products alphabetically by code and display
 *         Save sorted data to code_sorted.txt
 *     4 Search product
 *         Ask for product code and display product info if found
 *     5 Delete product
 *         Ask for product code and delete it from products.txt
 *     6 Exit
 * 
 * 
 * Notes: 
 * Use printf, fscanf, fopen, fclose for file operations.
 * Use struct for product information.
 * Use Quick Sort for sorting.
 * Prefer modular and functional programming structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char code[9];
    int price;
} Product;

void generateProduct(Product *product) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 4; i++) {
        product->code[i] = letters[rand() % 26];
    }
    for (int i = 4; i < 8; i++) {
        product->code[i] = '0' + rand() % 10;
    }
    product->code[8] = '\0';
    product->price = 50 + rand() % 451;
}

int comparePrice(const void *a, const void *b) {
    Product *prodA = *(Product **)a;
    Product *prodB = *(Product **)b;
    return prodA->price - prodB->price;
}

int compareCode(const void *a, const void *b) {
    Product *prodA = *(Product **)a;
    Product *prodB = *(Product **)b;
    return strcmp(prodA->code, prodB->code);
}

void writeToFile(Product **products, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", products[i]->code, products[i]->price);
    }
    fclose(file);
}

void searchProduct(Product **products, int count, const char *code) {
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i]->code, code) == 0) {
            printf("Product Found! Code: %s, Price: %d\n", products[i]->code, products[i]->price);
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct(Product ***products, int *count, const char *code) {
    for (int i = 0; i < *count; i++) {
        if (strcmp((*products)[i]->code, code) == 0) {
            free((*products)[i]);
            for (int j = i; j < *count - 1; j++) {
                (*products)[j] = (*products)[j + 1];
            }
            (*count)--;
            printf("Product deleted.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void menu(void) {
    printf("\n1. Add product\n");
    printf("2. Sort by price\n");
    printf("3. Sort by code\n");
    printf("4. Search product\n");
    printf("5. Delete product\n");
    printf("6. Exit\n");
}

int main(void) {
    srand((unsigned)time(NULL));

    int productCount = 20;
    Product **products = (Product **)malloc(sizeof(Product *) * productCount);
    for (int i = 0; i < productCount; i++) {
        products[i] = (Product *)malloc(sizeof(Product));
        generateProduct(products[i]);
    }

    int choice;
    char searchCode[9];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                productCount++;
                products = (Product **)realloc(products, sizeof(Product *) * productCount);
                products[productCount - 1] = (Product *)malloc(sizeof(Product));
                generateProduct(products[productCount - 1]);
                writeToFile(products, productCount, "products.txt");
                printf("New product added to file.\n");
                break;

            case 2:
                qsort(products, productCount, sizeof(Product *), comparePrice);
                writeToFile(products, productCount, "price_sorted.txt");
                printf("Products sorted by price and saved to price_sorted.txt.\n");
                break;

            case 3:
                qsort(products, productCount, sizeof(Product *), compareCode);
                writeToFile(products, productCount, "code_sorted.txt");
                printf("Products sorted by code and saved to code_sorted.txt.\n");
                break;

            case 4:
                printf("Enter product code to search: ");
                scanf("%s", searchCode);
                searchProduct(products, productCount, searchCode);
                break;

            case 5:
                printf("Enter product code to delete: ");
                scanf("%s", searchCode);
                deleteProduct(&products, &productCount, searchCode);
                writeToFile(products, productCount, "products.txt");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    for (int i = 0; i < productCount; i++) {
        free(products[i]);
    }
    free(products);

    return 0;
}