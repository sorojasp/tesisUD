String incomingString; // for incoming serial data
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  }



void loop() {
  // put your main code here, to run repeatedly:

 if (Serial.available()) {
    // read the incoming byte:
    incomingString = Serial.readStringUntil('\r\n');

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingString);
  }

 

}
