

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
  serial_flush_buffer();

  
}

void loop() {

  if(digitalRead(pusher)==LOW){
    counter++;
    
    delay(300);
    digitalWrite(GPIO0,HIGH);
    digitalWrite(GPIO2,HIGH);
    digitalWrite(RST,HIGH);
    delay(20);
    digitalWrite(RST,LOW);
    delay(100);

     digitalWrite(RST,HIGH);
  

     while(Serial.available()==0){}
     int incomingString =Serial.read();
     Serial.println("incoming data:"+String(incomingString));

      serial_flush_buffer();
     Serial.println("");

     Serial.println("counter:"+String(counter));

     //Serial.println(incomingString.indexOf("hi from esp8266-01"));

      
    
       /**
      if(incomingString==String("hi from esp8266-01")){
        Serial.println(String(" ** msg  is: ")+incomingString);

        
        }else{
           Serial.println(String(" ** Error msg not is: ")+incomingString);
          }

          **/
    
       
  }

  counter=0;

  
  

  

  
    }

    void serial_flush_buffer(){
                  Serial.available();
              while (Serial.read() >= 0); // do nothing
              }
