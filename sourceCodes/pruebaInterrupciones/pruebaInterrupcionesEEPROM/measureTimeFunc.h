#include "TimerOne.h"
#include <EEPROM.h>

void writeEEPROM2s(){
  int valueEEPROM = EEPROM.read(0);
  if(valueEEPROM==0){
    EEPROM.update(0,255);
    }else if(valueEEPROM==255){
      EEPROM.update(0,0);
      } 
  }
  
void setAndStartInterruptTime(int seconds){
  EEPROM.update(0,0);
  Timer1.initialize(1000000*seconds);// frecuencia con la que se ejecuta la interrupción
  Timer1.attachInterrupt(writeEEPROM2s);
  }


  void endInterruptTime(){
    Timer1.detachInterrupt();
    }
