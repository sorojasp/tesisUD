#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h>
#include <ArduinoJson.h>
#include "wifiLibrary.h"
  String incomingString;

  char ssid[] = "Ingnovatech";          //  your network SSID (name)
  char password[] = "recyapp2021";
  char servername[]="taskcontrollersr7.herokuapp.com";
  char endPoint[]="/task/";


    struct Data{

      String action;
      String state;
      String value;

      };

      String value;
      int GPIO2=2;
      int GPIO0=0;
      
void setup() {
  // put your setup code here, to run once:
  // put your main code here, to run repeatedly:

  pinMode(GPIO2, OUTPUT);
  pinMode(GPIO0, INPUT); 



  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(GPIO0)==HIGH){

    //tutorial del Json en arduino https://randomnerdtutorials.com/decoding-and-encoding-json-with-arduino-or-esp8266/
  StaticJsonBuffer<200> jsonBuffer;
  char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  JsonObject& root = jsonBuffer.parseObject(json);

   delay(100);

    if(connectToWifiNetwork(String(ssid), String(password))){

       concentracionesSensores cs = {280.3, 78.36, 74.74, 85.4, 41.85, 20.8, 96.63 };
       WiFiClient client;
       sendSensorData(String(servername), String(endPoint), 80, cs, client, root );

    }else{

      digitalWrite(GPIO2, HIGH);
      delay(4000);
      digitalWrite(GPIO2, LOW);
 


      };
    
    
    
    }


}
