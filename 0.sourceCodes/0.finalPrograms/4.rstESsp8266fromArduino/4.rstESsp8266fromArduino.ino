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

       

        Serial1_flush_buffer();

        

        Serial1.println("&A=200.38&B=10000.38&D=100000.99&E=100.25@");
         Serial1.flush();

          unsigned long time_wait=120000;
          
          
          incomingString=waitForData(time_wait);

           Serial.println(incomingString);
           Serial.flush();

           if(incomingString=="xddata1 recieved"){
             Serial.println("=)");
           Serial.flush();
            
            
            }else{

               Serial.println("** =(");
           Serial.flush();
              
              
              }

           
           Serial1.println("&F=236.88&G=20.38&H=20.388&I="+getDateTime()+"@");
           Serial1.flush();
         
 
           incomingString=waitForData(time_wait);
            
        
          

          

          

        
        

        Serial.println(incomingString);
        Serial.flush();

    





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
