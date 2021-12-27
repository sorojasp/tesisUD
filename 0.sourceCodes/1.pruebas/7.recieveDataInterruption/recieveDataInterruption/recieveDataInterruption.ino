#include <SoftwareSerial.h>
#include<TimerOne.h>
SoftwareSerial mySerial(10, 3); // RX, TX


volatile boolean flag=false;
volatile String s;
void setup() {
  // put your setup code here, to run once:

 

  Serial.begin(9600);
  Serial1.begin(9600);
  mySerial.begin(9600);

   Timer1.initialize(100);
   Timer1.attachInterrupt(recieveData);


  

}

void loop() {


  if(flag==true){
    Serial.write(s.c_str());
       Serial.flush();
       s="";
       Serial.write("\n");
       Serial.flush();
  
}
  

  

}

void serial_flush_buffer(){
  mySerial.available();
  while(Serial.read() >= 0); // do nothing
}


void recieveData(){




    char myChar;
    String incomingMsg ;
    flag=false;

    if(mySerial.available()!=0){
      incomingMsg=mySerial.read();

      int suma=incomingMsg.toInt()+0;
      myChar = suma;
      s.concat(String(myChar));
      if(!(s.indexOf('@',0)!=-1)){
        s.concat("*");
        
        }

        flag=true;
      
      }
      //}

      

      

   

  
  }
