#include <SoftwareSerial.h>
#include<TimerOne.h>
SoftwareSerial mySerial(10, 3); // RX, TX

const byte pinLed = 13;
const byte pulser=12;
volatile byte ledState = LOW;
volatile unsigned int cuenta = 0;

volatile boolean flag=false;
volatile String s;
char myChar;
void setup() {
  // put your setup code here, to run once:

 

  Serial.begin(9600);
  Serial1.begin(9600);
  mySerial.begin(9600);


  pinMode(pinLed,OUTPUT);
  pinMode(pulser,INPUT);

    SREG = (SREG & 0b01111111); //Desabilitar interrupciones
    TIMSK2 = TIMSK2|0b00000001; //Habilita la interrupcion por desbordamiento
    TCCR2B = 0b00000111; //Configura preescala para que FT2 sea de 7812.5Hz
    SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones

   Timer1.initialize(2000000);
   Timer1.attachInterrupt(blinkLed);


  

}

void loop() {


  if(flag==true && s!=""){
    Timer1.stop();
    s.trim();
    Serial.write(s.c_str());
       Serial.flush();
       s="";
       Serial.write("\n");
       Serial.flush();

       flag==false;
       Timer1.restart();  
}
  

  

}

void serial_flush_buffer(){
  mySerial.available();
  while(Serial.read() >= 0); // do nothing
}


void recieveData(){




    
    String incomingMsg ;
    flag=false;

    //while(mySerial.available()==0){}



    if(mySerial.available()>0){
      incomingMsg=mySerial.read();

      int suma=incomingMsg.toInt()+0;
      myChar = suma;
      s.concat(String(myChar));
      
      }

      if(myChar=='@'){
        flag=true;
        
        }

  
  }



  ISR(TIMER2_OVF_vect){

  cuenta++;
    if(cuenta > 29) {

     ledState=!ledState;

      //digitalWrite(pinLed,ledState);
      cuenta=0;


    }

}

void blinkLed(){

  digitalWrite(pinLed,LOW);
  //while(digitalRead(pulser)==LOW){}
  while(cuenta<25){};
  digitalWrite(pinLed,HIGH);
 
  
  
  }
