#include "functions.h"
#include<TimerOne.h>



Date date_now;
Time time_now;
volatile boolean increaseClockEnable=false;

//set days in months of 2022 and 2023, index 0 is 2022 and index 1 is 2023
Anio anios[2]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
int anios_index=0;





void setup() {
 Serial.begin(9600);
 date_now=getDate();
 time_now=getTime_();

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(increaseClock);
 

 
}
 
void loop() {


  if(increaseClockEnable==true){
    
    handleClock();
    increaseClockEnable=false;
    
    }

     

  
 
}


void handleClock(){

   time_now.segundos=time_now.segundos+1;
    if(time_now.segundos==60){
      time_now.segundos=0;
      time_now.minutos=time_now.minutos+1;

      if(time_now.minutos==60){
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
      
      Serial.println("Horas: "+String(time_now.horas));
      Serial.println("Minutos: "+String(time_now.minutos));
      Serial.println("Segundos: "+String(time_now.segundos));

      Serial.println("*********************");
      */
      
  
  
  }


void increaseClock(){
  increaseClockEnable=true;
  
  }
