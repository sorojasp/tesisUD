
  #include <string.h> 
  #include "functions.h"
  #include "sendRecieveData.h";
  String incomingString;
  #define input 4
  #define rstESP8266 8
  #define resComm 9

   int counter=0;



   

  
void setup() {
  // put your setup code here, to run once:

  pinMode(input, INPUT);
  pinMode(rstESP8266, OUTPUT);
  pinMode(resComm, OUTPUT);

  
  Serial.end();
 
}

void loop() {

  
        Serial.end();
         resetESP826601();

        
        Serial.begin(9600);
        delay(100);

        //String dataSensor= "?NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388";
        String dataSensor= "?NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388"+String("&d=")+String(getDateTime());

        boolean resultcomm=false; 
      
        resultcomm= sendData(String("sendData"), String("start"), dataSensor, "recieveData",10); 
        
        if(resultcomm==true){
          digitalWrite(resComm,HIGH);
          
          }else{
            digitalWrite(resComm,LOW);
            
            }
        
            Serial.println("supera el while....");
            Serial.flush();
  
  

  }

      void resetESP826601(){

          digitalWrite(rstESP8266, HIGH);
          delay(20);
          digitalWrite(rstESP8266, LOW);
          delay(100);
      }
