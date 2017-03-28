# Häufig gestellte Fragen

## Safari Browser 

### irrtümliche Bestätigung eines falschen Zertifikats

Safari merkt sich bei Aufruf einer Website mit Client Zertifikat Unterstützung ihre Auswahl und das ECS lehnt sie ab, weil sie ein ungültiges Zertifikat präsentieren.

Das ist schnell wieder geändert.

+ Gehen Sie zur Ihren MacOS Einstellungen und dort in die "Schlüsselverwaltung/Keychain. 
+ Suchen Sie in der "Alle Einträge" Suche nach den Namen des ECS Service zb. "ekmeduniwien.at" oder "ek-mui-tirol.at".
+ Ein "Identitäts Präferenz/Identity Preference" Eintrag sollte erscheinen.
+ Löschen sie diesen Eintrag.
+ Schliessen und öffnen Sie Safari.
+ Rufen die die ECS Website erneut auf, sagen sie Safari bei der nächsten Frage das er kein Client Zertifikat verwenden soll.

Falls sie damit keinen unmittelbaren Erfolg haben,
können sie auch einfach (temporär) Firefox für das ECS verwenden,
das verwendet eine eigene Keychain für Clientzertifikate.

