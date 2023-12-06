#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#define MAX_ZEILENLAENGE 20

/*struct Song{
char Titel[MAX_ZEILENLAENGE];
char Interpret[MAX_ZEILENLAENGE];
char Album[MAX_ZEILENLAENGE];
int Dauer[MAX_ZEILENLAENGE];
}*/

//void BibliothekInitialisieren(){}

int main()
{
int wahl;
while(wahl != 10){
    printf("Bibliothek Initialisieren -> 1\n");
    printf("Song hinzufügen -> 2\n");
    printf("Song löschen -> 3\n");
    printf("Metadaten eines Songs ändern -> 4\n");
    printf("Playlist erstellen -> 5\n");
    printf("Playlist bearbeiten -> 6\n");
    printf("Song Anzeigen -> 7\n");
    printf("Playlist anzeigen -> 8\n");
    printf("Bibliothk anzeigen -> 9\n");
    printf("Programm Beenden -> 10\n");
    printf("\n ->");
    scanf("%d", &wahl);

    switch (wahl){
        case 1:
            //BibliothekInitialisiern();
            printf("Bibliothek erfolgreich initialisiert\n");
            break;
        case 2:
            // Song Hinzufügen
            break;
        case 3:
            // Song löschen
            break;
        case 4:
            //Metadaten eines Songs ändern
            break;
        case 5:
            //Playlist erstellen
            break;
        case 6:
            //Playlist bearbeiten
            break;
        case 7:
            //Song anzeigen
            break;
        case 8:
            //Playlist anzeigen
            break;
        case 9:
            //Bibliothek anzeigen
        case 10:
        break;
        default:
            printf("Ungültige Wahl. Bitte erneut wählen\n ->");
            break;
    }
}
printf("\nProgramm Beendet");
return 0;

}
