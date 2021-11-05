/* 
 
MQ4 Calibration 
 
modified on 19 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
 
*/ 

  struct SensorValues{
    
    float VRL;
    float Rs;
    float Ro;

  };


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


    sensorValues = findRs(analogRead(A0),5,1000);

    Serial.print("Analog value: ");
    Serial.println(analogRead(A0));

    Serial.print("Rs = "); 
    Serial.println(sensorValues.Rs);

     Serial.print("VRL = "); 
    Serial.println(sensorValues.VRL); 


     Serial.print("Ro: ");
    sensorValues.Ro=sensorValues.Rs/k_MQ4;
    Serial.println(sensorValues.Ro);

    Serial.print("Ratio: ");
    float Ratio=sensorValues.Rs/Ro_clearAir;
    Serial.println(Ratio);



 

    
    Serial.print("ppm: ");
    double ppm = pow(10, ((log10(sensorValues.Rs/Ro_clearAir)-b)/m)); //use formula to calculate ppm
    Serial.println(ppm); //Display ppm
  

}
