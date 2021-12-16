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

  recieveJunk(2000);
  String dataRecieved=recieveData(2000);

  sendData(2,"Hi from ESP8266 =)",2000);

  delay(100);

   if(connectToWifiNetwork(String(ssid), String(password))){

       concentracionesSensores cs = {280.3, 78.36, 74.74, 85.4, 41.85, 20.8, 96.63, "Dec-9-2021h10:02:18" };
       WiFiClient client;
       sendSensorData(String(servername), String(endPoint), 80, cs, client);

    }


  ESP.deepSleep(0);




}

void loop() {



}
