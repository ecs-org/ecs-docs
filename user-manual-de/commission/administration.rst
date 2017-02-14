==========
Verwaltung
==========

Benutzerverwaltung
==================

In der Benutzerverwaltung scheinen alle Personen auf, die im ECS-System aktiv sind (sowohl bestätigte als auch nicht-bestätigte). Hier können Benutzer bestätigt, deren Daten bearbeitet und bestimmte Personen (z.B. Gutachter) eingeladen werden.

Abwesenheit / Anwesenheit markieren
+++++++++++++++++++++++++++++++++++

Damit der interne Arbeitsprozess der Ethikkommission weiterlaufen kann, hat die Bürogruppe die Möglichkeit, einen temporär ausfallenden internen Benutzer als abwesend zu markieren und einen zeitweiligen Ersatz für die erhaltenen Nachrichten auszuwählen.

Die abwesende Person wird zunächst in der Benutzerverwaltung mit einem Klick auf den entsprechenden Link als "verhindert" angezeigt und dann durch eine Vertretungsperson ersetzt. Diese Person erhält alle Nachrichten, die im Abwesenheitszeitraum an die abwesende Person geschickt werden. Die angenommenen Aufgaben der abwesenden Person werden für die jeweilige Gruppe in der *Aufgaben*-Box unter der Überschrift *Vertretungsaufgaben* angezeigt. 

Wenn eine Person als "abwesend" markiert wurde, wechselt in der Benutzerverwaltung der Link *Als Verhindert markieren* zu *Als Anwesend markieren*. Damit Sie die Anzeige zur Abwesenheit aufheben können, klicken Sie auf den Link *Als Anwesend markieren*. Wenn Sie die Änderung speichern, wird der betreffende Benutzer wieder als "anwesend" angezeigt. 

Benutzer einladen
+++++++++++++++++

Sie haben die Möglichkeit, einen neuen Benutzer (z.B. einen externen Gutachter) einzuladen. Jede Gruppe wird für bestimmte Aufgaben freigeschalten.

Wählen Sie unter *Gruppen* jene Gruppe aus, in der die betreffende Person eine Funktion erfüllt (z.B. Executive, Überprüfer des Gutachtens, externer Gutachter, Versicherungsprüfer, usw.). Bsp.: Bei der Einladung eines Sitzungsmitgliedes muss unter *Gruppe* "Sitzungsmitglied" ausgewählt werden. Zusätzlich wird eine medizinische Kategorie benötigt. Es kann auch ein Fachgebiet für ein Expedited Review ausgewählt werden.

Alle Personen, die in der *Bürogruppe* tätig sind, müssen als *Intern* markiert werden. Dies ist nötig, damit jedes Mitglied der Bürogruppe in alle Studien einsehen kann. 

Gebührenabrechnung
==================

In der Gebührenabrechnung wird die Abrechnung von unverrechneten Einreichungen erstellt. Benutzen Sie die Filter, um eine Auswahl der studienbezogenen Rechungen zu treffen. Laden Sie dann die Auflistung als xls-Datei herunter und schicken Sie diese weiter an die Finanzabteilung.

Gutachter-Bezahlung
===================

In der Gutachter-Bezahlung wird die Abrechnung von unverrechneten Gutachten erstellt. Die Filter ermöglichen dabei eine Auswahl der zu bezahlenden Gutachter. Wenn Sie die Abrechnung erstellt haben, können Sie sie als xls-Datei herunterladen und weiter an die Finanzabteilung schicken. 

Statistik
=========

In der Statistik sehen Sie die Summe aller Einreichungen sowie eine Aufschlüsselung nach bestimmten Kriterien: Die Anzahl der kommerziell gesponserten Studien, der multizentrischen Studien, der Studien nach dem AMG und jene nach dem MPG, die Studien mit einem B1, einem B2 oder einem B3 als Votum, sowie die Anzahl der abgelehnten bzw. zurückgezogenen Studien. Die Studien nach dem AMG und dem MPG sind zusätzlich nach ihrer Einreichungsart aufgeschlüsselt.

Textbausteine
=============

Textbausteine ermöglichen Ihnen, längere Texte, die Sie oft verwenden, unter einem Kürzel abzuspeichern. 

Unter dem Menüunterpunkt *Textbausteine* in der Verwaltung können Sie Textbausteine erstellen und bereits bestehende TBS bearbeiten und löschen. Zum Erstellen eines TBS klicken Sie auf *Neu*, wählen Sie ein Kürzel und füllen Sie dann den dazugehörigen Text in das darunterliegende Feld ein. Sobald Sie auf *Speichern* klicken, scheint der TBS in der von Ihnen erstellten Liste von TBS auf. 

Um direkt im Eingabefeld einen Text einzufügen, geben Sie das dazugehörige Kürzel (oder einen Teil des Kürzels) ein, markieren Sie es und drücken dann die Tastenkombination Alt+M. Der beliebige Text erscheint automatisch im dazugehörigen Eingabefeld.

Das Einfügen von Textbausteinen ist überall dort möglich, wo Sie das blaue Paragraphen-Symbol sehen. So z.B. im Notizblock oder in der Leseansicht einer Studie. Klicken Sie dafür auf das Symbol. Es wird die von Ihnen erstellte Liste von TBS angezeigt. Wählen Sie den betreffenden TBS mit einem Klick aus. Der Inhalt des TBS wird an der entsprechenden Stelle eingefügt. 

PKI
===

Interne Benutzer brauchen aus Sicherheitsgründen ein Client Zertifikat, um sich in das System einloggen zu können. (Zuvor muss ein Benutzerkonto erstellt worden sein.) Erstellen Sie das Client Zertifikat, indem Sie unter *User* den neuen Benutzer auswählen und geben Sie dann unter *Cn* eine Bezeichnung für das Client Zertifikat ein (z. B.: Büro_Laptop, Privater_Laptop_Mustermann, Sitzungstablet_3, o. ä.) Sobald das Zertifikat erstellt ist, wird es per Email an die betreffende Person gesendet. Übermitteln Sie nun das Passwort für die Entschlüsselung des Zertifikats. Es scheint nach der Erstellung des Zertifikats bei Ihnen auf. Wählen Sie für die Übermittlung des Codes einen sicheren Kanal (z. B. Telefon. Nicht Email!). Nun wird das Passwort eingegeben und das Client Zertifikat auf dem betreffenden Computer importiert. (Sehen Sie unten die einzelnen Schritte des Importierens im Firefox und Chrome.) Sobald das Client Zertifikat importiert ist, muss der Browser neu gestartet werden. Der neue Benutzer kann sich nun in das System einloggen. 

Importvorgang bei Firefox: *Preferences* -> *Advanced* -> *Certificates* -> *View Certificates* -> *Your Certificates* -> *Import...* -> Datei auswählen -> Passwort eingeben

Importvorgang bei Chrome: *Settings* -> *Show Advanced Settings...* -> *HTTPS/SSL* -> *Manage Certificates* -> *Your Certificates* -> *Import...* -> Datei auswählen -> Passwort eingeben

Tags
====

Tags dienen dazu, Studien mit Schlagwörtern zu markieren. Alle Tags sind für alle internen Benutzer sichtbar und benutzbar.

Das Erstellen eines Tags erfolgt in der Verwaltung unter *Tags*. Klicken Sie dort auf *Neues Tag*. Benennen Sie das Tag und wählen Sie eine Farbe. Sobald das Tag gespeichert wurde, erscheint es in einer Liste aller Tags.  

Taggen Sie eine Studie auf dem *Status*-Tab der betreffenden Studie. Klicken Sie dafür auf den *Bearbeiten*-Link in der Zeile *Tags*, wählen Sie ein Tag aus der Liste aus und klicken Sie dann auf *Speichern*. Das Tag scheint nun unter *Tags* auf. Wenn Sie ein Tag entfernen möchten, klicken Sie im *Status*-Tab auf den *Bearbeiten*-Link, klicken Sie das Tag weg und speichern Sie Ihre Einstellungen. 

Sobald eine Studie ein Tag hat, erscheint sie überall mit diesem Tag. Suchen Sie nach bestimmten Studien mittels Tags in der *Suche* oder in der Liste aller Studien (*Studien* -> *Alle Studien*).  
