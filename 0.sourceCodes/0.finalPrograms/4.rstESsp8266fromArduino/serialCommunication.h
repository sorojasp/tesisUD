void Serial1_flush_buffer(){
  Serial1.available();
  while(Serial1.read() >= 0); // do nothing
}


String waitForData(unsigned long time_wait){

    // first have to clear of serial buffer of input
    Serial1_flush_buffer();

    unsigned long count_time = 0;
    unsigned long A = 0;
    unsigned long B = 0;

    while(Serial1.available()==0 && count_time<time_wait){
      A=millis();
      B=millis();
      count_time=count_time+(B-A);
      }

      if(count_time<time_wait){
          String incomingString =Serial1.readStringUntil('@');
          Serial1_flush_buffer();
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

  int counter=0;
  boolean dataConfirm=false;


  while(counter<times&&!dataConfirm){

    Serial1.println(dataToSend+"@");
    Serial1.flush();

    String incomingString = waitForData(time_wait);
       /*
       Serial.println("incomingString: "+incomingString+"**"); //just for test
       Serial.flush();//just for test
       
       Serial.println("length incoming: "+String(incomingString.length()));//just for test
       Serial.flush();//just for test

       Serial.println("dataToSend: "+dataToSend+"**"); //just for test
       Serial.flush();//just for test
       
       Serial.println("length dataToSend: "+String(dataToSend.length()));//just for test
       Serial.flush();//just for test

       boolean test= incomingString==dataToSend;//just for test

       if(incomingString!=dataToSend){//just for test

        Serial.println("**No son iguales =(");//just for test
        
        }else{//just for test
          Serial.println("Son iguales =)");//just for test
          
          }//just for test

         */

       


 
      
      delay(200);// with out this delay, not works......
      if(incomingString==dataToSend){
        Serial1.println("finish@");
        Serial1.flush();
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
   *@period = Time that wait for response.. in each time
   */

  boolean finish=false;
  while(!finish){// maybe i can change the finish by a times control...

  String dataRecieve=waitForData(time_wait);

  //Serial.println("wait for data: "+dataRecieve);
  //Serial.flush();

  if(dataRecieve=="false@"){
    return "false@";
    }else{

      delay(100);
      Serial1.println(dataRecieve+"@");
      Serial1.flush();
      String confirm=waitForData(time_wait);
      if(confirm=="finish"){
        finish=true;
        return dataRecieve;
        }else{
          return "false@";
          }
      
      }
  
  }
}
