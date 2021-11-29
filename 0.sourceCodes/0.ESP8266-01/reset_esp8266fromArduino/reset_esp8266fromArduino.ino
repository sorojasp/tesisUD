#define rstESP8266 8
#define input 4


  void resetESP826601(){

          digitalWrite(rstESP8266, HIGH);
          delay(20);
          digitalWrite(rstESP8266, LOW);
          delay(100);
      }

void setup() {
 pinMode(rstESP8266, OUTPUT);
  pinMode(input,INPUT);

}

void loop() {

  if(digitalRead(4)==HIGH){
    resetESP826601();
    }

    delay(2000);

}
