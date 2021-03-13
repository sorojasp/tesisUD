
#include "functions.h"
#define input 4
#define led 5
#define rstESP8266 8


String incomingString;


      void resetESP826601(){

          digitalWrite(rstESP8266, HIGH);
          delay(20);
          digitalWrite(rstESP8266, LOW);
          delay(100);
      }




void setup() {

  pinMode(rstESP8266, OUTPUT);
  pinMode(input,INPUT);
  pinMode(led,OUTPUT);

  Serial.begin(9600);
  
  resetESP826601();
  
 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
     //String dataSensor= "NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388"+String("&d=")+String(getDateTime());
     String dataSensor= "&NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388";

     if(digitalRead(input)==LOW){

      
       Serial.println(dataSensor);
       Serial.flush();
       digitalWrite(led,LOW);


      }else{
        digitalWrite(led,HIGH);
 
        }




  

}
