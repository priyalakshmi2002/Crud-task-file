
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
// Structure to represent a grocery item
struct GroceryItem {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Global array to store grocery items
struct GroceryItem groceryItems[MAX_ITEMS];
int numItems = 0; // Track the number of items in the array

// Function prototypes
void createItem();
void readItems();
void updateItem();
void deleteItem();  

int main() {
    int choice;
    printf("\n**** Happy life super market ****\n");

    do {
        // Display menu
        printf("\n MENU\n");
        printf("1. Enter Item\n");
        printf("2. Read Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch(choice) {
            case 1:
                createItem();
                break;
            case 2:
                readItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while(choice != 5);
    printf("\n**** Thank You - Visit again ****");
    return 0;
}

void createItem() {
    struct GroceryItem newItem;

    // Input new item's information
    printf("Enter ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newItem.name); // Read name with spaces
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    // Add new item to the array
    groceryItems[numItems++] = newItem;

    printf("Item added successfully!\n");
}

void readItems() {
    if (numItems == 0) {
        printf("No items to display.\n");
        return;
    }

    printf("List of Grocery Items:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numItems; ++i) {
        printf("%d\t%s\t\t%d\t    %.2f\n", groceryItems[i].id, groceryItems[i].name, groceryItems[i].quantity, groceryItems[i].price);
    }
}

void updateItem() {
    int id, found = 0;

    if (numItems == 0) {
        printf("No items to update.\n");
        return;
    }

    printf("Enter ID of item to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numItems; ++i) {
        if (groceryItems[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", groceryItems[i].name); // Read name with spaces
            printf("Enter new Quantity: ");
            scanf("%d", &groceryItems[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &groceryItems[i].price);
            found = 1;
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void deleteItem() {
    int id, found = 0;

    if (numItems == 0) {
        printf("No items to delete.\n");
        return;
    }

    printf("Enter ID of item to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < numItems; ++i) {
        if (groceryItems[i].id == id) {
            // Shift elements to the left to overwrite the deleted element
            for (int j = i; j < numItems - 1; ++j) {
                groceryItems[j] = groceryItems[j + 1];
            }
            numItems--;
            found = 1;
            printf("Item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
    
}


