#include <SoftwareSerial.h>
#include<TimerOne.h>
//#include <avr/sleep.h>
#include "functions.h"

SoftwareSerial mySerial(2, 3); // RX, TX

const byte start_uart_comm = 4;
const byte pinLed = 7;
volatile byte stateLed = LOW;

void setup() {
  // put your setup code here, to run once:

   mySerial.begin(9600);

   pinMode(start_uart_comm, OUTPUT);
   pinMode(pinLed, OUTPUT);

   Timer1.initialize(3000000);
   Timer1.attachInterrupt(sendData);
   //sleep_enable();  

}

void loop() {




  

}

boolean sendDataSoftwareSerial(String str){

     int str_len = str.length() + 1; 
     char char_array[str_len];
     str.toCharArray(char_array, str_len);


     for(int i =0; i < strlen(char_array); i++ ) {
      char c = char_array[i];
      mySerial.write(c);
    }

     //clear serial buffer
     mySerial.available();
     while(mySerial.read() >= 0);

     return true;
 
  }

  void sendData(){

     digitalWrite(start_uart_comm,HIGH);

     //delay_millis(100);


     sendDataSoftwareSerial("Hi Rojas@");


     digitalWrite(start_uart_comm,LOW);

     //delay_millis(100);

    
    
    }


    void blinkLed(){
     
     

      stateLed=!stateLed;
      digitalWrite(pinLed,stateLed);

    }



    
