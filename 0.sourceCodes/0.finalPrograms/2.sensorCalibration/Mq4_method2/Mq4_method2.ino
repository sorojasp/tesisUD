// *** import data types and functions to handle the clock
#include "data_types_clock.h"
#include "clock_functions.h"


#include "gases_functions.h"

   float k_MQ4 = 4.4;//constant
   float k_MQ137 = 3.6;//constant
   float k_MQ136 = 1;//constant

   ChartValues chartValues_MQ4=find_m_b(200.0,1.8,1000.0,1.0,500.0,1.4);
   ChartValues chartValues_MQ137=find_m_b(40.0,1.0,100.0,0.8,70.0,0.75);
   ChartValues chartValues_MQ136=find_m_b(50.0,0.21,110.0,0.15,100,0.175);


float RL_MQ136=4.7;
float RL_MQ137=47.0;
float RL_MQ4=20;
float reference_voltage=5;


float analog_value_MQ4;
float analog_value_MQ137;
float analog_value_MQ136;


SensorValues MQ4_values;
SensorValues MQ137_values;
SensorValues MQ136_values;



float ppm_MQ4;
float ppm_MQ137;
float ppm_MQ136;

int times_calibrate_sensors=20;
int sample_frecuency=1000;// in seconds

bool sensor_calibrated=false; // false




  //float Ro_clearAir=2000;// result of the sensor calibration for MQ4



void setup() {
  Serial.begin(9600);
  //MQ136_values.Ro=117.5;
  

}


void loop() {


  //188032.54

   //MQ136_values.Ro=188032.54;

  

  if (!sensor_calibrated){

     for(int test_cycle = 1 ; test_cycle <= times_calibrate_sensors ; test_cycle++)
      {
          //Read the analog output of the sensor for n times
          analog_value_MQ4 =   analog_value_MQ4 + analogRead(A2);
          analog_value_MQ137 = analog_value_MQ137 + analogRead(A3);
          analog_value_MQ136 = analog_value_MQ136 + analogRead(A1);

        //MQ136_values =findRs(analogRead(A1) , reference_voltage, RL_MQ136);
        //MQ136_values.Ro=findRo(MQ136_values.Rs, k_MQ136);
        //Serial.print("**Ro of MQ136: ");
        //Serial.println(MQ136_values.Ro); //Display calculated Ro
     }

       analog_value_MQ4 = analog_value_MQ4 / ((float)times_calibrate_sensors); //Take average
       analog_value_MQ137 = analog_value_MQ137 / ((float)times_calibrate_sensors); //Take average
       analog_value_MQ136 = analog_value_MQ136 / ((float)times_calibrate_sensors); //Take average

        MQ4_values = findRs(analog_value_MQ4, reference_voltage, RL_MQ4);
        MQ137_values =findRs(analog_value_MQ137 , reference_voltage, RL_MQ137);
        MQ136_values =findRs(analog_value_MQ136 , reference_voltage, RL_MQ136);

        //MQ4_values.Ro=findRo(MQ4_values.Rs, k_MQ4);
        MQ4_values.Ro = 5.35;
        MQ137_values.Ro = findRo(MQ137_values.Rs, k_MQ137);
        MQ136_values.Ro = findRo(MQ136_values.Rs, k_MQ136);

        delay(2000);

        Serial.print("Ro of MQ4: ");
        Serial.println(MQ4_values.Ro); //Display calculated Ro

        Serial.print("Ro of MQ137: ");
        Serial.println(MQ137_values.Ro); //Display calculated Ro

        Serial.print("Ro of MQ136: ");
        Serial.println(MQ136_values.Ro); //Display calculated Ro

        //Serial.print("Y");

        sensor_calibrated=true;
    }else{

      MQ4_values = findRs(analogRead(A2), reference_voltage, RL_MQ4);
      MQ137_values =findRs(analogRead(A3), reference_voltage, RL_MQ137);
      MQ136_values =findRs(analogRead(A1), reference_voltage, RL_MQ136);

      ppm_MQ4= find_ppm(MQ4_values.Ro, MQ4_values.Rs, chartValues_MQ4.m, chartValues_MQ4.b );
      ppm_MQ137= find_ppm(MQ137_values.Ro, MQ137_values.Rs, chartValues_MQ137.m,chartValues_MQ137.b);
      ppm_MQ136= find_ppm(MQ136_values.Ro, MQ136_values.Rs, chartValues_MQ136.m,chartValues_MQ136.b);

      //ppm_MQ136 = find_ppm_using_VRL_MQ136(MQ136_values.VRL);
      //ppm_MQ137 = find_ppm_using_VRL_MQ136(MQ137_values.VRL);

      delay(sample_frecuency);


      Serial.print("ppm  of MQ4: ");
      Serial.flush();
      Serial.println(ppm_MQ4); //Display calculated Ro
      Serial.flush();
      
      Serial.print("ppm of MQ137: ");
      Serial.flush();
      Serial.println(ppm_MQ137); //Display calculated Ro
      Serial.flush();

     

      
      //Serial.print("VRL: ");
      //Serial.flush();
      //Serial.println(MQ136_values.VRL); //Display calculated Ro
      //Serial.flush();

      Serial.print("ppm of MQ136: ");
      Serial.flush();
      Serial.println(ppm_MQ136); //Display calculated Ro
      Serial.flush();

      

      
      //Date ahora = getDate();
      //Time tiempo = getTime_();
      
      //String ahoraString = String(ahora.anio) + String("-") +  String(ahora.mes) + String("-") +  String(ahora.dia) + "T" + tiempo.horas + ":" + tiempo.minutos +  ":" + tiempo.segundos;

      //Serial.print("time: ");
      //Serial.flush();
      //Serial.print("time");
      //Serial.println(ahoraString); //Display  Now
      //Serial.flush();
      
      
      //Serial.print("X");

      
      
      }

}
