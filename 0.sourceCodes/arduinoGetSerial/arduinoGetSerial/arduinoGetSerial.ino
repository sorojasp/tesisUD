void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  String  incomingString = Serial.readStringUntil('\r\n');
  serial_flush_buffer();
  Serial.println(incomingString);
  Serial.flush();

}

void serial_flush_buffer(){
              while (Serial.read() >= 0); // do nothing
              }
