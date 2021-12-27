#include <SoftwareSerial.h>
#include<TimerOne.h>
//#include <avr/sleep.h>


SoftwareSerial mySerial(2, 3); // RX, TX

const byte start_uart_comm = 4;
const byte recieve_data=7;
volatile byte stateLed = LOW;
const byte pinLed = 9;
const byte pinLed_2 = 8;
int enableInterruption=5;
int disableInterruption=6;

volatile byte ledState = LOW;
volatile unsigned int cuenta = 0;


void setup() {
  // put your setup code here, to run once:

   mySerial.begin(9600);

   pinMode(start_uart_comm, OUTPUT);
   pinMode(pinLed, OUTPUT);
   pinMode(pinLed_2, OUTPUT);
   pinMode(enableInterruption, INPUT);
   pinMode(disableInterruption, INPUT);
   pinMode(recieve_data, OUTPUT);

   //enable interruption timmer 2
    SREG = (SREG & 0b01111111); //Desabilitar interrupciones
    TIMSK2 = TIMSK2|0b00000001; //Habilita la interrupcion por desbordamiento
    TCCR2B = 0b00000111; //Configura preescala para que FT2 sea de 7812.5Hz
    SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones


   Timer1.initialize(3000000);
   Timer1.attachInterrupt(sendData);

   //**sleep_enable();



}

void loop() {

    if(digitalRead(disableInterruption)==LOW){
     TIMSK2 = TIMSK2&0b11111110;
     digitalWrite(pinLed_2, HIGH);
    }


  if(digitalRead(enableInterruption)==LOW){
    TIMSK2 = TIMSK2|0b00000001;
     }







}

boolean sendDataSoftwareSerial(String str){

     int str_len = str.length() + 1;
     char char_array[str_len];
     str.toCharArray(char_array, str_len);


     for(int i =0; i < strlen(char_array); i++ ) {
      char c = char_array[i];
      mySerial.write(c);
    }

     //clear serial buffer
        mySerial.flush();
     //mySerial.available();
     //while(mySerial.read() >= 0);

     return true;

  }

void sendData(){

    String incomingMsg;
    digitalWrite(start_uart_comm,LOW);


    digitalWrite(recieve_data, HIGH);



    if(mySerial.available()>0){
    incomingMsg=String(mySerial.read())+incomingMsg;

    }


     //CLEAR SERIAL PORT
     mySerial.available();
     while(mySerial.read() >= 0);

     digitalWrite(recieve_data, LOW);




     digitalWrite(start_uart_comm,HIGH);

     //delay_millis(100);


     sendDataSoftwareSerial(String(incomingMsg)+String("-")+String(analogRead(A0)));


     digitalWrite(start_uart_comm,LOW);

     //delay_millis(100);



    }


void blinkLed(){



      stateLed=!stateLed;
      digitalWrite(pinLed,stateLed);

    }





ISR(TIMER2_OVF_vect){




  cuenta++;
    if(cuenta > 29) {

     ledState=!ledState;

      digitalWrite(pinLed,ledState);
      cuenta=0;


    }

}
