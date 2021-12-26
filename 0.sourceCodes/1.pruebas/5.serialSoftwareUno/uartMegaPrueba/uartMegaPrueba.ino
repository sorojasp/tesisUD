
const byte start_uart_comm = 4;
const byte send_data=7;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(start_uart_comm, INPUT);
  pinMode(send_data, INPUT);


}

void loop() {


  if(digitalRead(send_data)==HIGH){


  Serial1.write(83);
  Serial1.flush();

  }
  

  

 // if(digitalRead(start_uart_comm)==HIGH){

    while(Serial.available()==0){}

    String incomingString =Serial.readStringUntil('@');
    Serial.available();
    while(Serial.read() >= 0);

    Serial.write(incomingString.c_str());
    Serial.write('\n');
    
   // }

 

}
