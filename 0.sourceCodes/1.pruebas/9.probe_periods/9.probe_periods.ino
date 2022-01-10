
// *** import library to handle timmer one
#include<TimerOne.h>


 /***  Set of pin to handle ESP8266-01 ***/

  const byte GPIO2 = 8;
  const byte GPIO0 = 7;
  const byte RST = 9;

  /***  Set of pin to indicate when the process is ok or present errors ***/

  const byte is_ok = 5;
  const byte present_errors = 6;

  /*set period of interruption and period to take a sample*/
  int interruption_period=5; // 5 seconds;
  volatile boolean take_sample=false;

  /* set period to send data in seconds*/
  int period_send_data=15;
  volatile boolean send_data=false;

  /* amount of sample before send data*/
  volatile int  amount_samples=period_send_data/interruption_period;


  volatile int counter=0;




void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);


  Serial.begin(9600);
 



   // set timmer 1
   /*
    * Timer1 can accept a minimum period of 1 microsecond and a maximum period of 8388480 microseconds (about 8.3 seconds).
    */
   Timer1.initialize(interruption_period*1000000); //interrupiton will happen each 8 seconds
   Timer1.attachInterrupt(interruptionFunction);

 



}

void loop() {


  if(take_sample==true){

    Serial.println("take_sample");
    take_sample = false;
  }





   if(send_data==true){

    Serial.println("SEND_DATA");
    Serial.println(amount_samples);
    send_data=false;

    }


    }


    void interruptionFunction(){

      take_sample=true;
      counter++;
      if(counter>=amount_samples){
        counter=0;
        send_data=true;
      }

    }
