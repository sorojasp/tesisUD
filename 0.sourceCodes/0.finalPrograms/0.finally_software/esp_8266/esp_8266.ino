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
  // put your setup code here, to run once:

    Serial.begin(9600);

    delay_millis(300);

     boolean resultSendJunk=sendJunk(5000);

       if(connectToWifiNetwork(String(ssid), String(password))){
                  WiFiClient client;
                  sendSensorData(String(servername), String(endPoint), 80, "&A=200.38&B=10000.38&D=100000.99&E=100.25", client);
                  }
                  
      

    
    if (resultSendJunk==true){

      boolean resultRecieveJunk=recieveJunk(5000);


       
      

      
       
      if(resultRecieveJunk==true){
      
      
      
             
      
      /*
          String A=recieveData(2000);
          if(A!="false@"){
            String B=recieveData(2000);
            if(B!="false@"){
                delay(100);
                if(connectToWifiNetwork(String(ssid), String(password))){
                  WiFiClient client;
                  sendSensorData(String(servername), String(endPoint), 80, A+B, client);
                  }
                  ESP.deepSleep(0);
       
              }else{}
            }else{} 

        */ 
        }else{} 
        
    }else{}
    
  ESP.deepSleep(0);
  //String dataRecieved=recieveData(2000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
