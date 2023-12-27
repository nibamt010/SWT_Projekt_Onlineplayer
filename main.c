#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ZEILENLAENGE 100

char dateiname[MAX_ZEILENLAENGE];

typedef struct {
    char titel[MAX_ZEILENLAENGE];
    char interpret[MAX_ZEILENLAENGE];
    char album[MAX_ZEILENLAENGE];
    int erscheinungsjahr;
    int dauer;
} Song;

void Startroutine() {
    int auswahl = 0;
    FILE *fp = NULL;

    printf("\n------------------ STARTMENÜ --------------------\n");
    printf("1. Bestehende Bibliothek einlesen\n");
    printf("2. Neue Bibliothek erstellen\n\n");
    printf("Bitte wählen Sie einen Option (1-2): ");

    do {
        scanf("%d", &auswahl);

        switch (auswahl) {
            case 1:
                printf("\nGeben Sie den Namen der bestehenden Bibliothek ein (mit .csv am Ende des Dateinamens): ");
                scanf("%s", dateiname);

                fp = fopen(dateiname, "r");

                if (fp == NULL) {
                    printf("\nDie Bibliothek %s konnte nicht geöffnet werden!\n", dateiname);
                    exit(EXIT_FAILURE);
                }
                else {
                    printf("\nDie Bibliothek %s wurde erfolgreich geöffnet.\n", dateiname);
                    fclose(fp);
                }
                break;

            case 2:
                printf("\nGeben Sie den Namen der neuen Bibliothek ein (mit .csv am Ende des Dateinamens): ");
                scanf("%s", dateiname);

                fp = fopen(dateiname, "w");

                if (fp == NULL) {
                    printf("\nDie Bibliothek %s konnte nicht erstellt werden!\n", dateiname);
                    exit(EXIT_FAILURE);
                }
                else {
                    printf("\nDie Bibliothek %s wurde erfolgreich erstellt.\n", dateiname);
                    fclose(fp);
                }
                break;

            default:
                printf("\nUngültige Eingabe! Wählen Sie erneut aus: ");
                break;
        }
    }
    while ((auswahl != 1) && (auswahl != 2));
}

/* Funktionsargumente vom Typ Song ** und int *, da void-Funktion (keine Rückgabewerte -> Pointer)
 und eine "Pointerebene" höher als in main-Funktion */

void BibliothekInitialisieren(Song **bibliothek, int *anzahl_songs) {
    int eintraege = 0;
    char c = 0;
    FILE *fp = NULL;

    fp = fopen(dateiname, "r");

// Buchstabenweises Einlesen bis Zeilenende und anschließendes Hochzählen der Einträge der Musikbibliotheksdatei

    while ((c = (char)fgetc(fp)) != EOF) {
        if (c == '\n') {
            eintraege++;
        }
    }
    rewind(fp);

    *bibliothek = (Song *)malloc((unsigned long)eintraege * sizeof(Song));

/* Zeilenweises Einlesen und Abspeichern der Songs aus der Musikbibliotheksdatei in die Strukur Song *bibliothek
   fscanf-Befehl mit Format Specifier %[^,] bedeutet, dass bis zum Trennzeichen ',' eingelesen wird */

    for (int i = 0; i < eintraege; i++) {
        fscanf(fp, "%[^,],%[^,],%[^,],%d,%d\n",
                (*bibliothek)[i].titel,
                (*bibliothek)[i].interpret,
                (*bibliothek)[i].album,
                &(*bibliothek)[i].erscheinungsjahr,
                &(*bibliothek)[i].dauer);
    }
    *anzahl_songs = eintraege;
    fclose(fp);
}

void SongHinzufügen(Song **bibliothek, int *anzahl_songs) {
    *bibliothek = (Song *)realloc(*bibliothek,((unsigned long)(*anzahl_songs) + 1) * sizeof(Song));

/* scanf-befehl " %[^\n]" bedeutet, dass bis zum nächsten Zeilenumbruch einglesen wird
   Das Leerzeichen vor dem Format Specifier bewirkt, dass voranstehende Leerzeichen, inklusive Zeilenumbrüche, übersprungen werden, bevor die Eingabe gelesen wird */

    printf("\n---------------- SONG HINZUFÜGEN ----------------\n");
    printf("Geben Sie den Titel ein: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_songs].titel);
    printf("Geben Sie den Interpret ein: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_songs].interpret);
    printf("Geben Sie das Album ein: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_songs].album);
    printf("Geben Sie das Erscheinungsjahr ein: ");
    scanf("%d", &(*bibliothek)[*anzahl_songs].erscheinungsjahr);
    printf("Geben Sie die Dauer in Sekunden ein: ");
    scanf("%d", &(*bibliothek)[*anzahl_songs].dauer);
    printf("\nSong erfolgreich hinzugefügt!\n");

    (*anzahl_songs)++;
}

void DatenÄndern(Song **bibliothek, int *anzahl_songs) {
    char gesuchtersong[MAX_ZEILENLAENGE];
    int gesuchterIndex = -1;
    int auswahl;

    printf("\n--------------- DATEN BEARBEITEN ----------------");
    printf("\nGeben Sie den Titel des Songs an, den Sie bearbeiten wollen: ");
    scanf(" %[^\n]", gesuchtersong);

    for (int i=0; i < *anzahl_songs; i++) {
            if (strcmp((*bibliothek)[i].titel, gesuchtersong) == 0) {
            gesuchterIndex = i;
            }
        }

    if (gesuchterIndex != -1) {
        do {
            printf("\n--------------- DATEN BEARBEITEN ----------------");
            printf("\n1. Titel");
            printf("\n2. Interpret");
            printf("\n3. Album");
            printf("\n4. Erscheinungsjahr");
            printf("\n5. Länge");
            printf("\n6. Zurück zum Hauptmenü\n");
            printf("\nWählen Sie die Kategorie, die Sie ändern wollen (1-6): ");
            scanf("%d", &auswahl);

            switch(auswahl) {
                case 1:
                    printf("\nBitte neuen Titel eingeben: ");
                    scanf(" %[^\n]", (*bibliothek)[gesuchterIndex].titel);
                    printf("\nTitel erfolgreich geändert!\n");
                break;

                case 2:
                    printf("\nBitte neuen Interpret eingeben: ");
                    scanf(" %[^\n]", (*bibliothek)[gesuchterIndex].interpret);
                    printf("\nInterpret erfolgreich geändert!\n");
                break;

                case 3:
                    printf("\nBitte neues Album eingeben: ");
                    scanf(" %[^\n]", (*bibliothek)[gesuchterIndex].album);
                    printf("\nAlbum erfolgreich geändert!\n");
                break;

                case 4:
                    printf("\nBitte neues Erscheinungsjahr eingeben: ");
                    scanf("%d", &(*bibliothek)[gesuchterIndex].erscheinungsjahr);
                    printf("\nErscheinungsjahr erfolgreich geändert!\n");
                break;

                case 5:
                    printf("\nBitte neue Länge eingeben: ");
                    scanf("%d", &(*bibliothek)[gesuchterIndex].dauer);
                    printf("\nLänge erfolgreich geändert!\n");
                break;

                case 6:
                    printf("\n");
                break;

                default:
                    printf("\nUngültige Eingabe! Bitte wählen Sie erneut aus.\n");
                break;

            }
        }
        while (auswahl != 6);
    }
    else {
        printf("Song nicht gefunden!\n");
    }
}

void SongLöschen(Song **bibliothek, int *anzahl_songs) {
    int gelöschterIndex =-1;
    char geloeschtersong[MAX_ZEILENLAENGE];

    printf("\n----------------- SONG LÖSCHEN ------------------");
    printf("\nGeben Sie den Namen des zu löschenden Songs ein: ");
    scanf(" %[^\n]", geloeschtersong);

    for (int i=0; i < *anzahl_songs; i++) {
        if (strcmp((*bibliothek)[i].titel, geloeschtersong) == 0) {
        gelöschterIndex = i;
        }
    }

    if(gelöschterIndex == -1) {
        printf("Song nicht gefunden!\n");
        return;
    }

    // Nachfolgende Songs des gelöschten Songs werden in der Bibliothek um 1 nach vorne verschoben

    else {
        for (int i = gelöschterIndex; i < *anzahl_songs - 1; i++) {
            strcpy((*bibliothek)[i].titel, (*bibliothek)[i + 1].titel);
            strcpy((*bibliothek)[i].interpret, (*bibliothek)[i + 1].interpret);
            strcpy((*bibliothek)[i].album, (*bibliothek)[i + 1].album);
            (*bibliothek)[i].erscheinungsjahr = (*bibliothek)[i + 1].erscheinungsjahr;
            (*bibliothek)[i].dauer = (*bibliothek)[i + 1].dauer;
        }
    printf("Song erfolgreich gelöscht!\n");
    }

    (*anzahl_songs)--;

    *bibliothek = (Song *)realloc(*bibliothek,(unsigned long)(*anzahl_songs) * sizeof(Song));
}

void DatenSuchen(Song **bibliothek, int *anzahl_songs) {
    int auswahl;
    char gesuchterText[MAX_ZEILENLAENGE];
    int gesuchtesErscheinungsjahr;
    int gesuchterIndex = -1;

    do {
        printf("\n---------------------- SUCHE --------------------");
        printf("\nIn welcher Kategorie wollen Sie suchen?");
        printf("\n1. Titel");
        printf("\n2. Interpret");
        printf("\n3. Album");
        printf("\n4. Erscheinungsjahr");
        printf("\n5. Zurück zum Hauptmenü\n");
        printf("\nBitte Wählen Sie eine Option (1-5): ");
        scanf("%d", &auswahl);

        switch(auswahl) {
            case 1:
                printf("\nGeben sie den gesuchten Titel ein: ");
                scanf(" %[^\n]", gesuchterText);

                for (int i=0 ; i < *anzahl_songs ; i++) {
                    if (strcmp((*bibliothek)[i].titel, gesuchterText) == 0) {
                        gesuchterIndex = i;
                    }
                }

                if(gesuchterIndex == -1) {
                    printf("\nKein Suchergebnis!\n");
                    break;
                }
                else {
                    printf("\nSuchergebnis:\n");
                    printf("%s, %s, %s, %d, %d",
                            (*bibliothek)[gesuchterIndex].titel,
                            (*bibliothek)[gesuchterIndex].interpret,
                            (*bibliothek)[gesuchterIndex].album,
                            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
                            (*bibliothek)[gesuchterIndex].dauer);
                    printf("\n");
                }

            gesuchterIndex = -1;
            break;

            case 2:
                printf("\nGeben sie den gesuchten Interpreten ein: ");
                scanf(" %[^\n]", gesuchterText);

                for (int i=0 ; i < *anzahl_songs ; i++) {
                    if (strcmp((*bibliothek)[i].interpret, gesuchterText) == 0) {
                        gesuchterIndex = i;
                    }
                }

                if (gesuchterIndex == -1) {
                    printf("\nKein Suchergebnis!\n");
                    break;
                }
                else {
                    printf("\nSuchergebnis:\n");
                    printf("%s, %s, %s, %d, %d",
                            (*bibliothek)[gesuchterIndex].titel,
                            (*bibliothek)[gesuchterIndex].interpret,
                            (*bibliothek)[gesuchterIndex].album,
                            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
                            (*bibliothek)[gesuchterIndex].dauer);
                    printf("\n");
                }

            gesuchterIndex = -1;
            break;

            case 3:
                printf("\nGeben sie das gesuchte Album ein: ");
                scanf(" %[^\n]", gesuchterText);

                for (int i=0; i < *anzahl_songs; i++) {
                    if (strcmp((*bibliothek)[i].album, gesuchterText) == 0) {
                    gesuchterIndex = i;
                    }
                }

                if (gesuchterIndex == -1) {
                    printf("\nKein Suchergebnis!\n");
                    break;
                }
                else {
                    printf("\nSuchergebnis:\n");
                    printf("%s, %s, %s, %d, %d",
                            (*bibliothek)[gesuchterIndex].titel,
                            (*bibliothek)[gesuchterIndex].interpret,
                            (*bibliothek)[gesuchterIndex].album,
                            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
                            (*bibliothek)[gesuchterIndex].dauer);
                    printf("\n");
                }

            gesuchterIndex = -1;
            break;

            case 4:
                printf("\nGeben sie das gesuchte Erscheinungsjahr ein: ");
                scanf("%d", &gesuchtesErscheinungsjahr);

                for (int i=0; i < *anzahl_songs; i++) {
                    if ((*bibliothek)[i].erscheinungsjahr == gesuchtesErscheinungsjahr) {
                        gesuchterIndex = i;
                    }
                }

                if (gesuchterIndex == -1) {
                    printf("\nKein Suchergebnis!\n");
                    break;
                }
                else {
                    printf("\nSuchergebnis:\n");
                    printf("%s, %s, %s, %d, %d",
                            (*bibliothek)[gesuchterIndex].titel,
                            (*bibliothek)[gesuchterIndex].interpret,
                            (*bibliothek)[gesuchterIndex].album,
                            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
                            (*bibliothek)[gesuchterIndex].dauer);
                    printf("\n");
                }

            gesuchterIndex = -1;
            break;

            case 5:
                printf("\n");
            break;

            default:
                printf("\nUngültige Eingabe!Bitte wählen Sie erneut aus.\n");
        }
    }
    while (auswahl != 5);
}

void BibliothekAnzeigen(Song *bibliothek, int anzahl_songs) {
    printf("\n-------------- BIBLIOTHEK ANZEIGEN --------------\n");

    if(anzahl_songs == 0) {
        printf("\nBibliothek leer!");
    }
    else {
        for (int i = 0; i < anzahl_songs; i++) {
            printf("%s, %s, %s, %d, %d",
                    bibliothek[i].titel,
                    bibliothek[i].interpret,
                    bibliothek[i].album,
                    bibliothek[i].erscheinungsjahr,
                    bibliothek[i].dauer);
            printf("\n");
        }
    }
}

void DatenInDateiSpeichern(Song *bibliothek, int anzahl_songs) {
    FILE *fp = NULL;
    fp = fopen(dateiname, "w");

    for (int i = 0; i < anzahl_songs; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d\n",
                bibliothek[i].titel,
                bibliothek[i].interpret,
                bibliothek[i].album,
                bibliothek[i].erscheinungsjahr,
                bibliothek[i].dauer);
    }
    fclose(fp);
}

int main() {
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
