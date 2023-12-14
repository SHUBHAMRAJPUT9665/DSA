/*3

Q-Write a menu driven program to perform following operations on
singly linked list: Create, Insert, Delete, reverse, search, count and
Display
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

struct Node *deleteNode(struct Node *head, int value) {
    struct Node *current = head, *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Element %d deleted from the list.\n", value);
    return head;
}

struct Node *reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void searchElement(struct Node *head, int value) {
    struct Node *current = head;
    int position = 1;

    while (current != NULL && current->data != value) {
        current = current->next;
        position++;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", value);
    } else {
        printf("Element %d found at position %d.\n", value, position);
    }
}

int countNodes(struct Node *head) {
    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void displayList(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void freeList(struct Node *head) {
    struct Node *current = head, *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

struct Node *createList() {
    struct Node *head = NULL;
    int value;

    printf("Enter elements to create the list (enter -1 to stop):\n");

    while (1) {
        printf("Enter element: ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        head = insertAtEnd(head, value);
    }

    return head;
}

int main() {
    struct Node *head = NULL;
    int choice, value;

    do {
        printf("\n------ Menu ------\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete an element\n");
        printf("4. Reverse the list\n");
        printf("5. Search for an element\n");
        printf("6. Count nodes\n");
        printf("7. Display the list\n");
        printf("8. Create a new list\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;

            case 4:
                head = reverseList(head);
                printf("List reversed.\n");
                break;

            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchElement(head, value);
                break;

            case 6:
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                // Free the existing list before creating a new one
                freeList(head);
                head = createList();
                break;

            case 9:
                freeList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}
