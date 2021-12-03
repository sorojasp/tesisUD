#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 
  const byte pin0 = 0;
  const byte pin2 = 2;
void setup() {
  // put your setup code here, to run once:

  pinMode(pin0, OUTPUT);
  pinMode(pin2, OUTPUT);
  Serial.begin(9600);


  for (int i = 0; i <= 10; i++) {

    digitalWrite(pin0, HIGH);
    delay(20);
    
    digitalWrite(pin0, LOW);
    delay(100);

    }

    Serial.println("hi from esp8266-01");
    Serial.flush();

  
  
  ESP.deepSleep(0);



}

void loop() {




}
