/*************************** Project Information *****************************
 *Title:              bookfunctions.h
 *Author:             Kevin
 *Date:               03.06.2024
 *Version:            1
 *Info:               Header file for the functions needed for the program.
 ******************************************************************************/

/* Prevent redefinition */
#ifndef BOOKS_BOOKFUNCTIONS_H
#define BOOKS_BOOKFUNCTIONS_H

/* Define sizes */
#define SIZE_TITLE  100
#define SIZE_AUTHOR 50
#define SIZE_SHELF  10

/* Structure template */
struct Book {
    char title[SIZE_TITLE];
    char author[SIZE_AUTHOR];
    int pages;
    float price;
};

/* External declaration of the book structure for use in main file */
extern struct Book books[SIZE_SHELF];

/* Function prototypes */
void init(void);
int printBook(void);
void printAllBooks(void);
void print(void);
float calculateAveragePages(void);
int deleteBook(void);
int addBook(void);

#endif //BOOKS_BOOKFUNCTIONS_H
