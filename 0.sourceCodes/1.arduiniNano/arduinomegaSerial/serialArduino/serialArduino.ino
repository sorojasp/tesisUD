String incomingString; // for incoming serial data
float k_MQ4=3.6;//constant 
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

    SensorValues sensorValues= findRs(incomingString.toInt(),5,20000);
    
    
    Serial.print("VRL: ");
    Serial.println(sensorValues.VRL);
    

    Serial.print("Rs: ");
    Serial.println(sensorValues.Rs);

    Serial.print("Ro: ");
    sensorValues.Ro=sensorValues.Rs/k_MQ4;
    Serial.println(sensorValues.Ro);
  }

 

}
