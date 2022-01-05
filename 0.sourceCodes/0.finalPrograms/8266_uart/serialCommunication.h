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
