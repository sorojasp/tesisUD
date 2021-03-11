
#include <ESP8266WiFi.h> //Timer1 library no funciona en el ESP8266, pero ESP8266WiFi.h tiene el objeto timer1_  

#include <string.h> 
#include <Ticker.h>

Ticker blinker;

// constants won't change. Used here to 
// set pin numbers:
 int GPIO2 =  2;      // the number of the LED pin
 int GPIO0 =  0; 
// Variables will change:
boolean ledState = false;             // ledState used to set the LED
int secondsInInterrupt=2;


void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO2, OUTPUT);
  pinMode(GPIO0, OUTPUT); 
  setAndLaunchinterrupt();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GPIO0,false);
  delay(1000*10);
  digitalWrite(GPIO0,true);
  delay(1000*10);

}


void  ICACHE_RAM_ATTR  blink_led(){

    ledState=!ledState;
    digitalWrite(GPIO2,ledState);
    timer1_write(setInterruptFrecuency(secondsInInterrupt));//12us
  }
  
void setAndLaunchinterrupt(){

    //Initialize Ticker every 
    timer1_attachInterrupt(blink_led);
    timer1_enable(TIM_DIV256, TIM_EDGE, TIM_SINGLE); // frecuencia del ESP es 80MHz / 256 = 312500
    timer1_write(setInterruptFrecuency(secondsInInterrupt)); //
  }


  void endInterrupt(){
    timer1_detachInterrupt();
    }

   int setInterruptFrecuency(int seconds){
    return 312500*seconds;
    }

   
