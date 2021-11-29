//#include <ESP8266WiFi.h> //Timer1 library no funciona en el ESP8266, pero ESP8266WiFi.h tiene el objeto timer1_  



// constants won't change. Used here to 
// set pin numbers:
 int GPIO2 =  2;      // the number of the LED pin
 int GPIO0 =  0; 


void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO2, OUTPUT);
  pinMode(GPIO0, OUTPUT); 

    digitalWrite(GPIO2, HIGH);
   digitalWrite(GPIO0, HIGH);
   delay(2000);
  
  digitalWrite(GPIO2, LOW);
  digitalWrite(GPIO0, LOW);
  delay(2000);

  digitalWrite(GPIO2, LOW);
  digitalWrite(GPIO0, HIGH);
  delay(2000);

  
  digitalWrite(GPIO2, HIGH);
  digitalWrite(GPIO0, LOW);
  delay(2000);

  
  
  
}

void loop() {

  digitalWrite(GPIO2, HIGH);
  digitalWrite(GPIO0, HIGH);
  delay(500);

  
  digitalWrite(GPIO2, LOW);
  digitalWrite(GPIO0, LOW);
  delay(500);

  

  

 


  

}
