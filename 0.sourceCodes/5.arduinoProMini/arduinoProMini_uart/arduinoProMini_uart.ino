
#include <string.h> 


const byte enable = 3;

void setup() {
  // put your setup code here, to run once:


   Serial.begin(9600);
   pinMode(enable,INPUT);

}

void loop() {


  if(enable==HIGH){

      Serial.write("Hi Irene Adler - nano");
      Serial.flush();

      
      while(Serial.available()==0){}

      String incomingString =Serial.readStringUntil('\n');
      serial_flush_buffer();


    
    }





}

  void serial_flush_buffer(){
           Serial.available();
              while (Serial.read() >= 0); // do nothing
              }
