S#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h> 
#include "wifiLibrary.h"
  String incomingString;

  char ssid[] = "name_wifi_network";          //  your network SSID (name)
  char password[] = "key_wifi_network";
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

      boolean startRecieveData=false;
      boolean endRecieveData=false;


void setup(){
  
  pinMode(GPIO2, OUTPUT);    // 
  pinMode(GPIO0, OUTPUT);
  
  Serial.begin(9600);

  Data d;

  d.action="";
  d.state="";

  digitalWrite(GPIO2,HIGH);
  digitalWrite(GPIO0,HIGH);
  
  while(!(d.action.equals("sendData") && d.state.equals("start"))){
      digitalWrite(GPIO2,LOW);
     digitalWrite(GPIO0,HIGH);
  
  if(Serial.available()){
     incomingString = Serial.readStringUntil('\r\n');
     serial_flush_buffer();
     d=readIncomingMsg(incomingString);

        if(d.action.equals("sendData") && d.state.equals("busy")){
          delay(100);
      value=String(d.value) + String(value);
      Serial.println("recieveData-busy-"+String(d.value)+"-");
      
      }
    }
         
        
               
    }

          Serial.println(String("recieveData")+"-"+String("start")+"-"+String(d.value)+"-");
          Serial.flush();

          // FALTA IMPLEMENTAR ALGO QUE CUANDO SEA SUCCESS, ENVÍE LO QUE TIENE EN d.value

   

 
    digitalWrite(GPIO2,HIGH);
    digitalWrite(GPIO0,LOW);

    Serial.println("recieveData-end-success");


       
      

       d.action="";
       d.state="";
       d.value="";



   
     ESP.deepSleep(0);
}

void loop() {

  /*
   * 
   * delay(100);
  
    if(connectToWifiNetwork(String(ssid), String(password))){
    
       concentracionesSensores cs = {280.3, 78.36, 74.74, 85.4, 41.85, 20.8, 96.63 };
       WiFiClient client;
       sendSensorData(String(servername), String(endPoint), 80, cs, client);
      
    }else{
      
      };
  */

  }



  





  
  Data readIncomingMsg(String incomingString){
    String action;
    String value;
    String state;

    Data d = {"","",""};
    
    

    int n = incomingString.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, incomingString.c_str());
       char *token = strtok(char_array, "-"); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            action=String(token);
            }else if(i==1){
              state=String(token); 
              }else if(i==2){
                value=String(token); 
                
              }
               token = strtok(NULL, "-"); 
              i++;
         
    }

    d.action=action;
    d.value=value;
    d.state=state;
    
    return d;
    
    }

      void serial_flush_buffer()
{
  while (Serial.read() >= 0)
   ; // do nothing
}





  
