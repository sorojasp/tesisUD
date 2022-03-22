#include "CO2Sensor.h"

/*
 * 
 library CO2Sensor was founded in: https://github.com/solvek/CO2Sensor

 this script was founded in : https://www.instructables.com/Tutorial-How-to-Use-Mg811-Co2-Carbon-Dioxide-Gas-S/


*/

CO2Sensor co2Sensor(A0, 0.99, 100);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Initialized ===");
  co2Sensor.calibrate();
}

void loop() {
  float val = co2Sensor.read();
  Serial.print("CO2 value: ");
  Serial.println(val);

  delay(100);
}
