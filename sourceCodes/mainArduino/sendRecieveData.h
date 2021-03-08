/*funciones para conexión con el módulo ESP8266-01*/


boolean sendData(String action, String state, String value, String recieveWord, int tries){
  /*función destinada para envíar los datos desde el arduino al modulo ESP
  tries es el número de intentos que se hacen para tratar los datos  
  */
  

   Data d;
   String incomingString;
   int i=0;
   boolean resultComm=false;

   while(resultComm!=true && i<tries){
    Serial.println(String(action)+"-"+String(state)+"-"+String(value)+"-");
   Serial.flush();
   
        while(!(d.action.equals(recieveWord) && d.state.equals(state))){
          
          if(Serial.available()){
            incomingString = Serial.readStringUntil('\r\n');
             serial_flush_buffer();
            d=readIncomingMsg(incomingString);
            }
            }

            if(d.value==value){
              resultComm=true;
              }else{
                resultComm=false;
                
                }
    
    i++;
    };

    return resultComm;
 
   
 
  }
