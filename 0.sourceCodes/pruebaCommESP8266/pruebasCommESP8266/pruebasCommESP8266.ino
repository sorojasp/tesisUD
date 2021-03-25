

#include "functions.h"
#define input 4
#define led 5
#define rstESP8266 8
# define ledCiclo 6
# define finishESP 7

int i =0;
int veces = 10;

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
  pinMode(finishESP, INPUT);
  pinMode(led,OUTPUT);
  pinMode(ledCiclo,OUTPUT);


  Serial.begin(250000);
  serial_flush_buffer();
  resetESP826601();
  
  
 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    String dataSensor= "&NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388"+String("&d=")+String(getDateTime());
   
  

     if(digitalRead(input)==LOW){

      i =0;

     

     while(i<veces){

      
        digitalWrite(ledCiclo,HIGH);
 
       Serial.print(dataSensor);
       Serial.flush();
    
       while(Serial.available()==0){}
       incomingString =Serial.readString();
       serial_flush_buffer();


       if(incomingString==dataSensor){
        
        digitalWrite(led,HIGH);
        
        String ok="true";

        
        Serial.print(ok);
        Serial.flush();
        
        
      

        }else{

          digitalWrite(led,LOW);

          
      
         String failed="false";

        
        Serial.print(failed);
        Serial.flush();
     
          
          
   
          }

        digitalWrite(ledCiclo,LOW);
        
  //while (digitalRead(finishESP)==HIGH){}
        
         while(Serial.available()==0){}
       incomingString =Serial.readString();
       serial_flush_buffer();


     i++;}
     
   
     
 

}


   

  

}
