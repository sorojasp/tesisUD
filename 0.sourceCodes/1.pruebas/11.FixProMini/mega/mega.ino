#include "serialCommunication.h"


void setup() {
  // put your setup code here, to run once:

  Serial1.begin(9600);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("junk@");
  Serial.flush();



  unsigned long time_wait = 10000;
  String sensor_data1= recieveData(time_wait);

  if(sensor_data1!="false@"){

    delay(100);
    String sensor_data2= recieveData(time_wait);

    if(sensor_data2!="false@"){
  

  

}
