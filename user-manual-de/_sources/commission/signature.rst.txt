======================
Elektronische Signatur
======================

Voraussetzungen
================

+ ein von ECS unterstützter **aktueller Webbrowser** (Firefox,Chrome,Safari,Edge)

+ **Java** Version 8/9, zur Installation siehe die `Download-Seite von java.com <https://java.com/de/download/>`_

+ ein Kartenlesegerät zum Anschluss über USB an den Computer
    + Gelistet unter buergerkarte.at: `Cryptoshop - Gemalto IDBridge CT30 ecard <http://www.cryptoshop.com/gemalto-idbridge-ct30-ecard.html>`_
    + Liste von anderen `SmartCard Reader im Preisportal Geizhals <https://geizhals.at/?cat=sm_r&xf=2925_USB-A+2.0%7E2957_SmartCard&sort=p#productlist>`_

+ eine als **Bürgerkarte aktivierte E-Card** oder eine andere von **A-Trust ausgestellte Signaturkarte**
    + Um Ihre E-Card zu aktivieren gehen Sie zur `"Bürgerkarte aktivieren" Seite von buergerkarte.at <https://www.buergerkarte.at/aktivieren-karte.html>`_.
    + Wir empfehlen die *"Persönliche Aktivierung in einer der zahlreichen Registrierungsstellen in ganz Österreich"* 
    + Voraussetzung: Amtlichen Lichtbildausweis und e-card mitbringen
    + Vorteil: Die Aktivierung wird von ausgebildeten Mitarbeitern durchgeführt und Ihre Bürgerkarte ist sofort einsatzbereit.
    + `Liste der akzeptierten Lichtbildausweise <https://www.buergerkarte.at/ausweisliste.html>`_
    + `Liste der Registrierungsstellen <https://www.buergerkarte.at/registrierungsstellen.html>`_

+ Die Signatursoftware Mocca installiert als **lokale Bürgerkartenumgebung**


.. Warning:: Die zusätzlich im ECS vorhandene "Online BKU" Version von Mocca ist veraltet und wird ab 5. September 2018 nicht mehr funktionieren. Wechseln Sie zeitnahe auf die "lokale BKU".
    
Einrichtung der Signatursoftware Mocca
======================================

Verwenden Sie für diese Schritte den Webbrowser welchen sie später für das ECS zum signieren einsetzen wollen. Falls sie einen weiteren Browser zur Signierung verwenden wollen, wiederholen sie die Punkte 2 und 3 um den Browser für Mocca zu konfigurieren und zu testen.

1. `Installation der lokalen Bürgerkartenumgebungs-Software Mocca <https://webstart.buergerkarte.at/mocca/webstart/mocca.jnlp>`_

2. Mit gestarteter Mocca Software (im ausgewählten Webbrowser):

  + `Bestätigen des lokalen https Zertifikats von Mocca <http://localhost:3495/ca.crt>`_
  + `Detailinformation zur Zertifikatinstallation <http://localhost:3495/help/help.install.cacert.html>`_

3. `Testen der elektronischen Signatur mit lokaler BKU <https://www.buergerkarte.at/test-suite-karte.html>`_


Im ECS signieren
================

Benutzer der Gruppe "Signing" haben die Tätigkeiten "Votum Signierung" und Amendment-Antwort Signierung" zu Verfügung. Um signieren zu können, muss die "lokale BKU (Bürgerkartenumgebung)" Software auf den verwendeten Computer gestartet sein.

Die Signierungsseite beinhaltet jeweils eine Vorschau der zu signierten Daten, einen Navigationsblock und ein Signierungsfenster.

Navigationsblock:

+ Mit "Zurückwerfen" wird das Votum/die Amendment-Antwort wieder in den Bearbeitungsarbeitsablauf zum letzten Arbeitsschritt vor der Signierung zurück geschickt.

+ Mit "Überspringen" wird das Votum/die Amendment-Antwort jetzt nicht signiert, und das ECS schlägt das nächste zu signierende Dokument vor.

+ Mit "Abbrechen" wird die aktuelle Signierungstätigkeit abgebrochen und in das Hauptmenü gewechselt

Signierungsfenster:

+ Um das dargestellte Votum/die Amendment-Antwort zu signieren, geben Sie den PIN-Code ein sobald das Signierungsfenster dazu hinweist. Nicht erfolgreich signierte Voten/Amendment-Antworten bleiben weiterhin als unsignierte Tätigkeiten im System.


Bürgerkartenumgebung wechseln
-----------------------------

Um die im ECS verwendete Bürgerkartenumgebung zu ändern gehen  Sie auf ihr Profil (Klick auf das Personen Icon rechts oben und dann auf ihren Namen) und dort auf "Profil Bearbeiten".

Als vorletzten Eintrag finden Sie den Punkt "Signatur Umgebung".

+ wählen Sie "lokale BKU" für Mocca als lokale BKU aus. 

    
+ wählen Sie "online BKU(veraltet)" für Mocca als online BKU aus.

    **Achtung:** Diese Art der Signaturumgebung ist veraltet und wird nur noch bis zum 5. September 2018 funktionieren, und kann nur mit Firefox 52-ESR und aktivierten Java-Plugin verwendet werden. 

+ wählen Sie "Handy Signatur" um statt der Signaturkarte die Handysignatur zu verwenden.

    **Information:** Leider weigert sich der Betreiber A-Trust die Stammzertifikate für Zertifikate von Letsencrypt zu akzeptieren.
    Es ist daher momentan nicht möglich die Handysignatur mit den ECS und einen Letsencrypt Zertifikat zu verwenden.
    
Mit Klick auf "Speichern", speichern Sie Ihre Einstellung.

