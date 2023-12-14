#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CarNode {
    char model[50];
    float price;
    char manufacturer[50];
    float engine_capacity;
    struct CarNode* prev;
    struct CarNode* next;
};

struct CarList {
    struct CarNode* head;
    struct CarNode* tail;
};

void display(struct CarList* carList) {
    struct CarNode* current = carList->head;
    while (current != NULL) {
        printf("Model: %s, Price: %.2f, Manufacturer: %s, Engine Capacity: %.2f\n",
               current->model, current->price, current->manufacturer, current->engine_capacity);
        current = current->next;
    }
}

void insert(struct CarList* carList, char model[], float price, char manufacturer[], float engine_capacity) {
    struct CarNode* newCar = (struct CarNode*)malloc(sizeof(struct CarNode));
    strcpy(newCar->model, model);
    newCar->price = price;
    strcpy(newCar->manufacturer, manufacturer);
    newCar->engine_capacity = engine_capacity;
    newCar->prev = NULL;
    newCar->next = NULL;

    if (carList->head == NULL) {
        carList->head = newCar;
        carList->tail = newCar;
    } else {
        newCar->prev = carList->tail;
        carList->tail->next = newCar;
        carList->tail = newCar;
    }
}

void deleteModel(struct CarList* carList, char model[]) {
    struct CarNode* current = carList->head;
    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                carList->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                carList->tail = current->prev;
            }

            printf("Model %s deleted successfully.\n", model);
            free(current);
            return;
        }
        current = current->next;
    }

    printf("Model %s not found.\n", model);
}

void updatePrice(struct CarList* carList, char model[], float newPrice) {
    struct CarNode* current = carList->head;
    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            current->price = newPrice;
            printf("Price for model %s updated to %.2f\n", model, newPrice);
            return;
        }
        current = current->next;
    }

    printf("Model %s not found.\n", model);
}

void displayInRange(struct CarList* carList, float minPrice, float maxPrice) {
    struct CarNode* current = carList->head;
    while (current != NULL) {
        if (current->price >= minPrice && current->price <= maxPrice) {
            printf("Model: %s, Price: %.2f, Manufacturer: %s, Engine Capacity: %.2f\n",
                   current->model, current->price, current->manufacturer, current->engine_capacity);
        }
        current = current->next;
    }
}

int main() {
    struct CarList carList;
    carList.head = NULL;
    carList.tail = NULL;

    int choice;
    char model[50];
    float price, engine_capacity, minPrice, maxPrice;
    char manufacturer[50];

    do {
        printf("\nMenu:\n");
        printf("1. Insert Car Model\n");
        printf("2. Delete Car Model\n");
        printf("3. Update Price\n");
        printf("4. Display Cars in Price Range\n");
        printf("5. Display All Cars\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter model: ");
                scanf("%s", model);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter manufacturer: ");
                scanf("%s", manufacturer);
                printf("Enter engine capacity: ");
                scanf("%f", &engine_capacity);
                insert(&carList, model, price, manufacturer, engine_capacity);
                break;

            case 2:
                printf("Enter model to delete: ");
                scanf("%s", model);
                deleteModel(&carList, model);
                break;

            case 3:
                printf("Enter model to update price: ");
                scanf("%s", model);
                printf("Enter new price: ");
                scanf("%f", &price);
                updatePrice(&carList, model, price);
                break;

            case 4:
                printf("Enter minimum price: ");
                scanf("%f", &minPrice);
                printf("Enter maximum price: ");
                scanf("%f", &maxPrice);
                displayInRange(&carList, minPrice, maxPrice);
                break;

            case 5:
                display(&carList);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
