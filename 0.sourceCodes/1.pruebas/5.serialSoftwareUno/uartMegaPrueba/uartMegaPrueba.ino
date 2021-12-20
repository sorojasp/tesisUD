const byte start_uart_comm = 4;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(start_uart_comm, INPUT);

}

void loop() {

  if(digitalRead(start_uart_comm)==HIGH){

    while(Serial.available()==0){}

    String incomingString =Serial.readStringUntil('@');
    Serial.available();
    while(Serial.read() >= 0);

    Serial.write(incomingString.c_str());
    Serial.write('\n');
    
    }

 

}
