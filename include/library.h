#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_ZEILENLAENGE 100

typedef struct {
    char titel[MAX_ZEILENLAENGE];
    char interpret[MAX_ZEILENLAENGE];
    char album[MAX_ZEILENLAENGE];
    int erscheinungsjahr;
    int dauer;
} Song;

void Startroutine(void);
void BibliothekInitialisieren(Song **bibliothek, int *anzahl_songs);
void SongHinzufügen(Song **bibliothek, int *anzahl_songs);
void DatenÄndern(Song **bibliothek, int *anzahl_songs);
int SongLöschen(Song **bibliotehk, int *anzahl_songs, int gelöschterIndex);
void BibliothekVerkleinern(Song **bibliothek, int *anzahl_songs);
int SucheTitel(Song **bibliothek, int *anzahl_songs, char *gesuchterText);
int SucheAlbum(Song **bibliothek, int *anzahl_songs, char *gesuchterText);
int SucheErscheinungsjahr(Song **bibliothek, int *anzahl_songs, int gesuchtesErscheinungsjahr);
void DatenSuchen(Song **bibliothek, int *anzahl_songs);
void BibliothekAnzeigen(Song *bibliothek, int anzahl_songs);
void DatenInDateiSpeichern(Song *bibliothek, int anzahl_songs);

#endif
