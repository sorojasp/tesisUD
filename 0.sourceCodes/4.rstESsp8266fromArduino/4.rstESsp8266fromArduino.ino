

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
     while(Serial1.available()==0){}

      String incomingString =Serial1.readStringUntil('@');
      serial_flush_buffer();
      //
     
  
     Serial.println(incomingString);
     Serial.flush();

     if(String("Hi Irene Adler - nano")==incomingString){
      Serial.println("=)");
     Serial.flush();
      
      }else{
        Serial.println("=(");
        Serial.flush();
        
        
        }
     }

    //Serial1.write("Hi Irene Adler");
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
