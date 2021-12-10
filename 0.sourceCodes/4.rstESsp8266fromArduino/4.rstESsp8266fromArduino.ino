#include "functions.h"
  
  const byte GPIO2 = 2;
  const byte GPIO0 = 3;
  const byte RST = 4;



void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);

  
  Serial.begin(9600);
  Serial1.begin(9600);


  
}

void loop() {


    delay(250);// this value con not be less than 200
    resetESP8266(RST, GPIO0, GPIO2);

    delay(250);// this value con not be less than 200
    sendJunk();
  

    boolean resultSendData= sendData(5,"A=200.38&B=10000.38&D=100000.99&E=100.25");

    if(resultSendData==true){
      Serial.write((String("Envío de datos exitoso")+"\n").c_str());
      
      }else{
        
         Serial.write((String("** Error")+"\n").c_str());
        
        }


    
   

      /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       * 
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25@
       * &SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18@
       * 
     *A=200.38&B=10000.38&D=100000.99&E=100.25@
     *F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18@
       */
     
  
 
  
  

  
    }
  
