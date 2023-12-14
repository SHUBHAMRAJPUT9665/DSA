#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNumber;
    char name[50];
    char division;
    char address[100];
};

void addStudent(FILE* file) {
    struct Student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    fflush(stdin);
    printf("Enter Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    printf("Enter Division: ");
    scanf(" %c", &newStudent.division);
    fflush(stdin);
    printf("Enter Address: ");
    fgets(newStudent.address, sizeof(newStudent.address), stdin);

    fwrite(&newStudent, sizeof(struct Student), 1, file);

    printf("Student added successfully!\n");
}

void displayStudent(FILE* file, int rollNumber) {
    struct Student student;

    rewind(file);

    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.rollNumber == rollNumber) {
            printf("\nStudent Information:\n");
            printf("Roll Number: %d\n", student.rollNumber);
            printf("Name: %s", student.name);
            printf("Division: %c\n", student.division);
            printf("Address: %s", student.address);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
}

void deleteStudent(FILE* file, int rollNumber) {
    struct Student student;
    FILE* tempFile;

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        exit(EXIT_FAILURE);
    }

    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.rollNumber != rollNumber) {
            fwrite(&student, sizeof(struct Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("Student with Roll Number %d deleted successfully!\n", rollNumber);
}

int main() {
    FILE* file;
    int choice, rollNumber;

    file = fopen("student.dat", "ab+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(file);
                break;

            case 2:
                printf("Enter Roll Number to display: ");
                scanf("%d", &rollNumber);
                displayStudent(file, rollNumber);
                break;

            case 3:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(file, rollNumber);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    fclose(file);

    return 0;
}
