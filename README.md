# LGTranslator
An Arduino library to handle a list of relations. The list canbe saved to SPIFFS
9.3 	LGTranslator
This Library defines a class which manages a reference table. The table allows 100 entries as a maximum. Every entry has an original string and an associated alias string. The library can be used to retrieve the alias string for a given original string. The compete table can be saved to the SPIFFS and also read from there. The class has the following public member functions.

## LGTranslator()
class constructor. It has no oparameters

## void addEntry(String original)
This function adds a new entry to the list, except the maximum number of allowed entries has been reached. The original string of the entry is set to the parameter original. The alias string of the entry will be filled with an empty string.

## void addEntry(String original, String alias)
This function adds a new entry to the list, except the maximum number of allowed entries has been reached. The original string of the entry is set to the parameter original. The alias string of the entry is set to the parameter alias.

## bool saveList(String filename)
This function saves the complete list to the SPIFFS using the parameter filename as the filename. It returns false if an error occured.

## bool loadList(String filename)
If the file with the name from parameter filename cant be read, the function returns false. Otherwise the complete list will be read from SPIFFS. Existing entries will be overwritten.

## String getTranslation(String original)
Diese Funktion liefert den Text, der dem im Parameter original angegebenen Wort zugewiesen wurde. Sollte das angegebene Wort nicht in der Liste sein oder noch kein zugewiesenes Wort besitzen, wird ein Leerstring zurückgegeben.

## void editTranslation(String original, String alias)
Diese Funktion dient zum Ändern einer Zuweisung. Es wird der Eintrag gesucht, der durch den Parameter original bezeichnet wird und dann wird die Zuweisung durch den Inhalt des Parameters alias ersetzt.

## void editTranslation(int16_t index, String alias)
Auch diese Funktion dient zum Ändern der Zuweisung. In diesem Fall wird mit dem Parameter index direkt die Position des Eintrags in der Liste angegeben. Achtung, die Nummerierung beginnt mit 0! Der neue Wert für die Zuweisung wird im Para-meter alias angegeben.

## int16_t findOriginal(String original)
Diese Funktion sucht den Listeneintrag, der durch den Parameter original be-zeichnet wird. Die gefundene Position wird zurückgegeben. Wurde kein entspre-chender Eintrag gefunden, ist der Rückgabewert -1.

## void deleteTranslation(String original)
Diese Funktion dient zum Löschen eines Listeneintrags. Es wird der Eintrag gesucht, der durch den Parameter original bezeichnet wird und dann wird der Eintrag gelöscht. Alle nachfolgenden Einträge werden verschoben , sodass keine Lücke bleibt.

## void deleteTranslation(uint16_t index)
Auch diese Funktion dient zum Löschen eines Listeneintrags. In diesem Fall wird mit dem Parameter index direkt die Position des Eintrags in der Liste angegeben. Achtung, die Nummerierung beginnt mit 0! Der Eintrag an der angegebenen Positi-on wird gelöscht.

## String getOriginal(uint16_t index)
Diese Funktion liefert das Original-Wort an der durch den Parameter index ange-gebenen Position in der Liste.
String getAlias(uint16_t index)
Diese Funktion liefert das zugewiesene Wort an der durch den Parameter index angegebenen Position in der Liste.

## String getBoth(uint16_t index)
Diese Funktion liefert sowohl das Original-Wort als auch das zugewiesen Wort an der durch den Parameter index angegebenen Position in der Liste. Beide Worte werden durch ein Gleichheitszeichen getrennt.

## uint16_t getCount()
Diese Funktion liefert die Anzahl der vorhandenen Listeneinträge.

