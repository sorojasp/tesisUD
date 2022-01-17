//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
//#include <string.h>
//#include <ArduinoJson.h>
#include "functions.h"
#include "serialCommunication.h"
#include "wifiLibrary.h"

int GPIO2=2;
int GPIO0=0;
char ssid[] = "Ingnovatech";          //  your network SSID (name)
char password[] = "recyapp2021";
char servername[]="taskcontrollersr7.herokuapp.com";
char endPoint[]="/task/";



void setup() {
  //pinMode(GPIO2, OUTPUT);
  //pinMode(GPIO0, INPUT);

  Serial.begin(9600);

  delay(100);

  Serial.print("junk@");
  Serial.flush();


     if(connectToWifiNetwork(String(ssid), String(password))){
               WiFiClient client;
               sendSensorData(String(servername), String(endPoint), 80, "&A=200.38&B=10000.38&C=100000.99", client);
               }

               

               
    

  


  /*

  if(data!="false@"){

      delay(100);///////////*  Is very important  *
      Serial.print(data+"@");
      Serial.flush();

      String confirm= waitForData(10000);

      if(confirm=="finish"){

        if(connectToWifiNetwork(String(ssid), String(password))){
               WiFiClient client;
               sendSensorData(String(servername), String(endPoint), 80, data, client);
               }

               Serial.print("data sended@");
              Serial.flush();


        }else{}


    }else{}

**/









ESP.deepSleep(0);





}

void loop() {



}
