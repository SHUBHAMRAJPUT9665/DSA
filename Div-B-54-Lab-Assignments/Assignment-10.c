/*
Write a program to create student database. Database contains different
fields of student like Roll No, Name and percentage. Search a
particular student according to roll number using binary search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float percentage;
};

int compareStudents(const void* a, const void* b) {
    return ((struct Student*)a)->rollNo - ((struct Student*)b)->rollNo;
}

int binarySearch(struct Student students[], int left, int right, int targetRollNo) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (students[mid].rollNo == targetRollNo)
            return mid;
        if (students[mid].rollNo > targetRollNo)
            return binarySearch(students, left, mid - 1, targetRollNo);
        return binarySearch(students, mid + 1, right, targetRollNo);
    }
    return -1;
}

void displayStudent(struct Student student) {
    printf("Roll No: %d\n", student.rollNo);
    printf("Name: %s\n", student.name);
    printf("Percentage: %.2f\n", student.percentage);
    printf("\n");
}

int main() {
    int numStudents;
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

    qsort(students, numStudents, sizeof(struct Student), compareStudents);

    int targetRollNo, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Search Student by Roll No\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the Roll No to search: ");
                scanf("%d", &targetRollNo);
                int index = binarySearch(students, 0, numStudents - 1, targetRollNo);
                if (index != -1) {
                    printf("\nStudent found!\n");
                    displayStudent(students[index]);
                } else {
                    printf("\nStudent not found.\n");
                }
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
