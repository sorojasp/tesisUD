
/*
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

boolean delay_millis(int period){
  /*mAKE A DELAY in milliseconds usings the millis() function
   * @period is the delay what you want in milliseconds
  */

     unsigned long time_now = 0;
     time_now = millis();

    while(millis() < time_now + period){}

    return true;



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
    delay_millis(280);
    digitalWrite(pinRST,LOW);
    //delay(100);
    delay_millis(280);
    digitalWrite(pinRST,HIGH);


  }
