#include "find_R0.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  delay(100);

  int sensorValue = analogRead(A0);

 
      Serial.println(String(sensorValue));
   

}
