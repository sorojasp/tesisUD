//timer0 will interrupt at 2kHz

volatile byte ledState = LOW;
volatile unsigned int cuenta = 0;
boolean toggle0 = 0;
boolean toggle2 = 0;
int pinLed=9;

void setup() {

   SREG = (SREG & 0b01111111); //Desabilitar interrupciones

    TIMSK2 = TIMSK2|0b00000001; //Habilita la interrupcion por desbordamiento
  TCCR2B = 0b00000111; //Configura preescala para que FT2 sea de 7812.5Hz

   SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones


 


}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(TIMER2_OVF_vect){

  cuenta++;
    if(cuenta > 29) {

     ledState=!ledState;

      digitalWrite(13,ledState);
      cuenta=0;
       TCNT1 = 0xC2F7;              

    }
 
}
