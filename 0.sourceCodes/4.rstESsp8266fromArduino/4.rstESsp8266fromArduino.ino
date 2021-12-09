
  #include "functions.h"
  
  const byte GPIO2 = 2;
  const byte GPIO0 = 3;
  const byte RST = 4;
  const byte pusher=5;
  const byte led1=6;
  const byte led2=7;

  int counter = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);
  pinMode(pusher,INPUT);

  Serial.begin(9600);
  Serial1.begin(9600);
  //serial_flush_buffer();

  
}

void loop() {

  //if(digitalRead(pusher)==LOW){
    counter++;
     //Serial.begin(9600);
     //Serial1.begin(9600);
    delay(1000);
    digitalWrite(GPIO0,HIGH);
    digitalWrite(GPIO2,HIGH);
    digitalWrite(RST,HIGH);
    delay(20);
    digitalWrite(RST,LOW);
    delay(100);

     digitalWrite(RST,HIGH);
  
while(true){
     while(Serial.available()==0){}

      String incomingString =Serial.readStringUntil('@');
      incomingString=incomingString;
      serial_flush_buffer();
      //

      /*data to probe  NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18
       * 
       * ?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25@
       * &SO2=236.88&T=200.38&H=200.388&t=Dec-9-2021h10:02:18@
       * 
     *A=200.38&B=10000.38&D=100000.99&E=100.25@
     *F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18@
       */
     
  
     Serial.write(incomingString.c_str()); // c_str to convet string to chart*
     Serial.flush();

     if(String("F=236.88&G=20.38&H=20.388&I=Dec-9-2021h10:02:18")==incomingString){
      Serial.println("=)");
     Serial.flush();
      
      }else{
        Serial.println("=(");
        Serial.flush();
        
        
        }
     }

     //String msg= "Hi Irene Adler"+String("7");

    //Serial1.write(msg.c_str());
    //Serial1.flush();
    
     //Serial.end();
     //Serial1.end();

 

     //Serial.println("counter:"+String(counter));

     //Serial.println(incomingString.indexOf("hi from esp8266-01,12345"));

      
      
     
     
      
    
       /**
      if(incomingString==String("hi from esp8266-01")){
        Serial.println(String(" ** msg  is: ")+incomingString);

        
        }else{
           Serial.println(String(" ** Error msg not is: ")+incomingString);
          }

          **/
    
       
  //}

  counter=0;

  
  

  

  
    }
  
    void serial_flush_buffer(){
                  Serial1.available();
                while (Serial1.read() >= 0); // do nothing
              }
