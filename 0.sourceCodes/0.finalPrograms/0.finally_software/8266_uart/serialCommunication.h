void serial_flush_buffer(){
  Serial.available();
  while(Serial.read() >= 0); // do nothing
}


String waitForData(unsigned long time_wait){

    // first have to clear of serial buffer of int
    serial_flush_buffer();

    unsigned long count_time = 0;
    unsigned long A = 0;
    unsigned long B = 0;

    while(Serial.available()==0 && count_time<time_wait){
      A=millis();
      B=millis();
      count_time=count_time+(B-A);
      }

      if(count_time<time_wait){
          String incomingString =Serial.readStringUntil('@');
          serial_flush_buffer();
          return incomingString;
        
        }else{
          return "false@";
                    
          }

 

}


boolean sendData(int times, String dataToSend, unsigned long time_wait){

    /**
   * Function to send data for Serial1 port, the idea is try to send data many @times and wait for respond usign @period for each time to try to do it.
   *@time_wait = Time that wait for response.. in each time
   *@times= Times that try send the data
   *@dataTosend= The data to send have be in string
   */
  delay(150);// delay to make sure that the entity that recieve data are ready for this
  int counter=0;
  boolean dataConfirm=false;


  while(counter<times&&!dataConfirm){

    Serial.println(dataToSend+"@");
    Serial.flush();

    String incomingString = waitForData(time_wait);

      delay(200);// with out this delay, not works......

      if(incomingString==dataToSend){
        Serial.println("finish@");
        Serial.flush();
        return true;
        }
        

    counter++;
  }
  return false;
}

String recieveData(unsigned long time_wait){

   /**
   * Function to .....recieve data, period is the maximum time to recieve data and is the same time to wait for the confirmation, is this period is over and
   * no recieve response, the function will returns 'false@' to indicate that not recieve response
   *@time_wait = Time that wait for response.. in each time
   */

  boolean finish=false;
  while(!finish){// maybe i can change the finish by a times control...

  String dataRecieve=waitForData(time_wait);


  if(dataRecieve=="false@"){
    serial_flush_buffer();
    return "false@";
    }else{

      delay(200);
      Serial.print(dataRecieve+"@");
      Serial.flush();
      String confirm=waitForData(time_wait);
      
      if(confirm=="finish"){
        finish=true;
        serial_flush_buffer();
        return dataRecieve;
        }else{
          serial_flush_buffer();
          return "false@";
          }
      
      }
  
  }
  return "";
}
