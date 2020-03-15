#include <LGTranslator.h>
#include "SPIFFS.h"

LGTranslator::LGTranslator () {
  _count = 0;
}

void LGTranslator::addEntry(String original){
  //add only if not exists and remaining space
  if (_count < LG_MAXENTRIES) {
    if (findOriginal(original) < 0){
      _list[_count].original =original;
      _list[_count].alias = "";
      _count++;
    }
  }
}
void LGTranslator::addEntry(String original, String alias){
  int16_t ix = findOriginal(original);
  if (ix < 0){
    //add only if not exists and remaining space
    if (_count < LG_MAXENTRIES) {
      _list[_count].original =original;
      _list[_count].alias = alias;
      _count++;
    }
  } else {
    _list[ix].alias = alias;
  }
}
bool LGTranslator::saveList(String filename){
  File f = SPIFFS.open(filename.c_str(),"w+");
  if (f) {
    for (uint16_t i = 0; i<_count; i++){
      f.print(getBoth(i)+'\n');
    }
    return true;
  } else {
    Serial.print("Cannot write alias list to ");
    Serial.println(filename);
    return false;
  }
}

bool LGTranslator::loadList(String filename){
  String line;
  uint8_t pos;
  int16_t index = 0;
  if (SPIFFS.exists(filename.c_str())) {
    File f = SPIFFS.open(filename.c_str(),"r");
    if (f) {
      Serial.println("Read alias list");
      uint32_t size = f.size();
      while ((index < LG_MAXENTRIES)&&(f.position() < size))  {
        line = f.readStringUntil('\n');
        Serial.println(line);
        pos = line.indexOf('=');
        _list[index].original = line.substring(0,pos);
        _list[index].alias = line.substring(pos+1);
        index++;
      }
      _count = index;
      f.close();
      return true;
    } else {
      Serial.println("Cannot read alias list");
      return false;
    }
  }else{
    Serial.println("Alias list does not exist");
    return false;
  }
}

String LGTranslator::getTranslation(String original){
  int16_t ix = findOriginal(original);
  if (ix < 0) {
    return "";
  } else {
    return _list[ix].alias;
  }
}

void LGTranslator::editTranslation(String original, String alias){
  int16_t ix = findOriginal(original);
  editTranslation(ix,alias);
}

void LGTranslator::editTranslation(int16_t index, String alias){
  if ((index >= 0) && (index < _count)) {
    _list[index].alias = alias;
  }
}
int16_t LGTranslator::findOriginal(String original){
  int16_t i = _count-1;
  while ((i >= 0) && (_list[i].original != original)) i--;
  return i;
}
void LGTranslator::deleteTranslation(String original){
  int16_t ix = findOriginal(original);
  if (ix >= 0) deleteTranslation(ix);
}

void LGTranslator::deleteTranslation(uint16_t index){
  if (index < _count) {
    while ((index+1) < _count) {
      _list[index] = _list[index+1];
      index++;
    }
    _count--;
  }
}
String LGTranslator::getOriginal(uint16_t index){
  if (index < _count) {
    return _list[index].original;
  } else {
    return "";
  }
}

String LGTranslator::getAlias(uint16_t index){
  if (index < _count) {
    return _list[index].alias;
  } else {
    return "";
  }
}

String LGTranslator::getBoth(uint16_t index){
  if (index < _count) {
    return _list[index].original+"="+_list[index].alias;
  } else {
    return "";
  }
}

uint16_t LGTranslator::getCount(){
  return _count;
}
