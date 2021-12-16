#include "functions.h"

const byte RST = 4;
const int delay_=200;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RST, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RST, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay_millis(delay_);                      // wait for a second
  digitalWrite(RST, LOW);    // turn the LED off by making the voltage LOW
  delay_millis(delay_);                    // wait for a second
}
