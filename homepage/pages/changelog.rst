Veröffentlichungsinformationen
==============================

:slug: changelog
:status: hidden
:order: 11

Veröffentlichungen chronologisch absteigend seit der ersten Beta Release.

2018.02.25
----------

Wording:
  + ecs: Öffentliches Register: "Prüfärtzin/arzt" wurde durch "Prüfärztin/arzt" ersetzt

2018.02.18
----------

Features:
  + ecs-appliance: Neuer Link für PDF-AS (noch benötigte Unterstützung für online signing)


2018.02.11
----------

Features:
  + ecs-appliance: Update des Metric Systems
  + ecs-docs: neuer Screencast "Durchlauf einer Sitzung" auf der Homepage verfügbar
  + ecs: #676 Unterstützung für Emails mit Zeichensatz iso-8859-8-i und iso-8859-8-e

Wording: 
  + ecs: #683 Der Hilfetext für neue Nachrichten wurde adaptiert

Bugfixes: 
  + ecs: #675 "Protokoll Versenden" wird jetzt nur für die Office-Gruppe angezeigt
  
2018.01.28
----------

Features:
  + ecs-appliance: Update des Metric Systems
  
2018.01.14
----------

Features:
  + ecs-appliance: Update der ssl tunnel configuration

2017.11.12
----------

Features:
  + ecs-appliance: Änderungen am Metric System

2017.10.23
----------

Features:
  + ecs-docs: Eine detailierte Beschreibung der Funktionalität des Agenda- und Protkollversendens wurde in die Dokumentation hinzugefügt
    
2017.10.19
----------

Features:
  + ecs-appliance: das Metric System wurde fehlerressistenter gemacht

2017.09.23
----------

Features:
  + ecs-appliance: #673 Alte Backups werden jetzt nach Ablauf der Zeit korrekt gelöscht

2017.08.13
---------- 

Features:
  + ecs-appliance: #664, #665 Zusätzliche Alarme wenn das Backup oder ein Update nicht innerhalb der erwarteten Zeit gestartet worden sind

2017.07.31
----------

Features:
  + ecs-appliance: Aktualisierung der E-Card/Buergerkarten Software Mocca 1.3.27 (inkludiert Unterstützung für CardOSV5.3) & PDF-AS 4.1.0 

2017.04.29
----------

Bugfixes:
  + #656: Ein Amendment konnte auf Grund von nicht sichtbaren Sonderzeichen im Text nicht eingereicht werden
  
2017.04.12
----------

Features:
  + #654 Verbesserter Email Empfang in das ECS

2017.04.09
----------

Features:
  + #653 Verbesserter Email Versand (DKIM-Support)

2017.04.02
----------

Bugfixes:
  + #652: Nachrichten die an sich selber geschickt und mit einen Stern
    markiert worden sind können jetzt genauso wie andere Nachrichten
    durch klicken auf Stern aus der Übersicht entfernt werden.
  + #644: ZIP Dateien werden korrekt bereitgestellt auch wenn sie ein
    Dokument vor 1980 als Erstellungsdatum beinhalten.
  + #648: Der Text der b2 Erinnerungsnachrichten wurde geändert und
    wird nach 6 Monaten an die Einreichenden Parteien und nach 12
    Monaten erneut inklusive Geschäftsstelle versendet.

2017.03.20
----------

Bugfixes:
  + #650: Ein Fehler der bei der Eingabe des Barcodes auftrat, 
    wurde behoben.
  + master: Die zu frühe Löschung von temporären Dateien wurde wieder
    auf 30 Tage geändert.

2017.03.12
----------

Bugfixes:
  + #646: Die Registrierung mit Gmail-Adressen funktioniert wieder.
Features:
  + #647: Das Login Formular wurde für mobile Geräte optimiert.


2017.03.06
----------

Bugfixes:
  + #638: Wenn der gleiche Spezialist eine manuelle erstellte Bewertung
    und eine durch die Spezialistenzuordnung generierte Spezialisten-
    bewertung hat konnte in der Zeitplanung dieser nicht aus einem TOP
    als Teilnehmer entfernt werden. Dieser Fehler wurde behoben.
  + #641: Es trat ein Fehler beim Rendern von zwei Studien auf. 
    Ggf. müssen die Einreicher eine leere Neueinreichung machen um das
    erneute Rendern des PDFs anzustoßen.
  + #603: Mehrfachklicks beim erneuten Öffnen einer Bewertung lösen
    jetzt einen 404 Fehler aus, anstatt die selbe Bewertungsaufgabe 
    mehrfach zu öffnen.

Features:
  + #615: Die Performance der Statistik Seite wurde optimiert.


2017.02.26
----------

Bugfixes:
  + #618: Ein Fehler in der Differenzanzeige, wenn der gleiche
    Prüfzentren-Name und verschiedene Ethikkommissionen ausgewählt
    wurden, ist behoben.
  + #637: Wenn zu einem ansonsten leeren Zentrum versehentlich
    MitarbeiterInnen eingetragen werden, kommt es zu keinem Fehler mehr.

Features:
  + #488: In Ansicht aller Nachrichten können jetzt Nachrichten nach
    Schlüsselwörter wie Betreff, Ab-/Sender, EK-Nummer und Gesamtinhalt
    der Nachrichten durchsucht werden.
  + #579: Im Generel Status Reiter wird jetzt für Lokale AMG als Phase
    "Unbekannt (lokale EK)" anstatt "abgelaufen" oder "aktiv" angezeigt.
  + #630: Es wurden Fragebogen, Unterschriftenseite, Gebrauchsanweisung
    und Konformitätserklärung als Dokumententyp hinzugefügt.
  + #631: Die Benutzergruppe "EC-Executive Board Member" wurde zum
    besseren Verständnis in "EC-Executive" umbenannt.
  + #540: Für interne Benutzer wird der Einreicher als erstes im Feld
    "beteiligte Parteien" bei einer neuen Nachricht angezeigt.
  + #623: Für interne Benutzer wird das Feld "beteiligte Parteien" beim
    Erstellen einer neuen Nachricht vorausgewählt.
  + #565: Im Votumsarbeitsablauf ist das Häkchen bei "Korrektur gelesen
    und gültig" jetzt immer ungesetzt.
  + #609: Die Sitzungsübersichtseite wurde neu gestaltet.
  + #606: Der Top und Einreichungen Reiter in Sitzungen wurde zusammen
    gefügt und jetzt werden alle benötigten Informationen im
    Einreichungen Reiter angezeigt. 
  + #575: Sicherheit: Das verändern der Sitzungsplanung ist bei
    gestarteter Sitzung nicht möglich.
  + #640: Die Suche nach einem TOP im Suchfeld im Sitzungseditor
    funktioniert jetzt auch mit Eingabe von "TOP x" und nicht nur wie
    vorher mit "TOPx".

Wording:
  + Bei manuellen TOPs im Sitzungseditor wurde der doppelt angezeigte Titel entfernt.
  
2017.02.17
----------

Bugfixes:
  + #629: Der Fehler, dass die Studien wo Zeiteinschränkungen in der
    Zeitplanung nicht rot angezeigt werden, wurde behoben.
  + #614: Die Sitzungsübersicht Anzeige springt nicht mehr mehrere
    Zeilen nach unten.
  + #604: Bewertungen die mittels Doppelklick zwei mal neu geöffnet
    werden, lösen jetzt nur noch eine erneute Öffnung aus.
  + #593: Ein Darstellungsproblem für Benutzer die ein neues Zertifikat
    bekommen und gleichzeitig als verhindert markiert sind wurde behoben.
  + #613: Der Notizblock speichert jetzt automatisch den Inhalt wenn er
    durch ein Neuladen der Seite (z.B.: Abschließen einer Aufgabe)
    geschlossen wird.

Features:
  + #621: In der Dokumentenansicht wird für interne Benutzer Version und
    Datum in der Tabbenennung als erstes gereiht.
  + #578: Alle Bewertungen haben jetzt ein PDF das heruntergeladen
    werden kann.
  + #597: Die Perfomance der Meldungserstellung "Zentrum schließen"
    wurde optimiert
  + #616: Im Zentren Reiter werden die Zentren in Unterreitern
    dargestellt. Geschlossene Zentren werden jetzt ausgegraut dargestellt.
    Die Unterreiter der einzelnen Zentren tragen jetzt automatisch den Namen
    vom Feld "Prüfzentrum".
  + #619: Die Farbe des Buttons "Fertig" in Meldungsbewertung Office
    wurde wurde grün hinterlegt um die gleiche Farbgebung wie bei den
    anderen Aufgaben zu haben.

Wording:
  + #608:
      + "Substantial" wurde durch "Substantiell" und "Meeting" durch
        "Sitzung" in der Leseansicht von Meldungen ersetzt.
      + In der Nachrichten Ansicht wurde ein Tippfehler "... schreiben
        sie ..." zu  "... schreiben Sie ..." ausgebessert.
      + Wenn in der Übersicht keine Aufgaben für einen Benutzer
        vorhanden sind wird statt "Sie haben derzeit keine Aufgaben.", "Keine
        Aufgaben" angezeigt.
      + Der Button "Amendment" wurde in "Neues Amendment" umbenannt um
        Verwechslungen vorzubeugen.
  + #624: "Subject" in neuen Nachrichten wurde als "Betreff" übersetzt.
  + #625: "No temporary authorizations yet." wurde in "Keine befristete
    Autorisierung vorhanden." übersetzt.

2017.02.09
----------

Bugfixes:
  + #474: Der Kommentar Button speichert jetzt auch unter iOS.
  + #607: Die Reiter einer Studie brechen jetzt wieder um wenn
    das Browserfenster sehr klein ist.
  + #533: Ein Fehler bei den Erinnerungsnachrichten für ablaufende /
    abgelaufene Voten wurde ausgebessert. Die Votumserinnerungen
    sollten jetzt wieder erwartungsgemäß funktionieren.
  + master: Tätigkeitserinnerungen von bereits abgeschlossenen 
    Tasks lösen keine Erinnerung mehr aus.

Features:
  + master: Die Funktion Tätigkeitenerrinnerung hat eine weitere
    Einstellung bekommen (Erinnerung nach 2 Tagen)
  + #610: Das Logo wurde überarbeitet und besser positioniert.
  + #598: Die Ausfüllhilfen im PDF wurden gelöscht, da diese nach
    Absprache mit den Vorsitzenden nicht sinnvoll sind. Im Reiter
    Biometrie wurde eine Ausfüllhilfe ergänzt: 
    "Hier nur Kurzinformationen in Stichworten, ausführlicher - wenn
    erforderlich - unter Punkt 7.15 und 7.16)"

2017.02.05
----------

Bugfixes:
  + #600: Die BenutzerInnen sehen jetzt immer die richtige Layoutversion
    (unabhängig vom Browser Cache) und müssen jetzt nicht mehr
    STRG-SHIFT-R (Reload) drücken um die neue Layoutversion zu sehen.

2017.02.02
----------

Bugfixes:
  + #538: Das "Springen" der Textfelder war für einen Tag zurück
    und ist jetzt wieder behoben.
  + #484: Das Signierungsfeld wird jetzt auch für 
    Kartenleser mit Tastatur richtig angezeigt

Features:
  + #588: "Änderungen verwerfen" einer nicht eingereichten Version einer
    Studie wird jetzt direkt im Generell Status Reiter angezeigt und
    nicht mehr in der Liste "Meine Studien".

2017.01.31
----------

Bugfixes:
  + #599: Das Einreichen von Studien mittels Internet Explorer bei
    Änderungen an den Mitarbeitern im Zentren Reiter funktioniert wieder

Features:
  + #536 und #526: Das Verhalten von Auswahlfeldern wurde verbessert
  + #563: Die Notizblock Funktion wurde überarbeitet. Der Notizblock
    öffnet sich jetzt in einer geteilten Bildschirmansicht um leichter
    Notizen zu der aktuellen Ansicht zu machen.
  + #550 Das Boostrap CSS Framework wurde aktualisiert. 
    Damit einhergehend sind verschiedene kleine Layoutänderungen.
  + #484 Das Signierungsfeld wurde vergrößert und zeigt
    jetzt den gesamten Inhalt an

2017.01.26
----------
 
Bugfixes:
  + #592: Der Export von Studien funktioniert wieder.
  + #580: Sicherheitsmeldungen mit einer großen Anzahl von Studien
    werden jetzt ohne Fehler erstellt.
  + #590: Das Layout des Textfeld in der Schreibansicht für die Formale
    Prüfung von Amendments ist wieder repariert.
Features:
  + #502: Aufgabenarten haben jetzt die gleiche Benennung in der Suche
    der Benutzerverwaltung wie in der Schreibansicht eines Benutzers
    in der Benutzerverwaltung.
  + #547: Die Verschlüsselungsstärke der Zerifikatspasswörter wurde
    optimiert.

2017.01.24
----------

Bugfixes:
  + #583 Der eingebaute PDF-Viewer zeigt das Datum des Dokuments jetzt korrekt an.
  + #517 Textfelder mit langen Text werden jetzt wieder vollständig angezeigt

Features:
  + #561 Die Überschrift im Gutachter PDF wurde verkleinert.
  + #559 "( Kurzbezeichnung!)" ist jetzt in einer Zeile im Einreichungs-PDF
  + #513 und #542 Die Ansicht bei "neue Meldung erstellen" wurde verbessert
  + #582 weitere Perfomance Optimierungen
  + #572 Das Textfeld im Sitzungsassistenten ist jetzt breiter
  + #577 Das Bestätigen von weiteren TOPs in der Sitzung wurde optimiert
  + #576 Nicht eingereichte Meldungen weren jetzt auch im Reiter offene Meldungen der jeweiligen Studie angezeigt

Wording:
  + #584 Other TOPs wurde übersetzt

2017.01.16
----------

Bugfixes:
  + #482: Das Protokoll PDF wird jetzt so wie das Studien PDF
    erstellt und ist erst nach Fertigstellung herunter zu laden.

2017.01.12
----------

Bugfixes:
  + #514: Die PDFs von zwei Einreichungen die nicht in ein PDF 
    umgewandelt werden konnten, werden jetzt richtig gerendert. Bitte
    beachten Sie dazu, dass die *Einreicher* eine *neue* Version ihrer
    Studie einreichen muss. Es kann natürlich auch eine Version ohne
    Änderung sein. Geben Sie bitte den Einreichern Bescheid!
  + #556: Die Anzeige der substanziellen Amendments für Spezialisten
    wurde korrigiert.
 
Features:
  + #557: Nicht eingereichte Meldungen in offene Meldung Ansicht 
    werden jetzt nach Datum der letzten Änderung sortiert.
  + #541: Die Differenzanzeige zeigt hinzugekommene Änderungen jetzt fett
    geschrieben an und Streichungen durchgestrichen. Dies betrifft auch
    die PDFs. Dadurch wird die Lesbarkeit auch für farben-schwache bzw.
    -blinde Personen und für den Schwarz/Weiß Ausdruck gewährleistet.

Wording:
  + #553: Der Tippfehler bei "nur gebärfähige" 2.10.5 im 
    Einreichungs-PDF wurde ausgebessert.
 
2017.01.11
----------

Bugfixes:
  + #538: Das Einfügen und Löschen von Text in einen großen Eingabefeld
    löst jetzt kein "herum springen" des Inhalts mehr aus.
  + #552: Die Liste der Substanziellen Amendments im SitzungsTab wird
    jetzt auch für nicht interne BenutzerInnen richtig angezeigt.
 
Features:
  + Der Title der Studie in der Differenzanzeige wird jetzt genau wie in der Leseansicht angezeigt und ist clickbar.
 
2017.01.10
----------

Bugfixes:
 + #544: Im der Sitzungsansicht "Offene Aufgaben" sind Aufgaben jetzt nach Erstellungsdatum sortiert.
 + #537: In der Differenzanzeige wird der Titel der Studie jetzt angezeigt.
 + #543: Nicht bestätigte substanzielle Amendments in der "Weitere TOPs" Ansicht erzeugen jetzt wie erwartet eine neue Aufgabe Amendment Formale Prüfung für die Office-Gruppe.

2017.01.05
----------

Bugfixes:
  + #545: Der Download des Sitzungs Zip Archives funktioniert jetzt wieder
    Bitte schreiben Sie den Mitgliedern, die damit Probleme hatten,
    den Link nochmals zu klicken und das ZIP Files herunterzuladen.

2017.01.04
----------

Bugfixes:
  + #534: Der 404 Fehler bei Zugriff auf Dokumente in der Differenz
    Ansicht wurde behoben.

2017.01.03
----------

Bugfixes:
  + #532: Das Zeitfenster PDF zeigt wieder die richtigen Zeitfenster an.
  + #531: Ein Amendment einer Studie konnte nicht eingereicht werden.
    Dies ist jetzt wieder möglich.
  + #530: Laden der Amendment Ansicht wurde beschleunigt

2016.12.29
----------

Bugfixes:
  + #530 Der Fehler bei Einreichung,Review & Signing von Amendments bei
    Studien mit hoher Zahl an Nachreichungen wurde behoben. Die 
    Wiederholung der Tätigkeit sollte jetzt korrekt verarbeitet werden.

2016.12.23
----------

Bugfixes:
  + #518 und #515: Nicht ausgefüllte Felder im Reiter Maßnahmen und 
    Reiter Zentren geben den Benutzern des ECS beim Validieren / 
    Abschicken einer Einreichung Rückmeldung, was noch nicht
    korrekt ausgefüllt ist.

2016.12.22
----------

Bugfixes:
  + #524: Verlängerung der Gültigkeit des Votums stellt jetzt die gleichen
    Daten wie im PDF dar.
  + #516: Text in der Leseansicht kann jetzt wieder kopiert werden
  + #519: Verfügbarkeitsaussetzer sollten jetzt nicht mehr auftreten.
  + #527: Die fehlerhafte Codierung von ins ECS geschickte Nachrichten wurde
    ausgebessert. Dies betrifft nur neue Nachrichten.
    Es ist daher gut wenn Sie bei den Nachrichten die bis jetzt fehlerhaft
    dargestellt wurden bitten  nochmals auf eine der Nachrichten per Email
    zu antworten.

2016.12.20
----------

Bugfixes:
  + #504 Meldungsanworten haben wieder Textbausteine
  + #171 PDF-Viewer: Es werden wieder EK-Nr, Dokument-Typ, Dokument-Name
    und Version im Titel angezeigt
  + #492 PDF-Viewer: Das Handwerkzeug ist wieder aktiv
  + Breadcrumbs (besuchte Studien) und die Version werden wieder rechts
    unterhalb des Suchfeldes angezeigt

2016.12.18
----------

Beta Release auf https://ekmeduniwien.at
