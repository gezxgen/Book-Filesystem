/*************************** Project Information *****************************
 *Title:              main.c
 *Author:             Kevin
 *Date:               03.06.2024
 *Version:            1
 *Improvements:       -
 *Info:               A program to manage a simple book database.
 ******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bookfunctions.h"

/* Defines */
#define UE 129
#define OE 148
#define AE 132

/* Main function with command line arguments */
int main(int argc, char *argv[]) {
    /* Variables */
    char input;

    init();  /* Initialization to avoid manual input every time */

    /* Main loop */
    do {
        /* Available Functions */
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

        /* Switch case for the functions */
        switch (input) {
            /* Exit Program */
            case '0' :
                exit(0);

                /* Add Book */
            case '1' :
                /* Output if the book could be added */
                if (addBook() != 0) {
                    system("CLS");
                    print();
                    printf(" All slots are already occupied...\n");
                }
                break;

                /* Delete Book */
            case '2' :
                /* Output if the book could be deleted */
                if (deleteBook() != 0) {
                    system("CLS");
                    print();
                    printf(" Book could not be deleted...\n");
                }
                break;

                /* Search Book */
            case '3' :
                /* Output if the book was found */
                if (printBook() != 0) {
                    system("CLS");
                    print();
                    printf(" Book not found...\n");
                }
                break;

                /* Calculate Average Pages */
            case '4' :
                print();
                printf(" The average number of pages is: %.2f\n", calculateAveragePages());
                break;

                /* Display All Books */
            case '5' :
                printAllBooks();
                break;

                /* Default */
            default:
                break;
        }
    } while (input != '0');  /* Loop until the exit is selected */
}
