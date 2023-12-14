/*
Write a program that reads a list of names and telephone numbers from
user and insert into a BST tree. Once the tree has been built, present the
user with a menu that allows him to search the list for a specified name,
insert new name, delete an existing name or print the entire phone list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phoneNumber[15];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char name[], char phoneNumber[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char name[], char phoneNumber[]) {
    if (root == NULL) {
        return createNode(name, phoneNumber);
    }

    int compareResult = strcmp(name, root->name);

    if (compareResult < 0) {
        root->left = insert(root->left, name, phoneNumber);
    } else if (compareResult > 0) {
        root->right = insert(root->right, name, phoneNumber);
    }

    return root;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL) {
        return root;
    }

    int compareResult = strcmp(name, root->name);

    if (compareResult < 0) {
        root->left = deleteNode(root->left, name);
    } else if (compareResult > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);

        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

void printPhoneList(struct Node* root) {
    if (root != NULL) {
        printPhoneList(root->left);
        printf("%s: %s\n", root->name, root->phoneNumber);
        printPhoneList(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];
    char phoneNumber[15];

    do {
        printf("\nMenu:\n");
        printf("1. Search\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Print Phone List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name to search: ");
                scanf("%s", name);
                struct Node* result = search(root, name);
                if (result != NULL) {
                    printf("Phone number: %s\n", result->phoneNumber);
                } else {
                    printf("Name not found in the phone list.\n");
                }
                break;

            case 2:
                printf("Enter name to insert: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                root = insert(root, name, phoneNumber);
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;

            case 4:
                printf("Phone List:\n");
                printPhoneList(root);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
