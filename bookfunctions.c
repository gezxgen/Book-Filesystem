/*************************** Project Information *****************************
 *Title:              bookfunctions.c
 *Author:             Kevin
 *Date:               03.06.2024
 *Version:            1
 *Info:               Source file for the functions used in the program.
 ******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "bookfunctions.h"

/* Defines */
#define UE 129
#define OE 148
#define AE 132

/* Creation of book structures */
struct Book books[SIZE_SHELF];

/* Initialize 5 books */
void init(void) {
    strcpy(books[0].title, "A Tale of Two Cities");
    strcpy(books[0].author, "Charles Dickens");
    books[0].pages = 448;
    books[0].price = 7.99;

    strcpy(books[1].title, "Pride and Prejudice");
    strcpy(books[1].author, "Jane Austen");
    books[1].pages = 279;
    books[1].price = 5.99;

    strcpy(books[2].title, "The Lord of the Rings");
    strcpy(books[2].author, "J.R.R. Tolkien");
    books[2].pages = 1077;
    books[2].price = 12.49;

    strcpy(books[3].title, "To Kill a Mockingbird");
    strcpy(books[3].author, "Harper Lee");
    books[3].pages = 281;
    books[3].price = 7.49;

    strcpy(books[4].title, "The Great Gatsby");
    strcpy(books[4].author, "F. Fitzgerald");
    books[4].pages = 180;
    books[4].price = 10.99;
}

/* Function to print a line of dashes */
void print(void) {
    printf("------------------------------------------------------------------------------\n");
}

/* Function to print a book's information */
int printBook() {
    char title[SIZE_TITLE];
    int found = 0;

    printf("Enter the book's title: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    for (int i = 0; i < SIZE_SHELF; i++) {
        if (strcmp(books[i].title, title) == 0) {
            system("CLS");
            print();
            printf(" Book Information \n");
            print();
            printf("--- Title\t: %s\n", books[i].title);
            printf("--- Author\t: %s\n", books[i].author);
            printf("--- Pages\t: %d\n", books[i].pages);
            printf("--- Price\t: %.2f-\n", books[i].price);
            found = 1;
            break;
        }
    }

    return !found;
}

/* Function to print all books */
void printAllBooks(void) {
    int i = 0;
    print();
    printf(" Book Shelf \n");
    print();
    printf(" Title\t\t\t\tAuthor\t\t\tPages\t\tPrice\n");
    print();
    while (books[i].pages != 0) {
        printf(" %s\t\t", books[i].title);
        printf("%s\t\t", books[i].author);
        printf("%d\t\t", books[i].pages);
        printf("%.2f-\n", books[i].price);
        i++;
    }
}

/* Function to calculate average pages of books */
float calculateAveragePages(void) {
    int total_pages = 0, i = 0;

    while (books[i].pages != 0) {
        total_pages += books[i].pages;
        i++;
    }
    return (float) total_pages / i;
}

/* Function to delete a book */
int deleteBook(void) {
    char title[SIZE_TITLE];
    int found = 0;

    printf("Enter the book's title: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    for (int i = 0; i < SIZE_SHELF; i++) {
        if (strcmp(books[i].title, title) == 0) {
            for (int j = i; j < (SIZE_SHELF - 1); j++) {
                strcpy(books[j].title, books[j + 1].title);
                strcpy(books[j].author, books[j + 1].author);
                books[j].pages = books[j + 1].pages;
                books[j].price = books[j + 1].price;
            }
            system("CLS");
            found = 1;
            break;
        }
    }

    return !found;
}

/* Function to add a new book */
int addBook(void) {
    int i = 0;
    char title[SIZE_TITLE], author[SIZE_AUTHOR];

    while (books[i].pages != 0) {
        i++;
    }

    if (i == 9) {
        system("CLS");
        return 1;
    }

    printf("Enter the book's title\t\t\t: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    printf("Enter the author's name\t\t\t: ");
    if (fgets(author, sizeof(author), stdin) != NULL) {
        size_t length = strlen(author);
        if (length > 0 && author[length - 1] == '\n') {
            author[length - 1] = '\0';
        }
    }

    /* Transfer the values */
    strcpy(books[i].title, title);
    strcpy(books[i].author, author);
    printf("Enter the number of pages of the book\t: ");
    scanf("%d", &books[i].pages);
    printf("Enter the price for the book\t\t: ");
    scanf("%f", &books[i].price);

    return 0;
}
