#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string.h>



boolean connectToWifiNetwork(String wifiNetworkName, String password){
  /*función para conectarse a una red wifi*/

   int n=200; // cantidad de veces que se intenta conectar a la red 
  WiFi.begin(wifiNetworkName,password);
  int i=0;// contador de veces que se intenta conectar
  while (WiFi.status() != WL_CONNECTED && i<n)
  {
    delay(500);// Si NO SE ESPERA, NO SIRVE
    i++;
  }

  if(WiFi.status() == WL_CONNECTED){
 
       return true;
    }else{
      return false;
      }
 }


 
 boolean sendSensorData(String serverName, String endPoint, int port,  String dataSensors, WiFiClient client){
        
 
  
  //tutorial del Json en arduino https://randomnerdtutorials.com/decoding-and-encoding-json-with-arduino-or-esp8266/

     String queryString = "?Authorization="+String("holi")+String(dataSensors);

     //serverName="https://web-production-3b82d.up.railway.app/";/***/
     //port=443;/***/

     //String queryString=value;
     if (client.connect(serverName, port)) {

      // Make a HTTP request:
      client.println(String("POST ") +  String(endPoint) + queryString + String(" HTTP/1.1"));
      client.println("Host: " + String(serverName));
      client.println("Content-Type: application/json");
      client.println("Connection: close");
 
      client.println(); // end HTTP request header

            
        
    
       int counter=0;
       while((!client.available()) && (counter<10000)){
        delay(500);
        counter++;
        
        
         if(client.available()){
        // read an incoming byte from the server and print it to serial monitor:
          char c = client.read();


         String line = client.readStringUntil('\r'); // la forma de la respuesta del servidor es "TP/1.1 200 OK"

         break;
      }

 
      
        }

        // read an incoming byte from the server and print them to serial monitor:
     
       
        if(!client.connected())
        {
          // if the server's disconnected, stop the client:
    
          client.stop();
         }

        return true;
     }
     else{
      return false;
      }
  
  }
