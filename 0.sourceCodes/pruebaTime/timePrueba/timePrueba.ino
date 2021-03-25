

#include <Time.h>
#include <TimeLib.h>
 
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
 

  Serial.println(fecha);
  /*
   from datetime import datetime
   print(datetime.fromtimestamp(fecha))
   Para python, y se obtiene la fecha
  */
  Serial.println(sizeof(fecha));
  Serial.println(fecha,HEX);
  byte n = 0b10011001;
  byte probe = (byte) "0b11111111";
  Serial.println(probe);
}
