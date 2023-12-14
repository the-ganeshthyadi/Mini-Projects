#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int bookId;
};

struct Book books[MAX_BOOKS];

int totalBooks = 0;

void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        printf("Cannot add more books. Library is full.\n");
        return;
    }

    struct Book newBook;

    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter author name: ");
    scanf(" %[^\n]", newBook.author);

    printf("Enter book ID: ");
    scanf("%d", &newBook.bookId);

    books[totalBooks++] = newBook;

    printf("Book added successfully.\n");
}

void displayBooks() {
    if (totalBooks == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("List of Books:\n");
    for (int i = 0; i < totalBooks; ++i) {
        printf("Book ID: %d\n", books[i].bookId);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("------------------------\n");
    }
}

void listBooksByAuthor(const char *authorName) {
    int count = 0;

    printf("Books by %s:\n", authorName);
    for (int i = 0; i < totalBooks; ++i) {
        if (strcmp(books[i].author, authorName) == 0) {
            printf("Book ID: %d\n", books[i].bookId);
            printf("Title: %s\n", books[i].title);
            printf("------------------------\n");
            count++;
        }
    }

    if (count == 0) {
        printf("No books found by %s.\n", authorName);
    }
}

void countBooks() {
    printf("Total number of books in the library: %d\n", totalBooks);
}

int main() {
    int choice;
    char authorName[100];

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. List Books by Author\n");
        printf("4. Count Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter author name to list books: ");
                scanf(" %[^\n]", authorName);
                listBooksByAuthor(authorName);
                break;
            case 4:
                countBooks();
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
