  #include <string.h> 
  String incomingString;
  #define input 4
  #define rstESP8266 8

   int counter=0;


  struct Data{

  String action;
  String state;
  String value;
 
  };

   Data d;

  
void setup() {
  // put your setup code here, to run once:

  pinMode(input, INPUT);
  pinMode(rstESP8266, OUTPUT);

  
  Serial.end();
 
}

void loop() {

  
  
  
  //if(digitalRead(input)==false){


        Serial.end();
         resetESP826601();

        
        Serial.begin(9600);
        delay(100);

       
    
       //Serial.println("sendData-end-"+String("?")+String("NH3=")+String(96.3)+String("&CO2=")+String(20.3)+String("&CH4=")+String(85.3)+String("&H2S=")+String(30.3));
       //Serial.flush();

        Serial.println("sendData-busy-"+String("?")+String("NH3=")+String(96.3)+String("&CO2=")+String(20.3));
       Serial.flush();

       
       while(!(d.action.equals("recieveData") && d.state.equals("busy"))){

               if(Serial.available()){
            
            incomingString = Serial.readStringUntil('\r\n');
            d=readIncomingMsg(incomingString);
            }
        }


        Serial.println("sendData-start-sucess");
        Serial.flush();
   
       


        while(!(d.action.equals("recieveData") && d.state.equals("end"))){
          
          if(Serial.available()){
            
            incomingString = Serial.readStringUntil('\r\n');
            d=readIncomingMsg(incomingString);
      
            }
            
            }


             /*
              Serial.end();
              Serial.begin(9600);
               delay(100);

               resetESP826601();

              Serial.println("sendData-end-"+String("?")+String("NH3=")+String(89.3)+String("&CO2=")+String(78.3)+String("&CH4=")+String(23.3)+String("&H2S=")+String(85.33));
              Serial.flush();
              */
            
            Serial.println("supera el while....");
            Serial.flush();


            
            
           
            
            //}

  }


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

    void resetESP826601(){

          digitalWrite(rstESP8266, HIGH);
          delay(20);
          digitalWrite(rstESP8266, LOW);
          delay(100);
      }
