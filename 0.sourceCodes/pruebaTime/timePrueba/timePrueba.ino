

#include <Time.h>
#include <TimeLib.h>
#include "decToBin.h" 
// Declaramos la variable del tipo time_t

 time_t fecha;
void setup() {
  Serial.begin(9600);

}




 
void loop() {
  
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
//String(decToByn10(456))
//decToByn7(99);
//decToByn10(186);
  int a[7]={1,1,0,0,1,0,1};
   Serial.println(sizeof(decToBin(byn7ToDec(a))));
   Serial.println(byn7ToDec(a));

}

double datosTratados(int enteroPromedio, int decimasPromedio, int enteroDesviacion,  int decimasDesviacion ){

  return 2.6;
 
   
}

int decToByn10(int num ){
  int cantidadBits=10;

    int a[cantidadBits]={0,0,0,0,0,0,0,0,0,0};
  int i;
  
  for(i=cantidadBits-1;num>0;i--){
    a[i]=num%2;    
    num=num/2;    
    
    }

  for(i=0;i<cantidadBits;i++){
    Serial.print(a[i]);
    }
    
    Serial.println("");
    return a;
  
  }

  int decToByn7(int num ){

    int cantidadBits=7;

    int a[cantidadBits]={0,0,0,0,0,0,0,0,0,0};
  int i;
  
  for(i=cantidadBits-1;num>0;i--){
    a[i]=num%2;    
    num=num/2;    
    
    }

  for(i=0;i<cantidadBits;i++){
    Serial.print(a[i]);
    }
    
    Serial.println("");
    return a;
  
  }


  byte byn7ToDec(int* bynNum7 ){
    int cantidadBits=7;
    double decimal=0;
    int i=6;
    int expo=0;


    while(i>=0){
      decimal=decimal + (pow(2,expo) *  bynNum7[i]);
      expo++;
      i--;
      }

     
      int intDecimal = (int)(decimal) +1;
      
    
      Serial.println(decToBin(intDecimal));
      return decToBin(intDecimal);
    
  }

  
  byte byn10ToDec(int bynNum10 ){
      return 12;
  }
