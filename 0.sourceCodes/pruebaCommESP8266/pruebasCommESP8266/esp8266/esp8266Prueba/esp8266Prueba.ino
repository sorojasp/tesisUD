#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 
#include "wifiLibrary.h"

  
int GPIO2=2;
int GPIO0=0;



String dataSensor= "?NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388";

String incomingString;
  char ssid[] = "ATARA";          //  your network SSID (name)
  char password[] = "1032406571";
  char servername[]="taskcontrollersr7.herokuapp.com";
  char endPoint[]="/task/";

     void serial_flush_buffer(){
  while (Serial.read() >= 0); // do nothing
  
  }


void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO2,OUTPUT);
  pinMode(GPIO0,INPUT);
  Serial.begin(9600);

  serial_flush_buffer();
}

void loop() {
  // put your main code here, to run repeatedly:



   if(digitalRead(GPIO0)==LOW &&  Serial.available()!=0){    
 //if(digitalRead(GPIO0)==LOW ){ 
    digitalWrite(GPIO2,HIGH);




    incomingString =Serial.readString();
    serial_flush_buffer();
   



        if(connectToWifiNetwork(String(ssid), String(password))){
    
       concentracionesSensores cs = {280.3, 78.36, 74.74, 85.4, 41.85, 20.8, 96.63 };
       WiFiClient client;
       StaticJsonBuffer<200> jsonBuffer;
       char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}"; 
       JsonObject& root = jsonBuffer.parseObject(json);
       sendSensorData(String(servername), String(endPoint), 80, cs, client, root, String("?Authorization=")+String(Serial.available())+String("&serial=")+String(Serial.read())+String(incomingString));
      
    }else{
      
      };

    
}

 digitalWrite(GPIO2,LOW);
    /*delay(100);
    incomingString = Serial.readStringUntil('\r\n');
    serial_flush_buffer();*/

 

    
        
   
    }
         
