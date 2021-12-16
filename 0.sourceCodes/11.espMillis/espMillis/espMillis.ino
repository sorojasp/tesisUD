#include <ESP8266HTTPClient.h>
#include <string.h>
#include <ArduinoJson.h>
#include "functions.h"

int GPIO2=2;
int GPIO0=0;
const char* msg;


void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO2, OUTPUT);
  pinMode(GPIO0, INPUT);


}

void loop() {
  digitalWrite(GPIO2, LOW);
  delay_millis(250);// this value con not be less than 200
  digitalWrite(GPIO2, HIGH);
  delay_millis(250);

}
