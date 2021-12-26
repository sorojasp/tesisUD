//timer0 will interrupt at 2kHz

volatile byte ledState = LOW;
volatile unsigned int cuenta = 0;

int pinLed=13;
int pulser=2;
int cable=3;

void setup() {

  pinMode(pinLed, OUTPUT);
  pinMode(pulser,INPUT);
  pinMode(cable,INPUT);
  
  

   SREG = (SREG & 0b01111111); //Desabilitar interrupciones

    TIMSK2 = TIMSK2|0b00000001; //Habilita la interrupcion por desbordamiento
  TCCR2B = 0b00000111; //Configura preescala para que FT2 sea de 7812.5Hz

   SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones


 


}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(pulser)==LOW){
     TIMSK2 = TIMSK2&0b11111110;
    }

    
  if(digitalRead(cable)==LOW){
  
      TIMSK2 = TIMSK2|0b00000001;
     
     
      
      
      
     
    }


  

}


ISR(TIMER2_OVF_vect){

  cuenta++;
    if(cuenta > 29) {

     ledState=!ledState;

      digitalWrite(pinLed,ledState);
      cuenta=0;
                 

    }
 
}
