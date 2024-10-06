/*************************** Projektinformationen *****************************
 *Titel:
 *Name:               main.c
 *Autor:              Kevin
 *Datum:              03.06.2024
 *Version:            1
 *Verbesserungen:     -
 *Infos:              Es wird ein Programm...
 ******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "buchfunktionen.h"

/* Defines */
#define ue 129
#define oe 148
#define ae 132

/* Main Funktion mit Command line arguments */
int main(int argc, char *argv[]) {
    /* Variabeln */
    char cEingabe;

    init();     /* Initialisierung, um nicht immer alles einzugeben */

    /* Hauptschleife */
    do {
        /* Mögliche Funktionen */
        print();
        printf(" B%ccherdatenbank \n", ue);
        print();
        printf("--- 0 : Programm abbrechen \n");
        printf("--- 1 : Erfassen \n");
        printf("--- 2 : L%cschen \n", oe);
        printf("--- 3 : Suchen \n");
        printf("--- 4 : Durchschnittliche Seiten berechnen \n");
        printf("--- 5 : Ausgabe \n");
        print();
        cEingabe = getch();
        system("CLS");

        /* Switch Case der Funktionen */
        switch (cEingabe) {
            /* Programmabbruch */
            case '0' :
                exit(0);

            /* Erfassung */
            case '1' :
                /* Ausgabe, ob das Buch hinzugefügt werden konnte */
                if (addBook() != 0) {
                    system("CLS");
                    print();
                    printf(" Es sind bereits alle Pl%ctze belegt...\n", ae);
                }
                break;

            /* Löschung */
            case '2' :
                /* Ausgabe, ob Buch gelöscht wurde */
                if (deleteBook() != 0) {
                    system("CLS");
                    print();
                    printf(" Buch konnte nicht gel%cscht werden...\n", oe);
                }
                break;

            /* Suchen */
            case '3' :
                /* Ausgabe, ob Buch gefunden wurde */
                if (printBook() != 0) {
                    system("CLS");
                    print();
                    printf(" Buch nicht vorhanden...\n");
                }
                break;

            /* Durchschnittliche Seitenanzahl berechnen */
            case '4' :
                print();
                printf(" Die durchschnittliche Seitenanzahl ist: %.2f\n", calculateAveragePages());
                break;

            /* Ausgabe */
            case '5' :
                printAllBooks();
                break;

            /* Default */
            default:
                break;
        }
    } while (cEingabe != '0');      /* Solange der Abbruch nicht gedrückt wurde */
}
