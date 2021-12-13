/*
struct Data{

  String action;
  String state;
  String value;

  };

Data readIncomingMsg(String incomingString){
    String action;
    String value;
    String state;

    Data d = {"","",""};



    int n = incomingString.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, incomingString.c_str());
       char *token = strtok(char_array, "-"); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            action=String(token);
            Serial.println(String("a:") + String(action));
            Serial.flush();
            }else if(i==1){
              state=String(token);
            Serial.println(String("s:") + String(state) );
            Serial.flush();
              }else if(i==2){
              value=String(token);
            Serial.println(String("v:") + String(value) );
            Serial.flush();
              }
               token = strtok(NULL, "-");
              i++;

    }

    d.action=action;
    d.value=value;
    d.state=state;

    return d;

    }
*/


boolean delay_millis(unsigned long delayInMillis){
  /*
   * Esta funcíon presenta un margen de error de +entre 20% para valores menores a 1000UL y de un 11% para valores 
   * mayores a 10000UL
  
  */
  unsigned long previousTime =0;
  unsigned long currentTime =0;
  unsigned long totalTime=0;
  unsigned long timeLapse=0;
  unsigned long error=2UL;
  boolean continueInCicle=true;
  delayInMillis=delayInMillis/error;
  

  while(continueInCicle){
    previousTime=millis();
     if (totalTime>= delayInMillis){
      continueInCicle=false;
      totalTime=0;
      return true;
      }

       currentTime=millis();
       timeLapse=currentTime-previousTime;
       totalTime=totalTime+timeLapse;
    
    }
    return false;
  
  
  } 

void serial_flush_buffer(){
  Serial1.available();
  while(Serial1.read() >= 0); // do nothing
}
void sendJunk(){
  Serial1.write("junk");
  Serial1.flush();
  while(Serial1.available()==0){};
  String incomingString =Serial.readStringUntil('@');
  serial_flush_buffer();
}

boolean recieveJunk(unsigned long maxTimeWait){
  unsigned long previousTime =0;
  unsigned long currentTime =0;
  unsigned long totalTime=0;
  unsigned long timeLapse=0;
  unsigned long error=4;
  maxTimeWait=maxTimeWait/error;

  
  
  while(Serial.available()==0 && totalTime<maxTimeWait){
       previousTime=millis();
       currentTime=millis();
       timeLapse=currentTime-previousTime;
       totalTime=totalTime+timeLapse;
    };

    if(totalTime<maxTimeWait){
      String incomingString =Serial.readStringUntil('@');
      serial_flush_buffer();
      return true;
      }else{
       return false;
        }
  
}

boolean sendData(int times, String dataToSend){
int counter=0;
boolean dataConfirm=false;
  while(counter<times&&!dataConfirm){
    
    Serial1.write(String(dataToSend+"@").c_str());
    Serial1.flush();
    while(Serial1.available()==0){};
    String incomingString =Serial1.readStringUntil('@');
    serial_flush_buffer();
    if(incomingString==dataToSend){
      Serial1.write("finish@");
      Serial1.flush();
      return true;
    }
    counter++;
  }
  return false;
}

String recieveData(){
  boolean finish=false;
  while(!finish){
  while(Serial1.available()==0){};

  //recieve data
  String dataRecieve =Serial1.readStringUntil('@');
  serial_flush_buffer();

  // send data to confirm
  Serial1.write(dataRecieve.c_str());
  Serial1.flush();
  //wait for finish data
  while(Serial1.available()==0){};
  String incomingString =Serial1.readStringUntil('@');
  serial_flush_buffer();

  if(incomingString=="finish"){
    finish=true;
    return dataRecieve;
  }else{
    return "false@";
    }

  }
}

String getDateTime(){

 String day;
 String month;
 String year;

  String date = String(__DATE__);
  int n = date.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, date.c_str());
       char *token = strtok(char_array, " "); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            month=String(token);

            }else if(i==1){
              day=String(token);

              }else if(i==2){
              year=String(token);

              }
               token = strtok(NULL, " ");
              i++;

    }

  return month+String("-")+day+String("-")+year+String("h")+String(__TIME__);

  }


 void resetESP8266(byte pinRST, byte GPIO0, byte GPIO2){
    digitalWrite(GPIO0,HIGH);
    digitalWrite(GPIO2,HIGH);
    digitalWrite(pinRST,HIGH);
    //delay(20);
    while(!(delay_millis(280UL)==true)){}
    digitalWrite(pinRST,LOW);
    //delay(100);
    while(!(delay_millis(280UL)==true)){}
    digitalWrite(pinRST,HIGH);
  
  
  }
