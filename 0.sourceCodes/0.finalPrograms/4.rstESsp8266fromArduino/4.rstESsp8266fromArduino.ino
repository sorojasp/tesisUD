#include "functions.h"
#include "serialCommunication.h"

  const byte GPIO2 = 8;
  const byte GPIO0 = 7;
  const byte RST = 9;

    /* 
   *  Set of pin to indicate when the process is ok or present errors
  */

  const byte is_ok = 5;
  const byte present_errors = 6;



void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);


  Serial.begin(9600);
  Serial1.begin(9600);



}

void loop() {




    delay_millis(250);
    resetESP8266(RST, GPIO0, GPIO2);
    delay_millis(250);// this value con not be less than 200

  
    String incomingString;

    Serial1_flush_buffer();// ** important because clear the serial port after recieve the junk from ESP8266-01

    unsigned long time_wait=10000;

    boolean dataRecieved= sendData(2, "&A=200.38&B=10000.38&D=100000.99&E=100.25",time_wait);

    if(dataRecieved==true){

      Serial.println("data Recieved =)");
      Serial.flush();

      delay(200);

      dataRecieved= sendData(2, "F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18",time_wait);

      if(dataRecieved==true){

        String data_to_server= recieveData(time_wait);
        Serial.println(data_to_server);
        Serial.flush();

        data_to_server= recieveData(time_wait);
        Serial.println(data_to_server);
        Serial.flush();

        data_to_server= recieveData(time_wait);
        Serial.println(data_to_server);
        Serial.flush();
        
        
        }else{
          
         Serial.println("**  Error to send data 2 not  Recieved =(");
         Serial.flush();
        
          }


      
      
      
      }else{

        Serial.println("**  Error data not  Recieved =(");
         Serial.flush();
        
        
        
        }

        

        






    }


        /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       *
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25@
       * &SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18@
       *
       * A=200.38&B=10000.38&D=100000.99&E=100.25@
       * F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18@
       * 
       */
