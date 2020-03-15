#ifndef LGTranslator_h
#define LGTranslator_h

#include <Arduino.h>

#define LG_MAXENTRIES 100

typedef
struct {
  String original;
  String alias;
} LG_ENTRY;

class LGTranslator {
public:
    LGTranslator();
    void addEntry(String original);
    void addEntry(String original, String alias);
    bool saveList(String filename);
    bool loadList(String filename);
    String getTranslation(String original);
    void editTranslation(String original, String alias);
    void editTranslation(int16_t index, String alias);
    int16_t findOriginal(String original);
    void deleteTranslation(String original);
    void deleteTranslation(uint16_t index);
    String getOriginal(uint16_t index);
    String getAlias(uint16_t index);
    String getBoth(uint16_t index);
    uint16_t getCount();
  private:
    uint16_t _count = 0;
    LG_ENTRY _list[LG_MAXENTRIES];
};
#endif'
