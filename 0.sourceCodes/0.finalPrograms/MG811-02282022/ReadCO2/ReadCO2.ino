#include "data_types_gases.h"

/** python scripts to get m and b values for each line 
 def find_m_a(x1:float, y1:float, x2:float, y2:float):
    m = (y2 - y1) / (x2 - x1)
    b = y1 - m * x1
    return {
        "m":round(m,6),
        "b":round(b,6)
        
        }


MG811_chart_points=[ 
     {"x":400,"y":324 }, 
     {"x": 600,"y":314 },
     {"x": 800,"y": 307.4 },
     {"x":1000, "y":303.34 },
     {"x":1568.19,"y": 298.45},
     {"x":2000,"y":293.34 },
     {"x":2576.93,"y": 288.89},
     {"x":3000,"y": 286 },
     {"x":4000, "y": 280.089 },
     {"x": 6000,"y":274.23 },
     {"x": 8000,"y":268.8 },
     {"x": 10000,"y": 263.78} 
     ]
   

m_a_constanst=[]

index:int=0

while index<len(MG811_chart_points)-1:
    m_a_constanst.append(find_m_a(MG811_chart_points[index]['x'],MG811_chart_points[index]['y'], MG811_chart_points[index+1]['x'],MG811_chart_points[index+1]['y']  ))
    index+=1
    
print(m_a_constanst)
 */


   Point MG811_points[12]= { { 400,324 }, { 600,314 },{ 800, 307.4 },{
   1000, 303.34 },{ 1568.19, 298.45  },{ 2000,293.34 },{ 2576.93, 288.89 },{ 3000, 286 },{ 4000,  280.089 },{ 6000,274.23 },{ 8000,268.8 },{ 10000, 263.78 } };
    
   ChartValues chartValuesMG811[11]={{-0.05,344.0}, { -0.033,  333.8}, {-0.0203,  323.64}, {-0.008606,  311.946276}, {-0.011834,  317.007817}, { -0.007713,  308.766482}, { -0.006831,  306.493063}, { -0.005911,  303.733}, { -0.002929,  291.807}, { -0.002715,  290.52}, { -0.00251,  288.88}};



void setup() {

  Serial.begin(9600);

}

void loop() {

  delay(700);

  float adcValue= float(analogRead(A0));

  Serial.println("adcValue: "+ String(adcValue));
  float MG811AnalogVoltage = float(((5.0*(float)adcValue)/(float)1023.0)*1000); // get MG811 Voltage in mV

    Serial.println("voltage: "+String(MG811AnalogVoltage));
      Serial.flush();

  int index=0;
  bool lineFounded=false;

  while((index<(sizeof(MG811_points)-1)&&lineFounded==false)){

    if( (MG811AnalogVoltage>=MG811_points[index].y) && (MG811AnalogVoltage<=MG811_points[index+1].y) ){
      lineFounded=true;
      Serial.println("line: "+String(index));
      Serial.flush();
      }
    
    index++;
    }
    
    }
