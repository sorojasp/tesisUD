#include<TimerOne.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


volatile byte state = LOW;
int pinLed=8;
String MSG="";
char c;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed,OUTPUT);
  //Timer1.initialize(100000);
  //Timer1.attachInterrupt(blink);
  mySerial.begin(9600);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //mySerial.readStringUntil('@');
     char buf[30];
     const char *first = "sent ";
     const char *second = "message";
     strcpy(buf,first);
     strcat(buf,second);
     
     for(int i =0; i < strlen(buf); i++ ) {
      char c = buf[i];
      Serial.write(c);
    
    }
    Serial.write('\n');
    
    
    }





void blink(){
  state=!state;
  digitalWrite(pinLed,state);
  while(mySerial.available()<=0){}
  while(mySerial.available()>0){

    c=mySerial.read();
    MSG.concat(c);
    }


  }
