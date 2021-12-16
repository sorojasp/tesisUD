//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
//#include <string.h>
//#include <ArduinoJson.h>
#include "functions.h"
#include "serialCommunication.h"

int GPIO2=2;
int GPIO0=0;
const char* msg;

void setup() {
  //pinMode(GPIO2, OUTPUT);
  //pinMode(GPIO0, INPUT);

  Serial.begin(9600);

  recieveJunk(2000);
  String dataRecieved=recieveData(2000);

  sendData(2,"Hi from ESP8266 =)",2000);


  ESP.deepSleep(0);




}

void loop() {



}
