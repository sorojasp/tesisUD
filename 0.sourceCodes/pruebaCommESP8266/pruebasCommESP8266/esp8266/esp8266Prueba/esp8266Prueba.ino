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
  pinMode(GPIO0,OUTPUT);
  Serial.begin(250000);

  serial_flush_buffer();
}

void loop() {
  // put your main code here, to run repeatedly:

  
 
  while(true){
   while(Serial.available()==0){}


    digitalWrite(GPIO2,HIGH);
    digitalWrite(GPIO0,HIGH);


    incomingString = Serial.readString();
    serial_flush_buffer();

    Serial.print(incomingString);
    Serial.flush();

    

while(Serial.available()==0){}


digitalWrite(GPIO2,LOW);

 incomingString =Serial.readString();
   serial_flush_buffer();

      if(incomingString=="t"){
          //digitalWrite(GPIO0,HIGH);
          }else{
     //digitalWrite(GPIO0,LOW);
     
     }


     Serial.print("finish");
    Serial.flush();

    
     digitalWrite(GPIO0,LOW);


 
//}

  
 //digitalWrite(GPIO0,LOW);

     

     

}


 
   
    
        
   
    

}


         
