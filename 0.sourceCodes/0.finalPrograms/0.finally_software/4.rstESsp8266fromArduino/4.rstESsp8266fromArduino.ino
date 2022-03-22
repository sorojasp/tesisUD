// *** import data types and functions to handle the clock
#include "data_types_clock.h"
#include "clock_functions.h"

#include "functions.h"
#include "serialCommunication_port0.h"
//#include "serialCommunication.h"

// *** import library to handle timmer one
#include<TimerOne.h>

/*Import DHT library*/
#include "DHT.h"

/**import gases functions**/
#include "gases_functions.h"

 /***  Set of pin to handle ESP8266-01 ***/


  const byte GPIO2 = 11;
  const byte GPIO0 = 10;
  const byte RST = 9;

  /***  Set of pin to indicate when the process is ok or present errors ***/

  const byte is_ok = 8;
  const byte present_errors = 7;

  //*flag to know if the sytem is work to make probe**///

  const byte probe_mode = 6;

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

  #define DHTPIN 12//PIN SELECTED
  #define DHTTYPE DHT11
  DHT dht(DHTPIN, DHTTYPE);


   /*set variable of humidity and temperature */
   int h=0;
   int t=0;

   float average_temp=0;
   float average_hume=0;


   /*Set variables to get gas concentrations */
   
   float k_MQ4=4.4;//constant
   float k_MQ137=3.6;//constant
   float k_MQ136=3.6;//constant

   ChartValues chartValues_MQ4=find_m_b(200.0,1.8,1000.0,1.0,500.0,1.4);
   ChartValues chartValues_MQ137=find_m_b(40.0,1.0,100.0,0.8,70.0,0.75);
   ChartValues chartValues_MQ136=find_m_b(40.0,1.0,100.0,0.78,70.0,0.87);
   
   float analog_value_MQ4;
   float analog_value_MQ137;
   float analog_value_MQ136;
   
   SensorValues MQ4_values;
   SensorValues MQ137_values;
   SensorValues MQ136_values;
   
   float ppm_MQ4=0;
   float ppm_MQ137=0;
   float ppm_MQ136=0;
   
     

   float ppm_MQ4_average=0;
   float ppm_MQ137_average=0;
   float ppm_MQ136_average=0;
    
    


   






void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);

  pinMode(probe_mode,INPUT);


  Serial.begin(9600);
  //Serial1.begin(9600);



   // set timmer 1
   /*
    * Timer1 can accept a minimum period of 1 microsecond and a maximum period of 8388480 microseconds (about 8.3 seconds).
    */
   Timer1.initialize(interruption_period*1000000); //interrupiton will happen each 8 seconds
   Timer1.attachInterrupt(interruptionFunction);

   // Set diodes to alert when something is wrong

   pinMode(is_ok, OUTPUT);
   pinMode(present_errors,OUTPUT);

   /*Set Ro for each sensor*/

    MQ4_values.Ro=37.39;
    MQ137_values.Ro=155.74;
    MQ136_values.Ro=87.92;






}

void loop() {


  if(take_sample==true){

   

    Timer1.stop();
    
    
    //Serial.println("take_sample");// ** just for test
    //Serial.flush();// ** just for test

    if(dht.readHumidity()!=NULL || dht.readHumidity()!=NULL){
      sample_counter++;
      h = dht.readHumidity()+h;// Lee la humedad
      t= dht.readTemperature()+t;//Lee la temperatura
      
      //Serial.println("temperaTura: "+String( dht.readTemperature()));// ** just for test
      //Serial.flush();// ** just for test
      
      //Serial.println("humedity: "+String(dht.readHumidity()));// ** just for test
      //Serial.flush();// ** just for test

      MQ4_values = findRs(analogRead(A2), 5.0, 20.0);
      MQ137_values =findRs(analogRead(A3), 5.0, 47.0);
      MQ136_values =findRs(analogRead(A1), 5.0, 20.0);

      ppm_MQ4= find_ppm(MQ4_values.Ro, MQ4_values.Rs, chartValues_MQ4.m, chartValues_MQ4.b )+ppm_MQ4;
      ppm_MQ137= find_ppm(MQ137_values.Ro, MQ137_values.Rs, chartValues_MQ137.m,chartValues_MQ137.b)+ppm_MQ137;
      ppm_MQ136= find_ppm(MQ136_values.Ro, MQ136_values.Rs, chartValues_MQ136.m,chartValues_MQ136.b)+ppm_MQ136;


      

      digitalWrite(is_ok,HIGH);
      digitalWrite(present_errors,LOW);


      }else{

        //Serial.println("Invalid value");
        //Serial.flush();

        digitalWrite(is_ok,LOW);
        digitalWrite(present_errors,HIGH);

        
        
        }

        Timer1.start();
       take_sample = false;

   
  }





   if(send_data==true && sample_counter!=0){

    //In this part we will have to use the **sample_counter** to calculate the average and then we will have to set with 0


    Timer1.stop();

   average_temp=t/sample_counter;
   average_hume=h/sample_counter;
   ppm_MQ4_average=ppm_MQ4/sample_counter;
   ppm_MQ136_average=ppm_MQ136/sample_counter;
   ppm_MQ137_average=ppm_MQ137/sample_counter;

   //Serial.println("Average Temperature: "+String(average_temp));// ** just for test
   //Serial.flush();// ** just for test

   //Serial.println("Average humedity: "+String(average_hume));// ** just for test
   //Serial.flush();// ** just for test


    delay(250);
    resetESP8266(RST, GPIO0, GPIO2);
    delay(250);// this value con not be less than 200


    String incomingString;

    Serial1_flush_buffer();// ** important because clear the serial port after recieve the junk from ESP8266-01

    unsigned long time_wait=10000;

    boolean dataRecieved= sendData(2, "&A="+String(ppm_MQ137_average)+"&B=10000.38&C="+String(ppm_MQ4_average)+String("&H=4.697540")+"&probe_mode="+String(digitalRead(probe_mode)),time_wait);

    if(dataRecieved==true){

      digitalWrite(is_ok,HIGH);
      digitalWrite(present_errors,LOW);

      //Serial.println("data Recieved =)");// ** just for test
      //Serial.flush();// ** just for test

      delay(200);

      dataRecieved= sendData(2, "&D="+String(ppm_MQ136_average)+"&E=236.88&F="+String(average_temp)+"&G="+String(average_hume)+String("&I=-74.114441"),time_wait);

      if(dataRecieved==true){
        digitalWrite(is_ok,HIGH);
        digitalWrite(present_errors,LOW);

        String data_to_server= recieveData(time_wait);
        //Serial.println(data_to_server);// ** just for test
        //Serial.flush();// ** just for test

        if(data_to_server=="data sended to server =)"){
          digitalWrite(is_ok,HIGH);
          digitalWrite(present_errors,LOW);
          
          }else{
            digitalWrite(is_ok,LOW);
           digitalWrite(present_errors,HIGH);
            
            
            }



        }else{

          digitalWrite(is_ok,LOW);
          digitalWrite(present_errors,HIGH);

         //Serial.println("**  Error to send data 2 not  Recieved =(");// ** just for test
         //Serial.flush();

          }


      }else{


       digitalWrite(is_ok,LOW);
       digitalWrite(present_errors,HIGH);

        //Serial.println("**  Error data not  Recieved =(");
        //Serial.flush();



        }




    average_temp=0;
    average_hume=0;
    t=0;
    h=0;
    
    ppm_MQ4_average=0;
    ppm_MQ137_average=0;
    ppm_MQ136_average=0;

    ppm_MQ4=0;
    ppm_MQ136=0;
    ppm_MQ137=0;


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











        /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388
       *
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99
       * &H2S=100.25&SO2=236.88&T=200.38&H=200.388
       *
       * &A=200.38&B=10000.38&C=100000.99
       * &D=100.25E=236.88&F=20.38&G=20.388
       *
       */
