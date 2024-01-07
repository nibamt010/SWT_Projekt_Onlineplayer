#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "library.h"  // Ersetze dies durch den tatsächlichen Header für deine Funktionen und Strukturen

void test_SongHinzufuegen(void) {

    Song *bibliothek = NULL;
    int anzahl_songs = 1;
    bibliothek = (Song *)malloc((unsigned long)anzahl_songs * sizeof(Song));
    strcpy(bibliothek[0].titel, "Abc");
    strcpy(bibliothek[0].interpret, "MASA");
    strcpy(bibliothek[0].album, "MASA");
    bibliothek[0].erscheinungsjahr = 2077;
    bibliothek[0].dauer = 123;

    // Rufe die zu testende Funktion auf
    SongHinzufügen(&bibliothek, &anzahl_songs);

    // Führe die Assertions durch
    TEST_ASSERT_EQUAL_STRING("Abc", bibliothek[0].titel);  // Ersetze "Test Titel" durch den erwarteten Titel
    TEST_ASSERT_EQUAL_STRING("MASA", bibliothek[0].interpret);  // Ersetze "Test Interpret" durch den erwarteten Interpret
    // Füge weitere Assertions für Album, Erscheinungsjahr, Dauer usw. hinzu
    TEST_ASSERT_EQUAL_INT(2077, bibliothek[0].erscheinungsjahr);  // Ersetze 2022 durch das erwartete Erscheinungsjahr
    TEST_ASSERT_EQUAL_INT(123, bibliothek[0].dauer);  // Ersetze 300 durch die erwartete Dauer

    TEST_ASSERT_EQUAL_INT(2, anzahl_songs);  // Erwartet, dass die Anzahl der Songs auf 1 erhöht wurde

    // Gib den Speicher frei (nach der Verwendung)
    free(bibliothek);
}

void setUp()
{

}

void tearDown()
{

}

int main(void) {
    UNITY_BEGIN();

    // Füge deine Tests hier hinzu
    RUN_TEST(test_SongHinzufuegen);

    UNITY_END();

    return 0;
}
