
#include <string.h> 


const byte enable = 4;

void setup() {
  // put your setup code here, to run once:


   pinMode(enable,INPUT);
   Serial.begin(9600);

}

void loop() {


  if(digitalRead(enable)==LOW){
    delay(300);

     Serial.write("Hi Irene Adler - nano");
     Serial.flush();
    
    
    }






  /*

     Serial.write("Hi Irene Adler - nano");
     Serial.flush();


      while(Serial.available()==0){}

      String incomingString =Serial.readStringUntil('\n');
      serial_flush_buffer();
*/



}

  void serial_flush_buffer(){
           Serial.available();
              while (Serial.read() >= 0); // do nothing
              }
