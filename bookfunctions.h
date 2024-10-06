/*************************** Projektinformationen *****************************
 *Name:
 *Autor:              Kevin
 *Datum:              03.06.2024
 *Version:            1
 *Verbesserungen:     -
 *Infos:              Headerfile der Funktionen, die für das Programm benötigt werden.
 ******************************************************************************/

/* Wenn das File schon definiert wurde */
#ifndef BOOKS_BOOKFUNCTIONS_H
#define BOOKS_BOOKFUNCTIONS_H

/* Defines der Grössen */
#define SIZE_TITLE  100
#define SIZE_AUTHOR 50
#define SIZE_SHELF  10

/* Strukturvorlage */
struct sBook {
    char title[SIZE_TITLE];
    char author[SIZE_AUTHOR];
    int pages;
    float price;
};

/* Übergabe der Strukturen an das Main File,
 * kann auskommentiert werden,
 * falls diese im Main nicht benötigt werden */
extern struct sBook sBooks[SIZE_SHELF];

/* Funktionen, bzw. Funktionsheader */
void init(void);
int printBook(void);
void printAllBooks(void);
void print(void);
float calculateAveragePages(void);
int deleteBook(void);
int addBook(void);

/* Ende der If-Bedingung */
#endif //BOOKS_BOOKFUNCTIONS_H
