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






