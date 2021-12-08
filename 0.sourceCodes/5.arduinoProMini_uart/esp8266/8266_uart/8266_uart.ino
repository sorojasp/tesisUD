#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h>
#include <ArduinoJson.h>


int GPIO2=2;
int GPIO0=0;
const char* msg;

void setup() {
  //pinMode(GPIO2, OUTPUT);
  //pinMode(GPIO0, INPUT); 

  Serial.begin(9600);

   delay(800);

       for (int i = 0; i <= 25; i++) {

 

        delay(100);
        Serial.write("Hi Irene Adler - nano@");
        Serial.flush();
        delay(400);
        }


          ESP.deepSleep(0);
     

     

}

void loop() {

  
  //if(digitalRead(GPIO0)==LOW){
    delay(800);

     Serial.write("Hi Irene Adler - nano@");
     Serial.flush();
    
    
    //}
  

}
