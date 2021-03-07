
/*
  Bloque de definición de puertos..se nombran los puertos por la función que desarrollarán
*/
#include <TimerOne.h>
#include <EEPROM.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#define led 2
#define input 4
#define alertaCH4 8
boolean valorPuerto4;
boolean guardarEEPROM = false;
int i = 0;
int valorEEPROM;
const int MQ4 = A0; // Define el pin analogico del MQ4   *** PARA TRABAJAR CON LOS PINES ANALÓGICOS PRIMERO SE DEFINE EL PIN
volatile long int Time = 0; //variable apar almacenar el tiempo de la interrupción

int valorPuertoSerie = "";
int incomingByte = 0; // for incoming serial data

void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT);
  pinMode(input, INPUT);
  pinMode(alertaCH4, OUTPUT);


  //configuración de puerto serial
  Serial.begin(9600);
  //Timer1.initialize(10009000);// valor para 5 horas= 18000000000;
  //Timer1.attachInterrupt(Temporizador);//se coloca el nombra de la función que se ejecutará cada intervalo de tiempo establecido



}

void loop() {

  if(digitalRead(input)==HIGH){

    Serial.println(digitalRead(input));
    Serial.flush();

    digitalWrite(alertaCH4, HIGH);
    
    }else{
      
      digitalWrite(alertaCH4, LOW);
      
     Serial.println(digitalRead(input));
     Serial.flush();


      }

  

  if (Serial.available()) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.flush();
    Serial.println(incomingByte);
    Serial.flush();
  }






}


void Temporizador(void) {

  Time++;
  Serial.println("valor Interrupcion: ");
  Serial.println(Time);


}

void copyMain() {
  int concentracion_CH4 = analogRead(MQ4);

  if (concentracion_CH4 <= 138) {

    Serial.println("Actualiza el valor de la memoria");

    EEPROM.write(500, 148);


  }


  Serial.println("valor de la memoría:");
  Serial.println(EEPROM.get(500, valorEEPROM));





  guardarEEPROM = true;

  if (guardarEEPROM) {

    guardarEEPROM = false;

    char valorGuardar = "S";

    EEPROM.put(500, 222);

  }



  // put your main code here, to run repeatedly:






  Serial.println("valor:");
  Serial.println(concentracion_CH4);

  Serial.println("mem_disp");


  if (concentracion_CH4 >= 512) {
    digitalWrite(alertaCH4, true);
  } else {
    digitalWrite(alertaCH4, false);
  }

  valorPuerto4 = digitalRead(4);
  if (valorPuerto4 == 1) {
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
  } else {
    digitalWrite(led, HIGH);
  }





}
