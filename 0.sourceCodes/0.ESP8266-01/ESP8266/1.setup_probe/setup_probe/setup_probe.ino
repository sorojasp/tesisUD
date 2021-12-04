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
  serial_flush_buffer();


  delay(200);


    
    Serial.write("p");
    Serial.flush();

  
  
  ESP.deepSleep(0);



}

void loop() {




}

  void serial_flush_buffer(){
           Serial.available();
              while (Serial.read() >= 0); // do nothing
              }
