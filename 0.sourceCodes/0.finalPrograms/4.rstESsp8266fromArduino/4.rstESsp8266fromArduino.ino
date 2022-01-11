// *** import data types and functions to handle the clock
#include "data_types_clock.h"
#include "clock_functions.h"

#include "functions.h"
#include "serialCommunication.h"

// *** import library to handle timmer one
#include<TimerOne.h>

/*Import DHT library*/
#include "DHT.h"

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
  //int period_send_data=900;
  int period_send_data=20;
  volatile boolean send_data=false;

  /* amount of sample before send data*/
  volatile int  amount_samples=period_send_data/interruption_period;


  volatile int counter=0;
  int sample_counter=0;


  /*Set of DHT11*/

  #define DHTPIN 10
  #define DHTTYPE DHT11
  DHT dht(DHTPIN, DHTTYPE);


   /*set variable of humidity and temperature */
   int h=0;
   int t=0;

   float average_temp=0;
   float average_hume=0;






void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);


  Serial.begin(9600);
  Serial1.begin(9600);



   // set timmer 1
   /*
    * Timer1 can accept a minimum period of 1 microsecond and a maximum period of 8388480 microseconds (about 8.3 seconds).
    */
   Timer1.initialize(interruption_period*1000000); //interrupiton will happen each 8 seconds
   Timer1.attachInterrupt(interruptionFunction);

   // Set diodes to alert when something is wrong

   pinMode(is_ok, OUTPUT);
   pinMode(present_errors,OUTPUT);






}

void loop() {


  if(take_sample==true){

    Timer1.stop();

    sample_counter++;
    Serial.println("take_sample");
    Serial.flush();

   h = dht.readHumidity()+h;// Lee la humedad
   t= dht.readTemperature()+t;//Lee la temperatura

   Serial.println("temperarura: "+String(dht.readHumidity()));
   Serial.flush();

   Serial.println("humedity: "+String(dht.readTemperature()));
   Serial.flush();



    Timer1.start();
    take_sample = false;
  }





   if(send_data==true){

    //In this part we will have to use the **sample_counter** to calculate the average and then we will have to set with 0


    Timer1.stop();

   average_temp=t/sample_counter;
   average_hume=h/sample_counter;

   Serial.println("Average Temperature: "+String(average_temp));
   Serial.flush();

   Serial.println("Average humedity: "+String(average_hume));
   Serial.flush();


    delay(250);
    resetESP8266(RST, GPIO0, GPIO2);
    delay(250);// this value con not be less than 200


    String incomingString;

    Serial1_flush_buffer();// ** important because clear the serial port after recieve the junk from ESP8266-01

    unsigned long time_wait=10000;

    boolean dataRecieved= sendData(2, "&A=200.38&B=10000.38&C=100000.99",time_wait);

    if(dataRecieved==true){

      digitalWrite(is_ok,HIGH);
      digitalWrite(present_errors,LOW);

      Serial.println("data Recieved =)");
      Serial.flush();

      delay(200);

      dataRecieved= sendData(2, "&D=100.25E=236.88&F="+String(average_temp)+"&G="+String(average_hume),time_wait);

      if(dataRecieved==true){
        digitalWrite(is_ok,HIGH);
        digitalWrite(present_errors,LOW);

        String data_to_server= recieveData(time_wait);
        Serial.println(data_to_server);
        Serial.flush();



        }else{

          digitalWrite(is_ok,LOW);
          digitalWrite(present_errors,HIGH);

         Serial.println("**  Error to send data 2 not  Recieved =(");
         Serial.flush();

          }


      }else{


       digitalWrite(is_ok,LOW);
       digitalWrite(present_errors,HIGH);

        Serial.println("**  Error data not  Recieved =(");
        Serial.flush();



        }




    average_temp=0;
    average_hume=0;
    t=0;
    h=0;

    sample_counter=0;
    send_data=false;

    Timer1.start();


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











        /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       *
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25
       * &SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       *
       * &A=200.38&B=10000.38&C=100000.99
       * &D=100.25E=236.88&F=20.38&G=20.388
       *
       */
