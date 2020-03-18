# LGTranslator
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
This function returns the alias string associated with the string in the parameter original. If the original string is not in the list, the function returns an empty string.

## void editTranslation(String original, String alias)
With this function an entry in the list can be modified. The alias string for the entry with the original string given by the parameter original will be replaced with the string from parameter alias. If the original string is not in the list, the function does nothing.

## void editTranslation(int16_t index, String alias)
This function sets the alias string of the list entry with the given index. The alias string gets the value from parameter alias. 

## int16_t findOriginal(String original)
This function returns the index of the list entry with the original string given in the parameter original. If no such entry exists, teh function returns -1.

## void deleteTranslation(String original)
This function removes the entry with the original string given by the parameter original. All entries after the deleted entry will be moved so that no gap remains. If the no entry matches the parameter original, nothing will be changed.

## void deleteTranslation(uint16_t index)
This function removes the entry with the index given by the parameter index. All entries after the deleted entry will be moved so that no gap remains. If the parameter index is outside the number of list entries, nothing will be changed.

## String getOriginal(uint16_t index)
This function returns the original string of the entry at the given index. If the parameter index is outside the number of list entries, an empty string will be returned.

## String getAlias(uint16_t index)
This function returns the alias string of the entry at the given index. If the parameter index is outside the number of list entries, an empty string will be returned.

## String getBoth(uint16_t index)
This function returns the original string and the alias string of the entry at the given index. Both strings will be separated by an equal sign. If the parameter index is outside the number of list entries, an empty string will be returned.

## uint16_t getCount()
This function returns the number of entries in the list.
