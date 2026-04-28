#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp;
    struct student s;

    fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student record added successfully.\n");
}

void displayStudents() {
    FILE *fp;
    struct student s;

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d\n", s.roll);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n\n", s.marks);
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

