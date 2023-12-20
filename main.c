#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ZEILENLAENGE 100
#define MAX_SONGS 100

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
        *bibliothek= (Song *)malloc(MAX_SONGS * sizeof(Song));
                if (*bibliothek== NULL) {
                printf("Fehler beim Allokieren des Speichers für die Bibliothek.\n");
                fclose(fp);
                exit(EXIT_FAILURE);
                }
                else{
                printf("Bibliothek erfolgreich erstellt!\n");
                }
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
            *bibliothek= (Song *)malloc(MAX_SONGS * sizeof(Song));
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
    if(anzahl_songs == 0){
    printf("\nBibliothek leer!");
    }
    else{
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
}

void SongHinzufügen(Song **bibliothek, int *anzahl_songs)
{
    if (*anzahl_songs >= MAX_SONGS) {
        printf("Die maximale Anzahl an Songs in der Bibliothek wurde erreicht.\n");
        return;
    }
    printf("\nGeben Sie den Titel ein: ");
    scanf("%s", (*bibliothek)[*anzahl_songs].titel);

    printf("\nGeben Sie den Interpret ein: ");
    scanf("%s", (*bibliothek)[*anzahl_songs].interpret);

    printf("\nGeben Sie das Album ein: ");
    scanf("%s", (*bibliothek)[*anzahl_songs].album);

    printf("\nGeben Sie das Erscheinungsjahr ein: ");
    scanf("%d", &(*bibliothek)[*anzahl_songs].erscheinungsjahr);

    printf("\nGeben Sie die Dauer in Sekunden ein: ");
    scanf("%d", &(*bibliothek)[*anzahl_songs].dauer);

    (*anzahl_songs)++;

    printf("Song erfolgreich hinzugefügt!\n");
}

void SongLöschen(Song **bibliothek, int *anzahl_songs){

    int gelöschterIndex =-1;
    char geloeschtersong[MAX_ZEILENLAENGE];
    printf("\nGeben Sie den Namen des zu löschenden Songs ein: ");
    scanf("%99s", geloeschtersong);


    for (int i=0 ; i < *anzahl_songs ; i++){
        if ( strcmp((*bibliothek)[i].titel, geloeschtersong) == 0){
        gelöschterIndex = i;
        }
    }

    if(gelöschterIndex == -1){
    printf("Song nicht gefunden!");
    return;
    }
    else{
        for (int i = gelöschterIndex; i < *anzahl_songs - 1; i++) {
        strcpy((*bibliothek)[i].titel, (*bibliothek)[i + 1].titel);
        strcpy((*bibliothek)[i].interpret, (*bibliothek)[i + 1].interpret);
        strcpy((*bibliothek)[i].album, (*bibliothek)[i + 1].album);
        (*bibliothek)[i].erscheinungsjahr = (*bibliothek)[i + 1].erscheinungsjahr;
        (*bibliothek)[i].dauer = (*bibliothek)[i + 1].dauer;
        }
    printf("Song erfolgreich gelöscht!");
    }
// Reduziere die Anzahl der Songs in der Bibliothek
(*anzahl_songs)--;
}

void DatenSuchen(Song **bibliothek, int *anzahl_songs){
int auswahl;
char gesuchterText[MAX_ZEILENLAENGE];
int gesuchtesErscheinungsjahr;
int gesuchterIndex = -1;

do{
printf("\n------------------ SUCHE --------------------");
printf("\nIn welcher Kategorie wollen Sie suchen?");
printf("\n1. Titel");
printf("\n2. Interpret");
printf("\n3. Album");
printf("\n4. Erscheinungsjahr");
printf("\n5. Zurück zum Hauptmenü\n");
printf("\nBitte Wählen Sie eine Option (1-5): ");
scanf("%d", &auswahl);

switch(auswahl){
    case 1:
        printf("\nGeben sie den gesuchten Titel ein: ");
        scanf("%99s", gesuchterText);

        for (int i=0 ; i < *anzahl_songs ; i++){
            if ( strcmp((*bibliothek)[i].titel, gesuchterText) == 0){
            gesuchterIndex = i;
            }
        }
        if(gesuchterIndex == -1){
            printf("\nKein Suchergebnis!\n");
            break;
        }
        else{
            printf("\nSuchergebnis:\n");
            printf("%s, %s, %s, %d, %d",
            (*bibliothek)[gesuchterIndex].titel,
            (*bibliothek)[gesuchterIndex].interpret,
            (*bibliothek)[gesuchterIndex].album,
            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
            (*bibliothek)[gesuchterIndex].dauer);
            printf("\n");
        }
    break;
    case 2:
        printf("\nGeben sie den gesuchten Interpreten ein: ");
        scanf("%99s", gesuchterText);

        for (int i=0 ; i < *anzahl_songs ; i++){
            if ( strcmp((*bibliothek)[i].interpret, gesuchterText) == 0){
            gesuchterIndex = i;
            }
        }
        if(gesuchterIndex == -1){
            printf("\nKein Suchergebnis!\n");
            break;
        }
        else{
            printf("\nSuchergebnis:\n");
            printf("%s, %s, %s, %d, %d",
            (*bibliothek)[gesuchterIndex].titel,
            (*bibliothek)[gesuchterIndex].interpret,
            (*bibliothek)[gesuchterIndex].album,
            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
            (*bibliothek)[gesuchterIndex].dauer);
            printf("\n");
        }
    break;
    case 3:
        printf("\nGeben sie das gesuchte Album ein: ");
        scanf("%99s", gesuchterText);

        for (int i=0 ; i < *anzahl_songs ; i++){
            if ( strcmp((*bibliothek)[i].album, gesuchterText) == 0){
            gesuchterIndex = i;
            }
        }
        if(gesuchterIndex == -1){
            printf("\nKein Suchergebnis!\n");
            break;
        }
        else{
            printf("\nSuchergebnis:\n");
            printf("%s, %s, %s, %d, %d",
            (*bibliothek)[gesuchterIndex].titel,
            (*bibliothek)[gesuchterIndex].interpret,
            (*bibliothek)[gesuchterIndex].album,
            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
            (*bibliothek)[gesuchterIndex].dauer);
            printf("\n");
        }
    break;
    case 4:
        printf("\nGeben sie das gesuchte Erscheinungsjahr ein: ");
        scanf("%d", gesuchtesErscheinungsjahr);

        for (int i=0 ; i < *anzahl_songs ; i++){
            if ((*bibliothek)[i].erscheinungsjahr == gesuchtesErscheinungsjahr){
            gesuchterIndex = i;
            }
        }
        if(gesuchterIndex == -1){
            printf("\nKein Suchergebnis!\n");
            break;
        }
        else{
            printf("\nSuchergebnis:\n");
            printf("%s, %s, %s, %d, %d",
            (*bibliothek)[gesuchterIndex].titel,
            (*bibliothek)[gesuchterIndex].interpret,
            (*bibliothek)[gesuchterIndex].album,
            (*bibliothek)[gesuchterIndex].erscheinungsjahr,
            (*bibliothek)[gesuchterIndex].dauer);
            printf("\n");
        }
    break;
    case 5:
    printf("\n");
    break;
    default:
    printf("\nUngültige Eingabe!Bitte wählen Sie erneut aus.\n");
}
}while(auswahl != 5);
}

void DatenÄndern(Song **bibliothek, int *anzahl_songs){
    char gesuchtersong[MAX_ZEILENLAENGE];
    char neuertitel[MAX_ZEILENLAENGE];
    int gesuchterIndex = -1;
    int auswahl;

    printf("\n---------------- DATEN BEARBEITEN ------------------");
    printf("\nGeben Sie den Titel des Songs an, den Sie bearbeiten wollen: ");
    scanf("%99s", gesuchtersong);


    for (int i=0 ; i < *anzahl_songs ; i++){
        if ( strcmp((*bibliothek)[i].titel, gesuchtersong) == 0){
        gesuchterIndex = i;
        }
    }

    if(gesuchterIndex != -1){
    do{
        printf("\n---------------- DATEN BEARBEITEN ------------------");
        printf("\n1. Titel");
        printf("\n2. Interpret");
        printf("\n3. Album");
        printf("\n4. Erscheinungsjahr");
        printf("\n5. Länge");
        printf("\n6. Zurück zum Hauptmenü\n");
        printf("\nWählen Sie die Kategorie, die Sie ändern wollen (1-6): ");
        scanf("%d", &auswahl);

        switch(auswahl)
        {
            case 1:
            printf("\nBitte neuen Titel eingeben: ");
            scanf("%s", (*bibliothek)[gesuchterIndex].titel);
            printf("\nTitel erfolgreich geändert!\n");
            break;
            case 2:
            printf("\nBitte neuen Interpret eingeben: ");
            scanf("%s", (*bibliothek)[gesuchterIndex].interpret);
            printf("\nInterpret erfolgreich geändert!\n");
            break;
            case 3:
            printf("\nBitte neues Album eingeben: ");
            scanf("%s", (*bibliothek)[gesuchterIndex].album);
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

    }while(auswahl != 6);
    }else{
        printf("Song nicht gefunden!");
    }
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
                    printf("Das Programm wird beendet.\n\n");
                    break;

                default:
                    printf("Ungültige Eingabe! Bitte wählen Sie erneut aus.\n");
            }
        }
        while (auswahl != 6);

    free(bibliothek);

    return 0;
}
