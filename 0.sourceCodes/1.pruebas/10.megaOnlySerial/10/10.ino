void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial1.available()>0){
      String incomingString =Serial1.readStringUntil('@');
      Serial1_flush_buffer();

      Serial.println(incomingString);
      Serial.flush();
    
    }

}

void Serial1_flush_buffer(){
  Serial1.available();
  while(Serial.read() >= 0); // do nothing
}
