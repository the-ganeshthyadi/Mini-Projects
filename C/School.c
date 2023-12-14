#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


struct Student {
    int rollNumber;
    char firstName[50];
    char lastName[50];
    char course[50];
};


struct Student students[MAX_STUDENTS];


int totalStudents = 0;


void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;
    newStudent.rollNumber = totalStudents + 1;

    printf("Enter first name: ");
    scanf("%s", newStudent.firstName);

    printf("Enter last name: ");
    scanf("%s", newStudent.lastName);

    printf("Enter course: ");
    scanf("%s", newStudent.course);

    students[totalStudents++] = newStudent;

    printf("Student added successfully. Roll number is %d.\n", newStudent.rollNumber);
}


void findStudentByRollNumber(int rollNumber) {
    int i, found = 0;

    for (i = 0; i < totalStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found by roll number %d:\n", rollNumber);
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Course: %s\n", students[i].course);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}


void findStudentByFirstName(const char *firstName) {
    int i, found = 0;

    for (i = 0; i < totalStudents; ++i) {
        if (strcmp(students[i].firstName, firstName) == 0) {
            printf("Student found by first name %s:\n", firstName);
            printf("Roll number: %d\n", students[i].rollNumber);
            printf("Last name: %s\n", students[i].lastName);
            printf("Course: %s\n", students[i].course);
            found = 1;
        }
    }

    if (!found) {
        printf("Student with first name %s not found.\n", firstName);
    }
}


void findStudentsInCourse(const char *course) {
    int i, count = 0;

    printf("Students registered in course %s:\n", course);

    for (i = 0; i < totalStudents; ++i) {
        if (strcmp(students[i].course, course) == 0) {
            printf("%d. %s %s\n", count + 1, students[i].firstName, students[i].lastName);
            count++;
        }
    }

    if (count == 0) {
        printf("No students found in course %s.\n", course);
    }
}


void countStudents() {
    printf("Total number of students: %d\n", totalStudents);
}


void deleteStudent(int rollNumber) {
    int i, found = 0;

    for (i = 0; i < totalStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;

            while (i < totalStudents - 1) {
                students[i] = students[i + 1];
                i++;
            }

            totalStudents--;
            printf("Student with roll number %d deleted successfully.\n", rollNumber);
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}


void updateStudent(int rollNumber) {
    int i, found = 0;

    for (i = 0; i < totalStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new first name: ");
            scanf("%s", students[i].firstName);

            printf("Enter new last name: ");
            scanf("%s", students[i].lastName);

            printf("Enter new course: ");
            scanf("%s", students[i].course);

            printf("Student with roll number %d updated successfully.\n", rollNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

int main() {
    int choice, rollNumber;
    char firstName[50], course[50];

    do {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Find Students in a Course\n");
        printf("5. Count Students\n");
        printf("6. Delete Student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printf("Enter roll number to find: ");
                scanf("%d", &rollNumber);
                findStudentByRollNumber(rollNumber);
                break;
            case 3:
                printf("Enter first name to find: ");
                scanf("%s", firstName);
                findStudentByFirstName(firstName);
                break;
            case 4:
                printf("Enter course to find students: ");
                scanf("%s", course);
                findStudentsInCourse(course);
                break;
            case 5:
                countStudents();
                break;
            case 6:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(rollNumber);
                break;
            case 7:
                printf("Enter roll number to update: ");
                scanf("%d", &rollNumber);
                updateStudent(rollNumber);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}
