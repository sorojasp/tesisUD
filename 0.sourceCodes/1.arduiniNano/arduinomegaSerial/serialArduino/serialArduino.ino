String incomingString; // for incoming serial data
float k_MQ4=4.4;//constant 
float x1=200;
float y1=1.8;
float x2=1000;
float y2=1;
float ya=1.4;
float xa=500;
float m=(log10(y2) - log10(y1)) / (log10(x2) - log10(x1));
float b = log10(ya) - (m*log10(xa));
float Ro_clearAir=6818.18;

  struct SensorValues{
    
    float VRL;
    float Rs;
    float Ro;

  };


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  }


  SensorValues findRs(int adc, float Vs, float RL){

    
    SensorValues sensorValues;
    float VRL= (5*adc)/1023;
    float Rs=((Vs/VRL)-1)* RL;
    sensorValues.VRL=VRL;
    sensorValues.Rs=Rs;
    
    return sensorValues;
    }



void loop() {
  // put your main code here, to run repeatedly:

  

 if (Serial.available()) {
    // read the incoming byte:
    incomingString = Serial.readStringUntil('\r\n');

    // say what you got:
    Serial.print("adc: ");
    Serial.println(incomingString);

    SensorValues sensorValues= findRs(incomingString.toInt(),5,1000);
    
    
    Serial.print("VRL: ");
    Serial.println(sensorValues.VRL);
    

    Serial.print("Rs: ");
    Serial.println(sensorValues.Rs);

    /*
    Serial.print("Ro: ");
    sensorValues.Ro=sensorValues.Rs/k_MQ4;
    Serial.println(sensorValues.Ro);


    

    Serial.print("Ratio: ");
    float Ratio=sensorValues.Rs/Ro_clearAir;
    Serial.println(Ratio);



 

    
    Serial.print("ppm: ");
    double ppm = pow(10, ((log10(sensorValues.Rs/Ro_clearAir)-b)/m)); //use formula to calculate ppm
    Serial.println(ppm); //Display ppm
    */




    
  }

 

}
