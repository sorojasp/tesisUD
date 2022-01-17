#include "serialCommunication_port0.h"
#include<TimerOne.h>
#include "functions.h"




volatile int  amount;
const byte GPIO2 = 11;
const byte GPIO0 = 10;
const byte RST = 9;

const byte is_ok = 8;
const byte present_errors = 7;


void setup() {
  // put your setup code here, to run once:

    // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);

  Serial.begin(9600);
 
  
  Timer1.initialize(1000000); //interrupiton will happen each 1 second
  Timer1.attachInterrupt(interruptionFunction);

  pinMode(is_ok, OUTPUT);
  pinMode(present_errors,OUTPUT);

  digitalWrite(is_ok,LOW);
  digitalWrite(present_errors,HIGH);

  // Set diodes to alert when something is wrong

   

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long time_wait=10000;
  boolean dataSended;



    if(amount>19){
      delay(250);
      resetESP8266(RST, GPIO0, GPIO2);
      delay(250);// this value con not be less than 200

      delay(7000);


    amount=0;
      }

}


void interruptionFunction(){
  amount++;
  
  
  }
