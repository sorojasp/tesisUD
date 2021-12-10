//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
//#include <string.h>
//#include <ArduinoJson.h>
#include "functions.h"

int GPIO2=2;
int GPIO0=0;
const char* msg;

void setup() {
  //pinMode(GPIO2, OUTPUT);
  //pinMode(GPIO0, INPUT); 

  Serial.begin(9600);

  //recieveJunk();
  //String dataRecieved=recieveData();
  //ESP.deepSleep(0);
     

     

}

void loop() {

    

  recieveJunk();
  String dataRecieved=recieveData();
     

  

}
