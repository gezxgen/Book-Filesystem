# Book Database Management Program

**Author**: Kevin  
**Date**: 03.06.2024  
**Language**: C

---

## Table of Contents
1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Functions Overview](#functions-overview)
4. [Detailed Function Documentation](#detailed-function-documentation)
    - [Main Function](#main-function)
    - [init()](#init)
    - [print()](#print)
    - [addBook()](#addbook)
    - [deleteBook()](#deletebook)
    - [printBook()](#printbook)
    - [printAllBooks()](#printallbooks)
    - [calculateAveragePages()](#calculateaveragepages)
5. [Data Structures](#data-structures)
6. [Error Handling](#error-handling)
7. [References](#references)

---

## Introduction

This C program manages a small book database with functionalities like adding, deleting, searching, and displaying books. It allows users to perform these actions through a console-based menu. Books are stored in an array, and the program supports up to 10 books at a time.

---

## Project Structure

The program consists of the following files:

1. **main.c**: The main entry point of the program, where the menu logic is implemented.
2. **bookfunctions.h**: Header file declaring all the function prototypes and the `sBook` structure.
3. **bookfunctions.c**: Source file where all the helper functions are implemented, such as adding, deleting, and displaying books.

---

## Functions Overview

Here’s a high-level summary of the main functions in the program:

- **main()**: Initializes the program and displays a menu for users to interact with the book database.
- **init()**: Initializes the database with predefined books.
- **addBook()**: Allows the user to add a book to the database.
- **deleteBook()**: Deletes a book from the database based on its title.
- **printBook()**: Searches for and displays details of a book by title.
- **printAllBooks()**: Displays all books currently in the database.
- **calculateAveragePages()**: Calculates and returns the average number of pages for all books in the database.

---

## Detailed Function Documentation

### Main Function

The `main()` function is the entry point of the program. It initializes the system by calling `init()`, then enters a loop where users can select from a menu of operations (add, delete, search, etc.). The loop continues until the user chooses to exit.

#### Code Snippet
```c
int main(int argc, char *argv[]) {
    char input;
    init(); // Initialize with pre-set books

    do {
        print();
        printf(" Book Database \n");
        print();
        printf("--- 0 : Exit Program \n");
        printf("--- 1 : Add Book \n");
        printf("--- 2 : Delete Book \n");
        printf("--- 3 : Search Book \n");
        printf("--- 4 : Calculate Average Pages \n");
        printf("--- 5 : Display All Books \n");
        print();
        input = getch();
        system("CLS");

        switch (input) {
            case '0':
                exit(0);
            case '1':
                if (addBook() != 0) {
                    printf(" All spaces are occupied...\n");
                }
                break;
            case '2':
                if (deleteBook() != 0) {
                    printf(" Book could not be deleted...\n");
                }
                break;
            case '3':
                if (printBook() != 0) {
                    printf(" Book not found...\n");
                }
                break;
            case '4':
                printf(" Average number of pages: %.2f\n", calculateAveragePages());
                break;
            case '5':
                printAllBooks();
                break;
            default:
                break;
        }
    } while (input != '0');
}
```

### init()

The `init()` function is responsible for initializing the book database with a few pre-set books. These books are hardcoded into the program to allow testing without manually adding books every time the program runs.

#### Code Snippet
```c
void init(void) {
    strcpy(sBooks[0].title, "A Tale of Two Cities");
    strcpy(sBooks[0].author, "Charles Dickens");
    sBooks[0].pages = 448;
    sBooks[0].price = 7.99;

    strcpy(sBooks[1].title, "Pride and Prejudice");
    strcpy(sBooks[1].author, "Jane Austen");
    sBooks[1].pages = 279;
    sBooks[1].price = 5.99;
    
    // Additional books initialized similarly...
}
```

### print()

The `print()` function outputs a horizontal line across the console. It's used for formatting the output of the program and making menus more readable.

#### Code Snippet
```c
void print(void) {
    printf("--------------------------------------------------------\n");
}
```

### addBook()

This function allows the user to add a new book to the database. It takes user input for the book’s title, author, number of pages, and price, then adds this data to the first available slot in the `sBooks` array. If the array is full, the function returns an error.

#### Code Snippet
```c
int addBook(void) {
    int i = 0;
    char title[SIZE_TITLE];
    char author[SIZE_AUTHOR];

    while (sBooks[i].pages != 0) {
        i++;
    }

    if (i == SIZE_SHELF) {
        return 1; // No space left
    }

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);
    printf("Enter book author: ");
    fgets(author, sizeof(author), stdin);

    strcpy(sBooks[i].title, title);
    strcpy(sBooks[i].author, author);
    printf("Enter number of pages: ");
    scanf("%d", &sBooks[i].pages);
    printf("Enter price: ");
    scanf("%f", &sBooks[i].price);

    return 0;
}
```

### deleteBook()

The `deleteBook()` function allows the user to delete a book from the database by its title. It searches for the book and shifts all subsequent books up in the array to remove the empty spot.

#### Code Snippet
```c
int deleteBook(void) {
    char title[SIZE_TITLE];
    int is_found = 0;

    printf("Enter the title of the book to delete: ");
    fgets(title, sizeof(title), stdin);

    for (int i = 0; i < SIZE_SHELF; i++) {
        if (strcmp(sBooks[i].title, title) == 0) {
            for (int j = i; j < SIZE_SHELF - 1; j++) {
                sBooks[j] = sBooks[j + 1];
            }
            is_found = 1;
            break;
        }
    }

    if (!is_found) {
        return 1; // Book not found
    } else {
        return 0; // Book deleted
    }
}
```

### printBook()

The `printBook()` function allows the user to search for a book by its title and displays its details if found. It returns an error if the book is not found.

#### Code Snippet
```c
int printBook(void) {
    char title[SIZE_TITLE];
    int is_found = 0;

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);

    for (int i = 0; i < SIZE_SHELF; i++) {
        if (strcmp(sBooks[i].title, title) == 0) {
            printf("Title: %s\n", sBooks[i].title);
            printf("Author: %s\n", sBooks[i].author);
            printf("Pages: %d\n", sBooks[i].pages);
            printf("Price: %.2f\n", sBooks[i].price);
            is_found = 1;
            break;
        }
    }

    if (!is_found) {
        return 1;
    } else {
        return 0;
    }
}
```

### printAllBooks()

The `printAllBooks()` function outputs all books currently in the database, formatted in columns with titles, authors, pages, and prices.

#### Code Snippet
```c
void printAllBooks(void) {
    print();
    printf(" Book Collection \n");
    print();
    printf(" Title\t\tAuthor\t\tPages\t\tPrice\n");
    print();

    for (int i = 0; i < SIZE_SHELF && sBooks[i].pages != 0; i++) {
        printf(" %s\t\t%s\t\t%d\t\t%.2f\n", sBooks[i].title, sBooks[i].author, sBooks[i].pages, sBooks[i].price);
    }
}
```

### calculateAveragePages()

This function calculates and returns the average number of pages for all books currently in the database. It loops through the array and sums the number of pages, then divides by the total number of books.

#### Code Snippet
```c
float calculateAveragePages(void) {
    int total_pages = 0;
    int count = 0;

    for (int i = 0; i < SIZE_SHELF && sBooks[i].pages != 0; i++) {


        total_pages += sBooks[i].pages;
        count++;
    }

    if (count == 0) {
        return 0.0f; // Avoid division by zero
    }

    return (float) total_pages / count;
}
```

---

## Data Structures

The program uses the following structure to store book details:

```c
struct sBook {
    char title[SIZE_TITLE];
    char author[SIZE_AUTHOR];
    int pages;
    float price;
};
```

The books are stored in a global array of `sBook` structs, with a maximum capacity defined by `SIZE_SHELF`.

---

## Error Handling

- **Adding Books**: The function returns `1` if the database is full.
- **Deleting Books**: If the book title is not found, the function returns `1`.
- **Searching Books**: If the book title is not found, the function returns `1`.
- **Graceful Exits**: The program exits using `exit(0)` when the user selects the exit option from the menu.

---

## References

- [C Standard Library Documentation](https://en.cppreference.com/w/c)
- [Guide to C Strings and Character Arrays](https://www.learn-c.org/en/Strings)
- [How to Use fgets() in C](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)

--- 

This documentation provides a comprehensive guide for developers or users who wish to understand and modify the **Book Database Management Program**. It outlines the program’s architecture, functionality, and individual components with code examples for each function.

