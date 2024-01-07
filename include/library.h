#ifndef LIBRARY_H
#define LIBRARY_H

#ifndef SONG
#define SONG

#define MAX_ZEILENLAENGE 100

typedef struct {
    char titel[MAX_ZEILENLAENGE];
    char interpret[MAX_ZEILENLAENGE];
    char album[MAX_ZEILENLAENGE];
    int erscheinungsjahr;
    int dauer;
} Song;
#endif

void Startroutine(void);
void BibliothekInitialisieren(Song **bibliothek, int *anzahl_songs);
void SongHinzufügen(Song **bibliothek, int *anzahl_songs);
void DatenÄndern(Song **bibliothek, int *anzahl_songs);
void SongLöschen(Song **bibliothek, int *anzahl_songs);
int SucheTitel(Song **bibliothek, int *anzahl_songs, char *gesuchterText);
void DatenSuchen(Song **bibliothek, int *anzahl_songs);
void BibliothekAnzeigen(Song *bibliothek, int anzahl_songs);
void DatenInDateiSpeichern(Song *bibliothek, int anzahl_songs);

#endif
