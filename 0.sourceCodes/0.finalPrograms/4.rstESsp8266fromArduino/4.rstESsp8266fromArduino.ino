// *** import data types and functions to handle the clock
#include "data_types_clock.h"
#include "clock_functions.h"

#include "functions.h"
#include "serialCommunication.h"

// *** import library to handle timmer one
#include<TimerOne.h>

 /***  Set of pin to handle ESP8266-01 ***/
  
  const byte GPIO2 = 8;
  const byte GPIO0 = 7;
  const byte RST = 9;

  /***  Set of pin to indicate when the process is ok or present errors ***/

  const byte is_ok = 5;
  const byte present_errors = 6;


  /*** Variables to implement the clock ***/

  Date date_now;
  Time time_now;
  volatile boolean increaseClockEnable=false;

  //set days in months of 2022 and 2023, index 0 is 2022 and index 1 is 2023
  Anio anios[2]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
  int anios_index=0;

  String currently_time;




void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);


  Serial.begin(9600);
  Serial1.begin(9600);


   // get initial date and time
   date_now=getDate();
   time_now=getTime_();
   time_now.segundos=0;

   // set timmer 1
   /*
    * Timer1 can accept a minimum period of 1 microsecond and a maximum period of 8388480 microseconds (about 8.3 seconds).
    */
   Timer1.initialize(8000000);
   Timer1.attachInterrupt(increaseClock);

   // Initialize the time
   //handleClock();



}

void loop() {


   if(increaseClockEnable==true){

    
    Timer1.stop();

    handleClock();
    

    delay(250);
    resetESP8266(RST, GPIO0, GPIO2);
    delay(250);// this value con not be less than 200

  
    String incomingString;

    Serial1_flush_buffer();// ** important because clear the serial port after recieve the junk from ESP8266-01

    unsigned long time_wait=10000;

    boolean dataRecieved= sendData(2, "&A=200.38&B=10000.38&D=100000.99&E=100.25",time_wait);

    if(dataRecieved==true){

      Serial.println("data Recieved =)");
      Serial.flush();

      delay(200);

      dataRecieved= sendData(2, "F=236.88&G=20.38&H=20.388&I="+getCurrentTimeStr(),time_wait);

      if(dataRecieved==true){

        String data_to_server= recieveData(time_wait);
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

        

    Timer1.start();   
    increaseClockEnable=false;
    
    }




    






    }

  void handleClock(){

   time_now.segundos=time_now.segundos+8;
    if(time_now.segundos>59){
      time_now.segundos=0;
      time_now.minutos=time_now.minutos+1;

      if(time_now.minutos>59){
        time_now.minutos=0;
        time_now.horas=time_now.horas+1;
        }

       if(time_now.horas==24){
        time_now.horas=0;
        date_now.dia=date_now.dia+1;
        }

        if(date_now.dia>getDaysInMonth(anios[anios_index],date_now.mes)){
          date_now.dia=1;
          date_now.mes=date_now.mes+1;
          }

          if(date_now.mes>12){
            date_now.mes=1;
            anios_index++;
            
            }
      
      }

      

      /*
      Serial.println("Dia: "+String(date_now.dia));
      Serial.println("Mes: "+String(date_now.mes));
      Serial.println("Año: "+String(date_now.anio));
      */
      Serial.println("Horas: "+String(time_now.horas));
      Serial.println("Minutos: "+String(time_now.minutos));
      Serial.println("Segundos: "+String(time_now.segundos));

      Serial.println("*********************");
      
      
  
  
  }


void increaseClock(){
  increaseClockEnable=true;
  }



 String getCurrentTimeStr(){
  String currenTimeString= String(date_now.mes)+"-"+String(date_now.dia)+"-"+String(date_now.anio)+"h"+String(time_now.horas)+":"+String(time_now.minutos)+":"+String(time_now.segundos);

  return currenTimeString;
  
  
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
