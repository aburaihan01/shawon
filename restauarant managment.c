#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 50
#define MAX_ORDER_ITEMS 50

// Define structure for restaurant information
typedef struct {
    char name[50];
} Restaurant;

// Define structures for menu item and order item
typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem item;
    int quantity;
} OrderItem;

// Global variables
Restaurant restaurant = {"Delicious Restaurant"};
MenuItem menu[MAX_MENU_ITEMS];
OrderItem order[MAX_ORDER_ITEMS];
int numMenuItems = 0;
int numOrderItems = 0;

// Function prototypes
void displayMenu();
void takeOrder();
float calculateTotal();
void generateBill();

int main() {
    int choice;

    // Adding some sample menu items
    strcpy(menu[numMenuItems].name, "Pizza");
    menu[numMenuItems].price = 8.99;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Burger");
    menu[numMenuItems].price = 6.49;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Salad");
    menu[numMenuItems].price = 5.99;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Sandwich");
    menu[numMenuItems].price = 5.49;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Chicken Fry (2 pcs)");
    menu[numMenuItems].price = 9.99;
    numMenuItems++;

    do {
        printf("\n%s\n", restaurant.name);
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Calculate Total\n");
        printf("4. Generate Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                takeOrder();
                break;
            case 3:
                printf("Total amount: $%.2f\n", calculateTotal());
                break;
            case 4:
                generateBill();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder() {
    int choice, quantity;

    printf("\nTaking Order\n");
    displayMenu();
    printf("Enter item number to order (0 to exit): ");
    scanf("%d", &choice);

    while (choice != 0 && numOrderItems < MAX_ORDER_ITEMS) {
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if (choice > 0 && choice <= numMenuItems) {
            order[numOrderItems].item = menu[choice - 1];
            order[numOrderItems].quantity = quantity;
            numOrderItems++;
        } else {
            printf("Invalid item number.\n");
        }

        printf("Enter item number to order (0 to exit): ");
        scanf("%d", &choice);
    }
}

float calculateTotal() {
    float total = 0.0;

    for (int i = 0; i < numOrderItems; i++) {
        total += order[i].item.price * order[i].quantity;
    }

    return total;
}

void generateBill() {
    printf("\n%s\n", restaurant.name);
    printf("Bill:\n");
    for (int i = 0; i < numOrderItems; i++) {
        printf("%s - $%.2f x %d\n", order[i].item.name, order[i].item.price, order[i].quantity);
    }
    printf("Total: $%.2f\n", calculateTotal());
}

