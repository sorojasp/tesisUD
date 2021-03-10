


#include "measureTimeFunc.h"
#define led 9
#define pulsador 4
#include "TimerOne.h"
#include <EEPROM.h>

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// constants won't change:
boolean ledS = false;           // interval at which to blink (milliseconds)
int valueEEPROM_; 
int counterHigh;
int counterLow;

void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT);
  pinMode(pulsador, INPUT);

 
  Serial.begin(9600);
  setAndStartInterruptTime(2);
}

void loop() {
 
 valueEEPROM_ = EEPROM.read(0);

 if(valueEEPROM_==0){
  counterHigh=0;
  counterLow++;
  
  Serial.println("Low-"+String(counterLow));
  }else{
     counterLow=0;
     counterHigh++;
     Serial.println("High-"+String(counterHigh));
    }


      
   

    if(digitalRead(pulsador)==LOW){
      endInterruptTime();
    }
       
      
      }


    //

 






 void blink_led(){

     ledState= !ledState;
  
    digitalWrite(led, ledState);
 
}
    
