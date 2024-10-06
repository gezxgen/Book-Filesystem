/*************************** Projektinformationen *****************************
 *Name:
 *Autor:              Kevin
 *Datum:              03.06.2024
 *Version:            1
 *Verbesserungen:     -
 *Infos:              Sourcefile der Funktionen, die für das Programm benötigt werden.
 ******************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "buchfunktionen.h"

/* Defines */
#define ue 129
#define oe 148
#define ae 132

/* Erstellen der Strukturen */
struct sBook sBooks[SIZE_SHELF];

/* Initialisierung von 5 Büchern */
void init(void) {
    /* Initialisierung Buch für Buch */
    strcpy(sBooks[0].title, "A Tale of Two Cities");
    strcpy(sBooks[0].author, "Charles Dickens");
    sBooks[0].pages = 448;
    sBooks[0].price = 7.99;

    strcpy(sBooks[1].title, "Pride and Prejudice");
    strcpy(sBooks[1].author, "Jane Austen");
    sBooks[1].pages = 279;
    sBooks[1].price = 5.99;

    strcpy(sBooks[2].title, "The Lord of the Rings");
    strcpy(sBooks[2].author, "J.R.R Tokien");
    sBooks[2].pages = 1077;
    sBooks[2].price = 12.49;

    strcpy(sBooks[3].title, "To Kill a Mockingbird");
    strcpy(sBooks[3].author, "Harper Lee");
    sBooks[3].pages = 281;
    sBooks[3].price = 7.49;

    strcpy(sBooks[4].title, "The Great Gatsby");
    strcpy(sBooks[4].author, "F. Fitzgerald");
    sBooks[4].pages = 180;
    sBooks[4].price = 10.99;
}

/* Funktion, damit überall gleich viele '-' gedruckt werden */
void print(void) {
    printf("------------------------------------------------------------------------------\n");
}

/* Funktion, um alle Bücher zu drucken */
int printBook() {
    /* Variablen */
    char title[SIZE_TITLE];
    int is_found = 0;

    /* Eingabe & speichern des Strings */
    printf("Gebe den Titel des Buches ein: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        /* Entfernen des Null-terminators */
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    /* Die Datenbank durchsuchen */
    for (int i = 0; i < SIZE_SHELF; i++) {
        /* Wenn das Buch gefunden wurde */
        if (strcmp(sBooks[i].title, title) == 0) {
            /* Drucken von den Angaben */
            system("CLS");
            print();
            printf(" Buchinfos \n");
            print();
            printf("--- Titel\t: %s\n", sBooks[i].title);
            printf("--- Author\t: %s\n", sBooks[i].author);
            printf("--- Seiten\t: %d\n", sBooks[i].pages);
            printf("--- Preis\t: %.2f-\n", sBooks[i].price);
            is_found = 1;
            break;
        }
    }

    /* Return, um main mitzuteilen, ob das Buch gefunden wurde */
    if (!is_found) {
        return 1;
    } else {
        return 0;
    }
}

/* Funktion, um alle Bücher zu drucken */
void printAllBooks(void) {
    int i = 0;
    print();
    printf(" B%ccherregal \n", ue);
    print();
    printf(" Titel\t\t\t\tAuthor\t\t\tSeiten\t\tPreis\n");
    print();
    while (sBooks[i].pages != 0) {
        printf(" %s\t\t", sBooks[i].title);
        printf("%s\t\t", sBooks[i].author);
        printf("%d\t\t", sBooks[i].pages);
        printf("%.2f-\n", sBooks[i].price);
        i++;
    }
}

/* Funktion, um die durschnittlichen Seiten zu berechnen */
float calculateAveragePages(void) {
    int max_seiten = 0;
    int i = 0;

    while (sBooks[i].pages != 0) {
        max_seiten += sBooks[i].pages;
        i++;
    }
    return max_seiten / i;
}

/* Funktion, um ein Buch zu löschen */
int deleteBook(void) {
    /* Variablen */
    char title[SIZE_TITLE];
    int is_found = 0;

    /* Eingabe & speichern des Strings */
    printf("Gebe den Titel des Buches ein: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        /* Entfernen des Null-terminators */
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    /* Die Datenbank durchsuchen */
    for (int i = 0; i < SIZE_SHELF; i++) {
        /* Wenn das Buch gefunden wurde */
        if (strcmp(sBooks[i].title, title) == 0) {
            /* nachschieben vom Rest der Bücher */
            for (int j = i; j < (SIZE_SHELF - 1); j++) {
                strcpy(sBooks[j].title, sBooks[j + 1].title);
                strcpy(sBooks[j].author, sBooks[j + 1].author);
                sBooks[j].pages = sBooks[j + 1].pages;
                sBooks[j].price = sBooks[j + 1].price;
            }
            system("CLS");
            is_found = 1;
            break;
        }
    }

    /* Return, um main mitzuteilen, ob das Buch gefunden wurde */
    if (!is_found) {
        return 1;
    } else {
        return 0;
    }
}

/* Funktion, um ein neues Buch hinzuzufügen */
int addBook(void) {
    /* Variables */
    int i = 0;
    char title[SIZE_TITLE];
    char author[SIZE_AUTHOR];

    /* herausfinden, ab welchen Index hinzugefügt werden kann */
    while (sBooks[i].pages != 0) {
        i++;
    }

    /* Wenn alle Plätze bereits voll sind */
    if (i == 9) {
        system("CLS");
        return 1;
    }

    /* Eingabe vom Titel */
    printf("Gebe den Titel des Buches ein\t\t\t: ");
    if (fgets(title, sizeof(title), stdin) != NULL) {
        /* Entfernen des Null-terminators */
        size_t len = strlen(title);
        if (len > 0 && title[len - 1] == '\n') {
            title[len - 1] = '\0';
        }
    }

    /* Eingabe vom Author */
    printf("Gebe den Author des Buches ein\t\t\t: ");
    if (fgets(author, sizeof(author), stdin) != NULL) {
        /* Entfernen des Null-terminators */
        size_t length = strlen(author);
        if (length > 0 && author[length - 1] == '\n') {
            author[length - 1] = '\0';
        }
    }

    /* Übertragen der Werte */
    strcpy(sBooks[i].title, title);
    strcpy(sBooks[i].author, author);
    printf("Gebe die Anzahl Seiten vom neuen Buch ein\t: ");
    scanf("%d", &sBooks[i].pages);
    printf("Gebe den Preis vom neuen Buch ein\t\t: ");
    scanf("%f", &sBooks[i].price);

    return 0;
}


















