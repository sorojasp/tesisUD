 unsigned long previousTime =0;
  unsigned long currentTime =0;
  unsigned long timeLapse=0;
#define led 8
boolean state=true;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, state);
}



void loop() { 
  previousTime=millis();
  unsigned long delayUL = 2500UL;
  
  while(!(delay_millis(delayUL)==true)){}
  
  currentTime=millis();
  timeLapse=currentTime-previousTime;

  unsigned long porcentaje= ((timeLapse-delayUL)*100UL)/delayUL;

  Serial.write(("timeLapse: "+String(timeLapse)+"-"+"porcentaje de error:"+String(porcentaje)+"%"+"\n").c_str());

  
  state=!state;
  digitalWrite(led, state);


  
}


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
  Serial.available();
  while(Serial.read() >= 0); // do nothing
}
