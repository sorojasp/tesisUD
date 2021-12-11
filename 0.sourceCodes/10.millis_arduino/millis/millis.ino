unsigned long previousTime =0;
unsigned long currentTime=0;
unsigned long lapseTime=0;
void setup() {
  Serial.begin(9600);
}

void loop() {

  
previousTime = millis();
currentTime=millis();
lapseTime=currentTime-previousTime;



Serial.write(String("\n").c_str());
Serial.write(String(lapseTime).c_str());
Serial.flush();
}

void serial_flush_buffer(){
  Serial.available();
  while(Serial.read() >= 0); // do nothing
}
