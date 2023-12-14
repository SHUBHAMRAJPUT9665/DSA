/*
Write a program to create binary tree. Find height of the tree and print
leaf nodes. Find mirror image, print original and mirror image using
level-wise printing
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

void printLeafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void mirrorImage(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Height of the tree: %d\n", height(root));

    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");

    printf("Original tree (level order): ");
    printLevelOrder(root);
    printf("\n");

    mirrorImage(root);

    printf("Mirror image of the tree (level order): ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}
