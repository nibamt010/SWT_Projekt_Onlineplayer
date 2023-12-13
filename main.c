#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ZEILENLAENGE 100

char dateiname[MAX_ZEILENLAENGE];
int anzahl_songs = 0;

typedef struct  {
    char titel[MAX_ZEILENLAENGE];
    char interpret[MAX_ZEILENLAENGE];
    char album[MAX_ZEILENLAENGE];
    int erscheinungsjahr;
    int dauer;
} Song;

void BibliothekInitialisieren(Song **bibliothek, int *anzahl_songs)
{
    FILE *fp = NULL;
    int auswahl;
    printf("\nWollen Sie eine neue Bibliothek erstellen (1) oder eine vorhandene Bibliothek initialisieren(2)?\n");
    scanf("%d", &auswahl);
    switch (auswahl)    {

    case 1:
        printf("Geben Sie den Dateinamen der neuen Bibliothek ein:\n");
        scanf("%s", dateiname);
        fp = fopen(dateiname, "w+");
            if (fp == NULL)
            printf("Die Bibliotheksdatei %s konnte nicht erstellt werden\n", dateiname);
            else
            printf("\nDie Bibliotheksdatei %s wurde erfolgreich erstellt.", dateiname);
        break;

    case 2:
         while (fp == NULL) {
        printf("Geben Sie den Dateinamen der bestehenden Bibliothek ein:\n");
        scanf("%s", dateiname);
        fp = fopen(dateiname, "r");

            if (fp == NULL)
            printf("\nDie Bibliotheksdatei %s konnte nicht initialisiert werden.\n\n", dateiname);
         }
            // Zählen der Anzahl an Einträgen (Songs) in der Bibliotheksdatei
            int eintraege = 0;
            char c;
            while ((c = (char)fgetc(fp)) != EOF) {
                if (c == '\n')
                eintraege++;
            }
            rewind(fp);

            // Allokieren des Speichers für die Bibliothek
            *bibliothek= (Song *)malloc((unsigned long) eintraege * sizeof(Song));
                if (*bibliothek== NULL) {
                printf("Fehler beim Allokieren des Speichers für die Bibliothek.\n");
                fclose(fp);
                exit(EXIT_FAILURE);
                }

            // Lesen der Einträge (Songs) aus der Bibliotheksdatei und initialisieren Sie die Bibliothek
            for (int i = 0; i < eintraege; i++) {
                fscanf(fp, "%99[^,],%99[^,],%99[^,],%d,%d\n",
                            (*bibliothek)[i].titel,
                            (*bibliothek)[i].interpret,
                            (*bibliothek)[i].album,
                            &(*bibliothek)[i].erscheinungsjahr,
                            &(*bibliothek)[i].dauer);
                            }

            *anzahl_songs = eintraege;

            printf("\nDie Bibliothek %s wurde erfolgreich initialisiert.\n", dateiname);

            fclose(fp);
                break;

        default:
        printf("Ungültige Eingabe! Bitte Wählen Sie erneut.\n");
    }

}

void BibliothekAnzeigen(Song *bibliothek, int anzahl_songs)
{
    // Ausgabe der bestehenden Einträge in der Bibliothek
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

void SongHinzufügen(){
    FILE *fp;
    Song NeuerSong;

    // Benutzereingabe für den neuen Song
    printf("Geben Sie den Titel des Songs ein: ");
    scanf("%99s", NeuerSong.titel);

    printf("\nGeben Sie das Album des Songs ein: ");
    scanf("%99s", NeuerSong.album);

    printf("\nGeben Sie den Interpreten des Songs ein: ");
    scanf("%99s", NeuerSong.interpret);

    printf("\nGeben Sie das Erscheinungsjahr des Songs ein: ");
    scanf("%d", &NeuerSong.erscheinungsjahr);

    printf("\nGeben Sie die Dauer des Songs in Sekunden ein: ");
    scanf("%d", &NeuerSong.dauer);

    fp = fopen(dateiname,"a");

    if (fp == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei %s\n", dateiname);
        return;
    }else{
        // Song-Daten an die Datei anhängen
        fprintf(fp,"%s,%s,%s,%d,%d\n",
                NeuerSong.titel,
                NeuerSong.album,
                NeuerSong.interpret,
                NeuerSong.erscheinungsjahr,
                NeuerSong.dauer);
        printf("\nDer Song wurde erfolgreich zur Datei %s hinzugefügt.\n\n", dateiname);
    }
    // Datei schließen
    fclose(fp);
}

int main()
{
    Song *bibliothek = NULL;
    int auswahl;

    printf("\nHerzlich Willkommen im Dateimanagementsystem ihres Musikplayers!\n");

    BibliothekInitialisieren(&bibliothek, &anzahl_songs);

        do
       {
            printf("\n------------------ HAUPTMENÜ --------------------");
            printf("\n1. Song hinzufügen\n");
            printf("2. Meta-Daten eines Songs ändern\n");
            printf("3. Song löschen\n");
            printf("4. Nach Song oder Meta-Daten eines Songs suchen\n");
            printf("5. Musikbibliothek anzeigen\n");
            printf("6. Programm beenden\n");

            printf("\nBitte wählen Sie einen Option (1-6): ");

            scanf("%d", &auswahl);

            printf("\n");

            switch (auswahl)
            {
                case 1:
                    SongHinzufügen();
                    break;
                case 2:

                    break;

                case 3:

                    break;

                case 4:

                    break;

                case 5:
                    BibliothekAnzeigen(bibliothek, anzahl_songs);
                    break;

                case 6:
                    printf("Das Programm wird beendet.\n\n");
                    break;

                default:
                    printf("Ungültige Eingabe!\nBitte wählen Sie erneut aus.\n");
            }
        }
        while (auswahl != 6);

    free(bibliothek);

    return 0;
}
