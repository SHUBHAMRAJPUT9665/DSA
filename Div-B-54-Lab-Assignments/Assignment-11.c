/*
Write a program to arrange list of students to find out first ten toppers
from a class using Bubble sort. (refer the student database given in
assignment 10)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float percentage;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void displayTopTen(struct Student students[], int numStudents) {
    printf("\nTop Ten Toppers:\n");
    printf("Roll No\t\tName\t\tPercentage\n");
    for (int i = 0; i < 10 && i < numStudents; i++) {
        printf("%d\t\t%s\t\t%.2f\n", students[i].rollNo, students[i].name, students[i].percentage);
    }
}

int main() {
    int numStudents, choice;

    printf("Enter the number of students in the database: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display Top Ten Toppers\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(students, numStudents);
                displayTopTen(students, numStudents);
                break;

            case 2:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 2);

    return 0;
}
