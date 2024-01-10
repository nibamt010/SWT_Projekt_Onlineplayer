#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library.h"

TEST_CASE("Song Löschen") {
    Song *bibliothek = NULL;
    int anzahl_songs = 0;

        anzahl_songs = 3;
        bibliothek = new Song[anzahl_songs];

        strcpy(bibliothek[0].titel, "In the End");
        strcpy(bibliothek[1].titel, "Lose Yourself");
        strcpy(bibliothek[2].titel, "Smells like Teen Spirit");

        int gelöschterIndex = 1;

        REQUIRE(SongLöschen(&bibliothek, &anzahl_songs, gelöschterIndex) == 2);

        delete[] bibliothek;
    }


TEST_CASE("SucheTitel") {
    Song *bibliothek = NULL;
    int anzahl_songs = 0;

    SECTION("Suche nach vorhandenem Song") {
        anzahl_songs = 3;
        bibliothek = new Song[anzahl_songs];

        strcpy(bibliothek[0].titel, "In the End");
        strcpy(bibliothek[1].titel, "Lose Yourself");
        strcpy(bibliothek[2].titel, "Smells like Teen Spirit");

        char gesuchterTitel[] = "Lose Yourself";
        REQUIRE(SucheTitel(&bibliothek, &anzahl_songs, gesuchterTitel) == 1);

        delete[] bibliothek;
    }

    SECTION("Suche nach nicht vorhandenem Song") {
        anzahl_songs = 2;
        bibliothek = new Song[anzahl_songs];

        strcpy(bibliothek[0].titel, "In the End");
        strcpy(bibliothek[1].titel, "Lose Yourself");

        char gesuchterTitel[] = "Smells like Teen Spirit";
        REQUIRE(SucheTitel(&bibliothek, &anzahl_songs, gesuchterTitel) == -1);

        delete[] bibliothek;
    }

    SECTION("Suche in leerer Bibliothek") {
        anzahl_songs = 0;
        bibliothek = new Song[anzahl_songs];

        char gesuchterTitel[] = "In the End";
        REQUIRE(SucheTitel(&bibliothek, &anzahl_songs, gesuchterTitel) == -1);

        delete[] bibliothek;
    }
}

TEST_CASE("SucheAlbum") {
    Song *bibliothek = NULL;
    int anzahl_songs = 0;

    SECTION("Suche nach vorhandenem Album") {
        anzahl_songs = 3;
        bibliothek = new Song[anzahl_songs];

        strcpy(bibliothek[0].album, "Hybrid Theory");
        strcpy(bibliothek[1].album, "Curtain Call");
        strcpy(bibliothek[2].album, "Nevermind");

        char gesuchtesAlbum[] = "Curtain Call";
        REQUIRE(SucheAlbum(&bibliothek, &anzahl_songs, gesuchtesAlbum) == 1);

        delete[] bibliothek;
    }

    SECTION("Suche nach nicht vorhandenem Album") {
        anzahl_songs = 2;
        bibliothek = new Song[anzahl_songs];

        strcpy(bibliothek[0].album, "Hybrid Theory");
        strcpy(bibliothek[1].album, "Curtain Call");

        char gesuchtesAlbum[] = "Nevermind";
        REQUIRE(SucheAlbum(&bibliothek, &anzahl_songs, gesuchtesAlbum) == -1);

        delete[] bibliothek;
    }

    SECTION("Suche in leerer Bibliothek") {
        anzahl_songs = 0;
        bibliothek = new Song[anzahl_songs];

        char gesuchtesAlbum[] = "Hybrid Theory";
        REQUIRE(SucheAlbum(&bibliothek, &anzahl_songs, gesuchtesAlbum) == -1);

        delete[] bibliothek;
    }
}

TEST_CASE("SucheErscheinungsjahr") {
    Song *bibliothek = NULL;
    int anzahl_songs = 0;

    SECTION("Suche nach vorhandenem Song") {
        anzahl_songs = 3;
        bibliothek = new Song[anzahl_songs];

        bibliothek[0].erscheinungsjahr = 1997;
        bibliothek[1].erscheinungsjahr = 2005;
        bibliothek[2].erscheinungsjahr = 2022;

        int gesuchtesErscheinungsjahr = 2005;
        REQUIRE(SucheErscheinungsjahr(&bibliothek, &anzahl_songs, gesuchtesErscheinungsjahr) == 1);

        delete[] bibliothek;
    }


    SECTION("Suche nach nicht vorhandenem Song") {
        anzahl_songs = 3;
        bibliothek = new Song[anzahl_songs];

        bibliothek[0].erscheinungsjahr = 1997;
        bibliothek[1].erscheinungsjahr = 2005;
        bibliothek[2].erscheinungsjahr = 2022;

        int gesuchtesErscheinungsjahr = 2007;
        REQUIRE(SucheErscheinungsjahr(&bibliothek, &anzahl_songs, gesuchtesErscheinungsjahr) == -1);

        delete[] bibliothek;
    }

    SECTION("Suche in leerer Bibliothek") {
        anzahl_songs = 0;
        bibliothek = new Song[anzahl_songs];

        int gesuchtesErscheinungsjahr = 2007;
        REQUIRE(SucheErscheinungsjahr(&bibliothek, &anzahl_songs, gesuchtesErscheinungsjahr) == -1);

        delete[] bibliothek;
    }
}
