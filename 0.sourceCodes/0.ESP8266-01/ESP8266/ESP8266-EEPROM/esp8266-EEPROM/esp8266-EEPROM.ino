#include <ESP8266WiFi.h> //Timer1 library no funciona en el ESP8266, pero ESP8266WiFi.h tiene el objeto timer1_  
#include <string.h> 
#include <EEPROM.h>

// tutorial de http://www.esp8266learning.com/read-and-write-to-the-eeprom-on-the-esp8266.php
int addr = 0;

void setup() {
  // put your setup code here, to run once:
EEPROM.begin(512);  //Initialize EEPROM
 
  // write to EEPROM.
  EEPROM.write(addr, 'a');    
  addr++;                      //Increment address
  EEPROM.write(addr, 'b');   
  addr++;                      //Increment address
  EEPROM.write(addr, 'C');    
 
  //Write string to eeprom
  String sample = "?NH3=200.38&CO2=10000.38&CH4=100000.99&H2S=100.25&SO2=236.88&T=200.38&H=200.388";
  for(int i=0;i<sample.length();i++)
  {
    EEPROM.write(0x0F+i, sample[i]); //Write one by one with starting address of 0x0F
    // funciona hasta 15 porque esta en hexadecimal....hay que leer de las EEPROM del ESP8266
  }
  EEPROM.commit();    //Store data to EEPROM
}

void loop() {
  // put your main code here, to run repeatedly:
 
  delay(2000);
  EEPROM.begin(512);  //Initialize EEPROM
  Serial.begin(9600); 
  Serial.println("empieza");
  Serial.flush();
  Serial.println(char(EEPROM.read(addr)));
  Serial.flush();
  addr++;                      //Increment address
  Serial.println(char(EEPROM.read(addr)));
  Serial.flush();
  addr++;                      //Increment address
  Serial.println(char(EEPROM.read(addr)));
  Serial.flush();
 
  //Read string from eeprom (testing eeprom)
  String strText;   
  for(int i=0;i<14;i++) 
  {
    strText = strText + char(EEPROM.read(0x0F+i)); //Read one by one with starting address of 0x0F    
  }  
 
  Serial.print(strText);  //Print the text
  Serial.flush();


}
