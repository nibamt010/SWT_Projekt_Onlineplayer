#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library.h"

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
