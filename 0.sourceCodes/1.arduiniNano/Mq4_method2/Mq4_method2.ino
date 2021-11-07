/*

MQ4 Calibration

modified on 19 Feb 2019
by Saeed Hosseini
https://electropeak.com/learn/

*/

#include "gases_functions.h"


float k_MQ4=4.4;//constant
float k_MQ137=3.6;//constant


ChartValues chartValues_MQ4=find_m_b(200.0,1.8,1000.0,1.0,500.0,1.4);
ChartValues chartValues_MQ137=find_m_b(40.0,1.0,100.0,0.8,70.0,0.75);

float analog_value_MQ4;
float analog_value_MQ137;

SensorValues MQ4_values;
SensorValues MQ137_values;

float ppm_MQ4;
float ppm_MQ137;

int times_calibrate_sensors=5000;

bool sensor_calibrated=false;

  //float Ro_clearAir=2000;// result of the sensor calibration for MQ4



void setup() {
  Serial.begin(9600);
}





void loop() {

  

  if (!sensor_calibrated){

     for(int test_cycle = 1 ; test_cycle <= times_calibrate_sensors ; test_cycle++)
  {
    //Read the analog output of the sensor for 500 times
  analog_value_MQ4 =   analog_value_MQ4 + analogRead(A0);
  analog_value_MQ137 = analog_value_MQ137 + analogRead(A1);
  }

  analog_value_MQ4 = analog_value_MQ4 / ((float)times_calibrate_sensors); //Take average
  analog_value_MQ137 = analog_value_MQ137 / ((float)times_calibrate_sensors); //Take average

  MQ4_values = findRs(analog_value_MQ4, 5.0, 20.0);
  MQ137_values =findRs(analog_value_MQ137 , 5.0, 47.0);

  MQ4_values.Ro=findRo(MQ4_values.Rs, k_MQ4);
  MQ137_values.Ro=findRo(MQ4_values.Rs, k_MQ137);

  delay(2000);

  Serial.print("Ro of MQ4: ");
  Serial.println(MQ4_values.Ro); //Display calculated Ro

  Serial.print("Ro of MQ137: ");
  Serial.println(MQ137_values.Ro); //Display calculated Ro

    sensor_calibrated=true;
    }else{

      MQ4_values = findRs(analogRead(A0), 5.0, 20.0);
      MQ137_values =findRs(analogRead(A1), 5.0, 47.0);

      ppm_MQ4= find_ppm(MQ4_values.Ro, MQ4_values.Rs, chartValues_MQ4.m, chartValues_MQ4.b );
      ppm_MQ137= find_ppm(MQ137_values.Ro, MQ137_values.Rs, chartValues_MQ137.m,chartValues_MQ137.b);

      delay(2000);


      Serial.print("ppm  of MQ4: ");
      Serial.println(ppm_MQ4); //Display calculated Ro
      
      Serial.print("ppm of MQ137: ");
      Serial.println(ppm_MQ137); //Display calculated Ro
      
      
      
      
      }

 




}
