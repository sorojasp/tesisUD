void Serial1_flush_buffer(){
  Serial1.available();
  while(Serial1.read() >= 0); // do nothing
}

boolean sendJunk(int period){

  /**
   * Function to send junk, the period is the  maximun time that the function wait for response,
   * is in this lapse of time not recieve confirmation, the function will return false. And if the function recieve
   * confirmation before that the period is finish, then return true
   *
   *@period = time that wait for response
   */

  Serial1.write("junk@");
  Serial1.flush();

  unsigned long time_now = 0;
  time_now = millis();

  while(Serial1.available()==0 && millis() < time_now + period){};

  if(millis() < time_now + period){
    String incomingString =Serial1.readStringUntil('@');
    Serial1_flush_buffer();
    return true;

  }else{
    return false;


  }


}

boolean recieveJunk(int period){
  /**
   * Function to recieve junk, the period is the  maximun time that the function wait for response,
   * is in this lapse of time not recieve confirmation, the function will return false. And if the function recieve
   * confirmation before that the period is finish, then return true
   *
   *@period = time that wait for response
   */

  unsigned long time_now = 0;
  time_now = millis();

  while(Serial1.available()==0 && millis() < time_now + period){};

  if(millis() < time_now + period){
    String incomingString =Serial1.readStringUntil('@');
          Serial1_flush_buffer();
          return true;
    }else{
      return false;
      }
}

boolean sendData(int times, String dataToSend, int period){

    /**
   * Function to send data for Serial1 port, the idea is try to send data many @times and wait for respond usign @period for each time to try to do it.
   *@period = Time that wait for response.. in each time
   *@times= Times that try send the data
   *@dataTosend= The data to send have be in string
   */

  int counter=0;
  boolean dataConfirm=false;


  while(counter<times&&!dataConfirm){

    Serial1.write(String(dataToSend+"@").c_str());
    Serial1.flush();

      unsigned long time_now = 0;
      time_now = millis();

    while(Serial1.available()==0 && millis() < time_now + period){};

     if(millis() < time_now + period){
      String incomingString =Serial1.readStringUntil('@');
      Serial1_flush_buffer();

      if(incomingString==dataToSend){
        Serial1.write("finish@");
        Serial1.flush();
        return true;
        }
        }else{
          //pass
          }

    counter++;
  }
  return false;
}

String recieveData(int period){

      /**
   * Function to .....recieve data, period is the maximum time to recieve data and is the same time to wait for the confirmation, is this period is over and
   * no recieve response, the function will returns 'false@' to indicate that not recieve response
   *@period = Time that wait for response.. in each time
   */

  boolean finish=false;
  while(!finish){// maybe i can change the finist by a times control...

  unsigned long time_now = 0;
  time_now = millis();
  String dataRecieve;

    //recieve data
  while(Serial1.available()==0 && millis() < time_now + period){};

  if(millis() < time_now + period){
      dataRecieve =Serial1.readStringUntil('@');
      Serial1_flush_buffer();

    }else{
      return "false@";
      }

  // send data to confirm
  Serial1.write(dataRecieve.c_str());
  Serial1.flush();

  //wait for finish data

  time_now = 0;
  time_now = millis();
  String incomingString;
  while(Serial1.available()==0 && millis() < time_now + period){};

    if(millis() < time_now + period){
      incomingString =Serial1.readStringUntil('@');
      Serial1_flush_buffer();

    }else{
      return "false@";
      }



  if(incomingString=="finish"){
    finish=true;
    return dataRecieve;
  }else{
    return "false@";
    }

  }
}
