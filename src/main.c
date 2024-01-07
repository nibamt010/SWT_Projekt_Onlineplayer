#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(void) {
    Song *bibliothek = NULL;
    int auswahl;
    int anzahl_songs = 0;

    printf("\nHerzlich Willkommen im Dateimanagementsystem ihres Musikplayers!\n");

    Startroutine();

    BibliothekInitialisieren(&bibliothek, &anzahl_songs);

    do {
        printf("\n------------------- HAUPTMENÜ -------------------");
        printf("\n1. Song hinzufügen\n");
        printf("2. Meta-Daten eines Songs ändern\n");
        printf("3. Song löschen\n");
        printf("4. Nach Song oder Meta-Daten eines Songs suchen\n");
        printf("5. Musikbibliothek anzeigen\n");
        printf("6. Änderungen speichern\n");
        printf("7. Daten speichern und Programm beenden\n");

        printf("\nBitte wählen Sie einen Option (1-7): ");
        scanf("%d", &auswahl);
        printf("\n");

        switch (auswahl) {
            case 1:
                SongHinzufügen(&bibliothek, &anzahl_songs);
            break;

            case 2:
                DatenÄndern(&bibliothek, &anzahl_songs);
            break;

            case 3:
                SongLöschen(&bibliothek, &anzahl_songs);
            break;

            case 4:
                DatenSuchen(&bibliothek, &anzahl_songs);
            break;

            case 5:
                BibliothekAnzeigen(bibliothek, anzahl_songs);
            break;

            case 6:
                DatenInDateiSpeichern(bibliothek, anzahl_songs);
                printf("Die Änderungen wurden gespeichert.\n");
            break;

            case 7:
                DatenInDateiSpeichern(bibliothek, anzahl_songs);
                printf("Die Daten wurden gespeichert und das Programm wurde beendet.\n\n");
            break;

            default:
                printf("Ungültige Eingabe! Bitte wählen Sie erneut aus.\n");
        }
    }
    while (auswahl != 7);

    free(bibliothek);

    return 0;
}
