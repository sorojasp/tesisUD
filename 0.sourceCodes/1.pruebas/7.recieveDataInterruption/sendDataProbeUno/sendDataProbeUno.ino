const byte sendData=8;
int i=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sendData, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  /*
  if(digitalRead(sendData)==LOW){
    delay(200);
    sendDataSoftwareSerial(String("Stiven@"+String(i)));
    }
    i++;

    */

    delay(200);
    sendDataSoftwareSerial("Stiven@-"+String(i));
    i++;

    
  
  

}



boolean sendDataSoftwareSerial(String str){

     int str_len = str.length() + 1;
     char char_array[str_len];
     str.toCharArray(char_array, str_len);


     for(int i =0; i < strlen(char_array); i++ ) {
      char c = char_array[i];
      delay(50);
      Serial.write(c);
    }

     //clear serial buffer
        Serial.flush();
     //mySerial.available();
     //while(mySerial.read() >= 0);

     return true;

  }
