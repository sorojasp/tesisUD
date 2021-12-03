#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 

const byte ledPin = 0;
const byte interruptPin = 2;
volatile byte state = LOW;

unsigned long previousMillis = 0;
unsigned long previousMillis_blink = 0;

const long interval = 1000; 
const long interval_blink=300;  

void setup() {
  //Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {

  
}

void blink() {
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

     previousMillis = currentMillis;

     

    
           state = !state;
           digitalWrite(ledPin, state);
           //Serial.println("Interrupt Detected"); 
          
          
          
          }
      
      
  
   




  
 
}
