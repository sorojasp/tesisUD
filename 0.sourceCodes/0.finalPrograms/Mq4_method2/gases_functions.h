
  // Library of functions to calculate value about gases

#include "data_types.h"

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

  
     /**
     [-372049.23756175  462144.66812135 -193059.11451625   32085.14180293
     -1730.32952222]
     */

     double ak = -372049.23756175;
     double bk = 462144.66812135;
     double ck = -193059.11451625;
     double dk = 32085.14180293;
     double ek = -1730.32952222;
  

        double ppm = pow(10, ((log10(Rs/Ro_clearAir)-b)/m));

        //double ppm = ( ak * pow((Rs/Ro_clearAir), 4)) + ( bk * pow((Rs/Ro_clearAir), 3)) + ( ck * pow((Rs/Ro_clearAir), 2)) + ( dk * pow((Rs/Ro_clearAir), 1)) + ek;

        
        return ppm;



        }

float find_ppm_using_VRL_MQ136(float VRL){

  
     /**

          import matplotlib.pyplot as plt
          import numpy as np
          #x_data = [0.5, 0.625, 0.75, 1, 1.25, 1.448979592, 1.625, 1.75, 1.836734694, 1.897959184, 1.93877551, 2, 2.020408163, 2.06122449, 2.081632653, 2.12244898, 2.142857143, 2.153061224, 2.163265306, 2.1875]
          #y_data = [0, 1, 3, 6.25, 12.5, 25, 37.5, 50, 62.5, 75, 87.5, 100, 112.5, 125, 137.5, 150, 162.5, 175, 187.5, 200]

          x_data = [0.732, 1]
          y_data = [0, 3.645]



          #x_data = [1, 1.16]
          #y_data = [3.645, 9.27]

          #x_data = [1.16, 1.37]
          #y_data = [9.27, 24.85]


          x =  np.array(x_data)
          y = np.array(y_data)
          model = np.poly1d(np.polyfit(x, y, 1))

          #print("model: ", model)
          ynew = model(x)
          plt.plot(x, y, 'o', x, ynew, '-' , )
          plt.ylabel( str(model).strip())
          plt.show()
     */

     double a = 136.2;
     double b = -964.2;
     double c = 2758;
     double d = -4028;
     double e =  3162;
     double f =  -1252;
     double g = 194.9;

     if (VRL <=0.732){

       return 0;

     }else if( (VRL > 0.732) && (VRL <= 1) ){

       return (  13.6 * VRL) - 9.956;


     }else if( (VRL > 1) && (VRL <= 1.16) ){

       return (  35.16 * VRL) - 31.51;

     } else if( (VRL > 1.16) && (VRL <= 1.37) ){


       return (  74.19 * VRL) - 76.79;


     }

        double ppm = ( a * pow((VRL), 6)) + ( b * pow((VRL), 5)) + ( c * pow((VRL), 4)) + ( d * pow((VRL), 3)) + ( e * pow((VRL), 2)) + ( f * VRL) + g; 
        return ppm;


     
  

        

     



        }

float findRo(float Rs, float datasheet_ratio){
  return Rs/datasheet_ratio;
}
