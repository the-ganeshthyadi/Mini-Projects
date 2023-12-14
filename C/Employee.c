#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100


struct Employee {
    int employeeId;
    char name[50];
    char role[50];
};


struct Employee employees[MAX_EMPLOYEES];


int totalEmployees = 0;


void buildEmployeeTable() {
    printf("Built the Employee Table.\n");
}


void insertEntry() {
    if (totalEmployees >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Employee table is full.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.employeeId);

    printf("Enter employee name: ");
    scanf(" %[^\n]", newEmployee.name);

    printf("Enter employee role: ");
    scanf(" %[^\n]", newEmployee.role);

    employees[totalEmployees++] = newEmployee;

    printf("Employee added successfully.\n");
}


void deleteEntry(int employeeId) {
    int i, found = 0;

    for (i = 0; i < totalEmployees; ++i) {
        if (employees[i].employeeId == employeeId) {
            found = 1;

            while (i < totalEmployees - 1) {
                employees[i] = employees[i + 1];
                i++;
            }

            totalEmployees--;
            printf("Employee with ID %d deleted successfully.\n", employeeId);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", employeeId);
    }
}


void searchRecord(int employeeId) {
    int i, found = 0;

    for (i = 0; i < totalEmployees; ++i) {
        if (employees[i].employeeId == employeeId) {
            found = 1;
            printf("Employee found by ID %d:\n", employeeId);
            printf("Name: %s\n", employees[i].name);
            printf("Role: %s\n", employees[i].role);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", employeeId);
    }
}

int main() {
    int choice, employeeId;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Build Employee Table\n");
        printf("2. Insert New Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Search Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buildEmployeeTable();
                break;
            case 2:
                insertEntry();
                break;
            case 3:
                printf("Enter employee ID to delete: ");
                scanf("%d", &employeeId);
                deleteEntry(employeeId);
                break;
            case 4:
                printf("Enter employee ID to search: ");
                scanf("%d", &employeeId);
                searchRecord(employeeId);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
