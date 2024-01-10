Musik-Bibliothek

Das in C erstellte Programm dient zur Verwaltung einer Musik-Bibliothek, welche später von einem Online-Player genutzt werden soll. Das Programm verfügt über sieben verschiedene Funktionen und ist eine reine "Command-Line-Interface" (CLI) Anwendung. Demnach erfolgen die Eingaben/Ausgaben über das Terminal. 

Aufbau des Codes:

Es gibt eine main-Funktion, in der das "Hauptmenü" realisiert wurde. Von hier aus werden die Anwendungsoptionen in verschiedene void-Funktionen ausgelagert.


Ablauf:

Bevor man in das Hauptmenü gelangt muss der Benutzer zunächst entscheiden ob eine bestehende Bibliotheksdatei initialisiert oder eine neue Bibliotheksdatei erstellt werden soll. Dies erfolgt in der "Startroutine". Bei der Eingabe muss darauf geachtet werden, dass diese mit ".csv" endet, da das Programm nur mit Daten im CSV-Format arbeiten kann.
Nach erfolgreicher Initialisierung gelangt man in das Hauptmenü. Nun gibt es sieben verschiedene Anwendungsmöglichkeiten:

1. Song hinzufügen
2. Meta-Daten eines Songs ändern
3. Song löschen
4. Nach Song oder Meta-Daten eines Songs suchen
5. Musikbibliothek anzeigen
6. Änderungen speichern
7. Daten speichern und Programm beenden

Per switch-case-Anwendung springt das Programm in die jeweilige void-Funktion. Kommt es zu einer ungültigen Eingabe wird der Benutzer erneut aufgefordert eine Eingabe zu treffen.

Die DatenSuchen Funktion wurde zum Durchführen der Unit-Tests in mehrere kleine Unterfunktionen unterteilt (bspw. InterpretSuchen, AlbumSuchen, ...). Ebenso wurde ein Teil der BibliothekVerkleinern Funktion ausgelagert (SongLöschen) um den jeweiligen Unit Test durchführen zu können. Dies ist nötig, da aufgrund der benutzerabhängigen Eingaben ein Durchführen der Tests sonst nicht möglich wäre.

Testframework:

Zum Durchführen der Unit-Tests wird das Catch2-Framework verwendet.
Erwähnenswerte Datentypen:

Ein Song wird als struct abgelegt, in dem die verschiedenen Attribute wie Titel, Interpret, Album, Erscheinungsjahr und Dauer enthalten sind.

Zeiger werden verwendet, um dynamischen Speicher für die Musikbibliothek zu allozieren. Dies ermöglicht es, die Größe der Bibliothek zur Laufzeit zu ändern.

Doppelte Zeiger werden verwendet, um Adressen von Zeigern zu speichern, insbesondere für die dynamische Verwaltung von Speicherplatz für die Musikbibliothek.

Der Datentyp FILE wird verwendet, um einen Zeiger auf eine Datei zu speichern, insbesondere um auf die Musikbibliotheksdatei zuzugreifen.

Benutzung:

Der Code kann mit einem C-Compiler wie GCC oder Clang kompiliert werden. Die Unit-Tests selber werden mit einem G++ Compiler übersetzt.






