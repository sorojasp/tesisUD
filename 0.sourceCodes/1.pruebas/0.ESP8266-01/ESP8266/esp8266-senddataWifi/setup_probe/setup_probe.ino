#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 

#include <ArduinoJson.h>
#include "wifiLibrary.h"


  char ssid[] = "Ingnovatech";          //  your network SSID (name)
  char password[] = "recyapp2021";
  char servername[]="taskcontrollersr7.herokuapp.com";
  char endPoint[]="/task/";



  const byte pin0 = 0;
  const byte pin2 = 2;
void setup() {
  // put your setup code here, to run once:

  pinMode(pin0, INPUT);
  pinMode(pin2, INPUT);
   Serial.begin(9600);
 


  delay(100);


    
    Serial.write("Hi Irene Adler");
    Serial.flush();

      while(Serial.available()==0){}

      String incomingString =Serial.readStringUntil('\n');
      serial_flush_buffer();


      StaticJsonBuffer<200> jsonBuffer;
  char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  JsonObject& root = jsonBuffer.parseObject(json);

   delay(100);

  if(connectToWifiNetwork(String(ssid), String(password))){
    
       concentracionesSensores cs = {280.3, 78.36, 74.74, 85.4, 41.85, 20.8, 96.63 };
       WiFiClient client;
       sendSensorData(String(servername), String(endPoint), 80, cs, client, incomingString);
      
    }else{
      
      };
    

  
  
  ESP.deepSleep(0);



}

void loop() {




}

  void serial_flush_buffer(){
           Serial.available();
              while (Serial.read() >= 0); // do nothing
              }
