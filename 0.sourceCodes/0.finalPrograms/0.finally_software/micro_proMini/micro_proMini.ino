#include "functions.h"
#include "serialCommunication.h"
#include<TimerOne.h>

  /* 
   *  Set of pin control of ESP8266-01
  */
  const byte GPIO2 = 2;
  const byte GPIO0 = 3;
  const byte RST = 4;
  
  /* 
   *  Setting of time to store data in EEPROM and time to send data to server
  */
  unsigned int time_store_concentrations_EEPROM = 60000000;//time to get sample and  store gas concentration data in EEPROM in microseconds-- 60 seconds
  unsigned int time_send_concentrations_server=900000000;// time to send gas concentration data to server in microseconds ---15 min
  unsigned int samples=floor(time_send_concentrations_server/time_store_concentrations_EEPROM);// amount of samples to get average and send to server

  /*
   * flags to handle when the gas concentration data have to store in EEPROM and when the average of gas concentration data have to send 
   * to server
  */

  volatile boolean store_in_EEPROM= true;
  volatile boolean send_to_server=false;


  volatile unsigned int sample_counter=0;

 
  


void setup() {
  // put your setup code here, to run once:

    pinMode(GPIO0,OUTPUT);
    pinMode(GPIO2,OUTPUT);
    pinMode(RST,OUTPUT);  
    
    Serial.begin(9600);

       Timer1.initialize(time_store_concentrations_EEPROM);
       Timer1.attachInterrupt(storeDataInEEPROM);

}

void loop() {
  // put your main code here, to run repeatedly:

  
      /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       *
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25@
       * &SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18@
       *
       * A=200.38&B=10000.38&D=100000.99&E=100.25@
       * F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18@
       */

  if(store_in_EEPROM==true){

    store_in_EEPROM=false;
    }

  if(send_to_server==true){
    delay_millis(10);
    resetESP8266(RST, GPIO0, GPIO2);
    delay_millis(250);// this value con not be less than 200
    boolean resultSendJunk=sendJunk(2000);

    if(resultSendJunk==true){

      boolean retultRecieveJunk=recieveJunk(3000);

      if(retultRecieveJunk==true){
        
        boolean resultSendData= sendData(1,"&A=200.38&B=10000.38&D=100000.99&E=100.25@", 100);
        if(resultSendData==true){
          
          resultSendData= sendData(1,"&F=236.88&G=20.38&H=20.388&I="+String(getDateTime())+"@", 100);
          if(resultSendData==false){}
          }else{}
        }else{}
      }else{}

    send_to_server=false;    
    }

}



void storeDataInEEPROM(){

  if (sample_counter<samples){
    store_in_EEPROM=true;
    sample_counter++;
    
    }else{


      sample_counter=0;
      send_to_server=true;
      
      }
      }
