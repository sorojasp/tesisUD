

#include <Time.h>
#include <TimeLib.h>

#include "binDecHandlers.h"
#include "probeDecToBin.h"


// Declaramos la variable del tipo time_t

#define input 4
#define led 5
 time_t fecha;
void setup() {
  Serial.begin(9600);

  pinMode(input,INPUT);
  pinMode(led,OUTPUT);

}




 
void loop() {

  digitalWrite(led,HIGH);

  //if(digitalRead(input)==LOW){
  while(true){
    digitalWrite(led,LOW);
  /*
   // Establecemos la fecha
  setTime(12, 32, 0, 13, 12, 2020);
 
  // Obtenemos la fecha actual
  fecha = now();
 

  //Serial.println(fecha);
  /*
   from datetime import datetime
   print(datetime.fromtimestamp(fecha))
   Para python, y se obtiene la fecha
  */
  
  //Serial.println(sizeof(fecha));
  //Serial.println(2000,HEX);
  
  
  
  byte n = byte(1023);

  int entidad[4];
  entidad[0]=1;entidad[1]=1;entidad[2]=1;entidad[3]=1;

    
    int *data;
    int *data2;
    int *data3;
    byte *data_F;



    
    //data[0],data[1],data[2],data[3],data[4]= datosTratados(892,99,141,82,entidad);
    //data = datosTratados(892,99,141,82,entidad);

    //int suma = data[0]+data[1]+data[2]+data[3]+data[4];
    //Serial.println("Suma: "+String(suma));

    //data=decToBin_10(int(80));
    

    //data_F = datosTratados(int(224),99,20,41,entidad);

      int i=0;



 
    String pruebaBin="11000011";
     Serial.println(bin8ToByte(pruebaBin));
     String str="45";
     int str_int= str.toInt();
     Serial.println(str_int+100);
     
int countProbe=0;

while(countProbe<4){

      Serial.println("num"+String(countProbe)+String(": ")+String(decToBin(countProbe,8)));
      Serial.println("num"+String(countProbe)+String(": ")+String(decToBin(countProbe,10)));
      countProbe++;
    
  }

  byte byte_po = 255;
  Serial.println(byte_po);


  String prueba_stri="24771";
  Serial.println("peso:"+String(sizeof(prueba_stri)));
   
 

    

        
}
}
