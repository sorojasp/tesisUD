#include <ArduinoJson.h>
# define input 4


StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();


void setup() {

  pinMode(input, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
root["sensor"] = "gps";
root["time"] = 1351824120;
JsonArray& data = root.createNestedArray("data");
data.add(48.756080);
data.add(2.302038);
}

void loop() {

  if(digitalRead(input)==LOW){

    Serial.println("?NH3=1200.38&CO2=1661.38&CH4=3120.99&H2S=2156.25&SO2=1236.88&T=1200.38&H=200.388"+String("&d=")+String(getDateTime()));
    Serial.println(" ");
    root.printTo(Serial);
    Serial.println("Compilation date:");
    Serial.println(__DATE__);
    Serial.println("Compilation time: ");
    Serial.println(__TIME__);
    Serial.println(" ");
    
    }

  // put your main code here, to run repeatedly:

}


String getDateTime(){

 String day;
 String month;
 String year;
  
  String date = String(__DATE__);
  int n = date.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, date.c_str());
       char *token = strtok(char_array, " "); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            month=String(token);
     
            }else if(i==1){
              day=String(token);
     
              }else if(i==2){
              year=String(token);
   
              }
               token = strtok(NULL, " "); 
              i++;
         
    }

  return month+String("-")+day+String("-")+year+String("h")+String(__TIME__);
  
  }
