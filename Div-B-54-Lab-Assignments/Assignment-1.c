/*
Write a program to represent sparse matrix using array and perform
simple and fast transpose
*/

#include <stdio.h>

#define MAX 100

struct Element {
    int row, col, value;
};

struct SparseMatrix {
    int rows, cols, numElements;
    struct Element data[MAX];
};

void inputSparseMatrix(struct SparseMatrix *matrix) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &matrix->numElements);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < matrix->numElements; ++i) {
        scanf("%d %d %d", &matrix->data[i].row, &matrix->data[i].col, &matrix->data[i].value);
    }
}

void printSparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < matrix.numElements; ++i) {
        printf("%d %d %d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
    }
}

void transposeSparseMatrix(struct SparseMatrix *matrix) {
    int temp = matrix->rows;
    matrix->rows = matrix->cols;
    matrix->cols = temp;

    for (int i = 0; i < matrix->numElements; ++i) {
        temp = matrix->data[i].row;
        matrix->data[i].row = matrix->data[i].col;
        matrix->data[i].col = temp;
    }
}

int main() {
    struct SparseMatrix matrix;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Input Sparse Matrix\n");
        printf("2. Print Original Matrix\n");
        printf("3. Transpose Matrix\n");
        printf("4. Print Transposed Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputSparseMatrix(&matrix);
                break;

            case 2:
                printf("\nOriginal Matrix:\n");
                printSparseMatrix(matrix);
                break;

            case 3:
                transposeSparseMatrix(&matrix);
                break;

            case 4:
                printf("\nTransposed Matrix:\n");
                printSparseMatrix(matrix);
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


// output
/*
Menu:
1. Input Sparse Matrix
2. Print Original Matrix
3. Transpose Matrix
4. Print Transposed Matrix
5. Exit
Enter your choice: 1
Enter number of rows and columns: 3 3
Enter number of non-zero elements: 4
Enter the non-zero elements (row, column, value):
0 0 1
1 1 2
2 2 3
2 0 4

Menu:
1. Input Sparse Matrix
2. Print Original Matrix
3. Transpose Matrix
4. Print Transposed Matrix
5. Exit
Enter your choice: 2
Original Matrix:
Sparse Matrix:
0 0 1
1 1 2
2 2 3
2 0 4

Menu:
1. Input Sparse Matrix
2. Print Original Matrix
3. Transpose Matrix
4. Print Transposed Matrix
5. Exit
Enter your choice: 3

Menu:
1. Input Sparse Matrix
2. Print Original Matrix
3. Transpose Matrix
4. Print Transposed Matrix
5. Exit
Enter your choice: 4
Transposed Matrix:
Sparse Matrix:
0 0 1
1 1 2
2 2 3
0 2 4

Menu:
1. Input Sparse Matrix
2. Print Original Matrix
3. Transpose Matrix
4. Print Transposed Matrix
5. Exit
Enter your choice: 5
Exiting program.

*/