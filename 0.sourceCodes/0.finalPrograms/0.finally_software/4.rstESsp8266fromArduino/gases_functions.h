
  // Library of functions to calculate value about gases

#include "data_types_gases.h"

SensorValues findRs(float adc, float Vs, float RL){
    /*
     * Function using to find Rs, this process is very important
     * to calibrate the sensor
    */
    SensorValues sensorValues;
    sensorValues.VRL= (Vs*(float)adc)/(float)1023.0;
    sensorValues.Rs=((Vs/sensorValues.VRL)-1)* RL;
    return sensorValues;

    }

ChartValues   find_m_b(float x1, float y1, float x2, float y2, float xa, float ya){

      ChartValues chartValues;

      chartValues.m=(log10(y2) - log10(y1)) / (log10(x2) - log10(x1));
      chartValues.b = log10(ya) - (chartValues.m*log10(xa));

      return chartValues;

      }

float find_ppm(float Ro_clearAir, float Rs, float m, float b ){

        double ppm = pow(10, ((log10(Rs/Ro_clearAir)-b)/m));
        return ppm;

        }

float findRo(float Rs, float datasheet_ratio){
  return Rs/datasheet_ratio;
}
