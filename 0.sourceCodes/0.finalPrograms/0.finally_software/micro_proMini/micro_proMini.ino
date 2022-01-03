#include "functions.h"
#include "serialCommunication.h"
#include<TimerOne.h>

  /* 
   *  Set of pin control of ESP8266-01
  */
  const byte GPIO2 = 8;
  const byte GPIO0 = 7;
  const byte RST = 9;

   /* 
   *  Set of pin to indicate when the process is ok or present errors
  */

  const byte is_ok = 5;
  const byte present_errors = 6;
  
  
  /* 
   *  Setting of time to store data in EEPROM and time to send data to server
  */
  //unsigned int time_store_concentrations_EEPROM = 60000000;//time to get sample and  store gas concentration data in EEPROM in microseconds-- 60 seconds
  //unsigned int time_send_concentrations_server=900000000;// time to send gas concentration data to server in microseconds ---15 min
  
  unsigned int time_store_concentrations_EEPROM = 30000000;//time to get sample and  store gas concentration data in EEPROM in microseconds-- 60 seconds
  unsigned int time_send_concentrations_server=60000000;// time to send gas concentration data to server in microseconds ---15 min
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

    pinMode(is_ok,OUTPUT); 
    pinMode(present_errors,OUTPUT);
    
    Serial1.begin(9600);
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
    
     boolean resultRecieveJunk=recieveJunk(3000);
    

    if(resultRecieveJunk==true){

       boolean resultSendJunk=sendJunk(2000);

     

      if(resultSendJunk==true){

         /*


       
        
        boolean resultSendData= sendData(1,"&A=200.38&B=10000.38&D=100000.99&E=100.25@", 100);
        if(resultSendData==true){
          
          resultSendData= sendData(1,"&F=236.88&G=20.38&H=20.388&I="+String(getDateTime())+"@", 100);
          if(resultSendData==false){
            
            digitalWrite(is_ok,LOW);
            digitalWrite(present_errors,HIGH);
             Serial.write((String("Problemas enviando segundo paquete de datos")+"\n").c_str());
            }

            digitalWrite(is_ok,HIGH);
            digitalWrite(present_errors,LOW);
          }else{

             Serial.write((String("Problemas enviando primer paquete de datos")+"\n").c_str());
             digitalWrite(is_ok,LOW);
             digitalWrite(present_errors,HIGH);
            }
           */
          digitalWrite(is_ok,HIGH);
          digitalWrite(present_errors,LOW);
          Serial.write((String("Basura enviada Ok =)")+"\n").c_str());
        }else{
           Serial.write((String("** Problemas enviando basura")+"\n").c_str());
            digitalWrite(is_ok,LOW);
            digitalWrite(present_errors,HIGH);
          }
            
           
        digitalWrite(is_ok,HIGH);
        digitalWrite(present_errors,LOW);
       
       Serial.write((String("Recibida de basura ok =)")+"\n").c_str());
        
      }else{

          Serial.write((String("** Problemas recibiendo basura")+"\n").c_str());
         digitalWrite(is_ok,LOW);
         digitalWrite(present_errors,HIGH);
        }

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
