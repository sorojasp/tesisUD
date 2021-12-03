

  const byte GPIO2 = 2;
  const byte GPIO0 = 3;
  const byte RST = 4;
  const byte pusher=5;
  const byte led1=6;
  const byte led2=7;

void setup() {
  // put your setup code here, to run once:

  pinMode(GPIO0,OUTPUT);
  pinMode(GPIO2,OUTPUT);
  pinMode(RST,OUTPUT);
  pinMode(pusher,INPUT);

  Serial.begin(9600);

  
}

void loop() {

  if(digitalRead(pusher)==LOW){
    delay(400);
    digitalWrite(GPIO0,HIGH);
    digitalWrite(GPIO2,HIGH);
    digitalWrite(RST,HIGH);
    delay(20);
    digitalWrite(RST,LOW);
    delay(100);
    digitalWrite(RST,HIGH);

  }

  String  incomingString = Serial.readStringUntil('\r\n');
  serial_flush_buffer();

  Serial.println(incomingString);
  Serial.flush();

  

  
    }

    void serial_flush_buffer(){
              while (Serial.read() >= 0); // do nothing
              }
