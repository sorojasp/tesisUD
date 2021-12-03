#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 


const byte ledPin = 0;
const byte interruptPin = 2;
volatile boolean interrupt_occurred = false;
unsigned long previousTime=0;
const unsigned long eventInterval=1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR, FALLING);
}

void loop() {


  
}

void ISR() {

  unsigned long currentTime=millis();

  for (int i = 0; i <= 255; i++) {

    if(currentTime - previousTime>= eventInterval){
      digitalWrite(ledPin,LOW);
      }


          if(currentTime - previousTime>= eventInterval){
      digitalWrite(ledPin,HIGH);
      }
  

  
    
   
   
    
    }


  

}
