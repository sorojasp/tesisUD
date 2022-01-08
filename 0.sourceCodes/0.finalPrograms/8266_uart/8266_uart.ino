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

  Serial.print("junk@");
  Serial.flush();

  
  
  unsigned long time_wait = 10000;
  String sensor_data1= recieveData(time_wait);

  if(sensor_data1!="false@"){

    delay(100);
    String sensor_data2= recieveData(time_wait);

    if(sensor_data2!=false){

      if(connectToWifiNetwork(String(ssid), String(password))){
               WiFiClient client;
               sendSensorData(String(servername), String(endPoint), 80, sensor_data1+sensor_data2, client);
               }

               delay(100);

               sendData(2, "data sended to server =)",time_wait);
             
      
      
      }else{}


    
        
    
    }else{}


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
