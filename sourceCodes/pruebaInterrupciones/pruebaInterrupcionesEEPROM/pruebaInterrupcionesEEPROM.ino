
#include "TimerOne.h"
#define led 9
#define pulsador 4


// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// constants won't change:
boolean ledS = false;           // interval at which to blink (milliseconds)

void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT);
  pinMode(pulsador, INPUT);

  activateInterruption();
}

void loop() {

  if(digitalRead(pulsador)==LOW){

 
    Timer1.detachInterrupt();
    Serial.println("=(");
    
    }
 
}


void activateInterruption(){
  float seconds=0.2;
  Timer1.initialize(1000000*seconds);
  Timer1.attachInterrupt(blink_led);
  }


 void blink_led(){

     ledState= !ledState;
  
    digitalWrite(led, ledState);
 
}
  
