/* 
 
MQ4 Calibration 
 
modified on 19 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
 
*/ 

float k_MQ4=4.4;//constant 
float x1=200.0;
float y1=1.8;
float x2=1000.0;
float y2=1.0;
float ya=1.4;
float xa=500.0;
float m=(log10(y2) - log10(y1)) / (log10(x2) - log10(x1));
float b = log10(ya) - (m*log10(xa));



  struct SensorValues{
    
    float VRL;
    float Rs;
    float Ro;

  };


  int sensorValue;


  float Ro_clearAir=8068.49;// result of the sensor calibration
  //float Ro_clearAir=2000;// result of the sensor calibration



  SensorValues findRs(int adc, float Vs, float RL){

    
    SensorValues sensorValues;
    float VRL= (5.0*(float)adc)/(float)1024;
    float Rs=((Vs/VRL)-1)* RL;
    sensorValues.VRL=VRL;
    sensorValues.Rs=Rs;
    
    return sensorValues;
    }


  
void setup() { 
  Serial.begin(9600); 
} 


  

  
void loop() { 

 
   SensorValues sensorValues;



    sensorValues = findRs(analogRead(A0),5,20000);

    Serial.print("Rs = "); 
    Serial.println(sensorValues.Rs);

    Serial.print("Ro: ");

    float Ro=sensorValues.Rs/k_MQ4;
    Serial.println(Ro);

     Serial.print("VRL = "); 
    Serial.println(sensorValues.VRL); 


    Serial.print("adc:");
    Serial.println(analogRead(A0));

    
    Serial.print("Ratio: ");
    float Ratio=sensorValues.Rs/Ro_clearAir;
    Serial.println(Ratio);



    
    Serial.print("ppm: ");
    double ppm = pow(10, ((log10(sensorValues.Rs/Ro_clearAir)-b)/m)); //use formula to calculate ppm
    Serial.println(ppm); //Display ppm
    

  
   
}
