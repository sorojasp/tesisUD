  struct concentracionesSensores{
    
    float NH3;
    float CO2;
    float CH4;
    float H2S;
    float SO2;
    float temperatura;
    float humedad;
  };


boolean connectToWifiNetwork(String wifiNetworkName, String password){
  /*función para conectarse a una red wifi*/

   int n=200; // cantidad de veces que se intenta conectar a la red 
  WiFi.begin(wifiNetworkName,password);
  int i=0;// contador de veces que se intenta conectar

  Serial.println("Connecting...");
  Serial.flush();
  while (WiFi.status() != WL_CONNECTED && i<n)
  {

    //digitalWrite(GPIO2,HIGH);
    //digitalWrite(GPIO0,HIGH);
    
    delay(500);// Si NO SE ESPERA, NO SIRVE
    Serial.println("intento "+ String(i)+ " de conectarse");
    Serial.flush();
    i++;
  }

  if(WiFi.status() == WL_CONNECTED){
       Serial.println("Conectado a la red wifi");
       Serial.flush();
       Serial.print("Connected, IP address: ");
       Serial.flush();
       Serial.println(WiFi.localIP());
       Serial.flush();
       return true;
    }else{
      Serial.println("Error al conectarse a la wifi red wifi");
      Serial.flush();
      return false;
      }
 }


 boolean sendSensorData(String serverName, String endPoint, int port,  struct concentracionesSensores  cs, WiFiClient client){

     String queryString = "?Authorization="+String(cs.NH3)+"&co2="+String(cs.SO2)+"&so2="+String(cs.CO2);

     //String queryString=value;
     if (client.connect(serverName, port)) {
      Serial.println("connected to server:" + String(serverName));
      Serial.flush();
      // Make a HTTP request:
      client.println(String("POST ") +  String(endPoint) + queryString + String(" HTTP/1.1"));
      client.println("Host: " + String(serverName));
      client.println("Connection: close");
      client.println(); // end HTTP request header
      
      // send HTTP body
      client.println(queryString);

    
       Serial.println("esperando respuesta del servidor");
       Serial.flush();
       int counter=0;
       while((!client.available()) && (counter<10000)){
        delay(500);
        counter++;
        
        
         if(client.available()){
        // read an incoming byte from the server and print it to serial monitor:
          char c = client.read();
        Serial.println(String("respuesta del servidor: ")+ String(client.read()));
        Serial.flush();

         String line = client.readStringUntil('\r'); // la forma de la respuesta del servidor es "TP/1.1 200 OK"

         Serial.println(line);
         Serial.flush();
         break;
      }

      Serial.print(".");
      
        }

        // read an incoming byte from the server and print them to serial monitor:
     
       
        if(!client.connected())
        {
          // if the server's disconnected, stop the client:
          Serial.println("disconnected");
          client.stop();
         }

        return true;
     }
     else{
      return false;
      }
  
  }
