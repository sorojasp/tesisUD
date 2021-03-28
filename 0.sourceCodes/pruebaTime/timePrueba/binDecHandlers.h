#include "decToBin.h" 



String decToBin(int num, int cantidadBits){
  /*Función que recibe un entero y devuelve un arreglo de enteros[n] donde n es la cantidad de bits*/
   
  String a;
  char bit_;

  int i=0;

  while(i<cantidadBits){
   a=a+"0";
    i++;
    }



  i=cantidadBits-1;
  while(num>0){
    if(num%2==1){
      bit_='1';
      }else{
        bit_='0';
        }
    a.setCharAt(i, bit_);   
    num=num/2;  
    i--; 
    }

    return a;
  
  }

 
    byte bin8ToByte(String binNum8 ){
    int cantidadBits=8;
    double decimal=0;
    int i=cantidadBits-1;

    int bit_;
    String bit_str;
    int expo=0;
   
    while(i>=0){
      bit_str=binNum8.charAt(i);
      if(bit_str.equals("1")){
        bit_=1;
        }else{
        bit_=0;  
          };
      
      decimal=decimal + (pow(2,expo) *  bit_);
      i--;
      expo++;
      }   
      return decToBin_SR(round(decimal));
    
  }

    
 void datosTratados(int enteroPromedio, int decimasPromedio, int enteroDesviacion,  int decimasDesviacion, String entidadMedida ){

    
      String binEP10=decToBin(enteroPromedio,10);
      String binDP7=decToBin(decimasPromedio,7);
      String binED10=decToBin(enteroDesviacion,10);
      String binED7=decToBin(decimasDesviacion,7);
      
      
      String bytes;
      
      String byte1="00000000";
      String byte2="00000000";
      String byte3="00000000";
      String byte4="00000000";
      String byte5="00000000";

      // se configura el primer byte
      int i=0;
      while(i<8){
        byte1.setCharAt(i, binEP10.charAt(i));   
        i++;
    }

    Serial.println("PrimerByte: "+byte1);

    // se configura el segundo byte

    byte2.setCharAt(0, binEP10.charAt(8));   
    byte2.setCharAt(1, binEP10.charAt(9));  

     i=2;
     while(i<8){
      byte2.setCharAt(i, binDP7.charAt(i-2));
      i++;        
    }

    Serial.println("SegundoByte: "+byte2);

    // se configura el tercer byte

     byte3.setCharAt(0, binDP7.charAt(6));  

       i=2;
     while(i<8){
      byte3.setCharAt(i+1, binED10.charAt(i));
      i++;        
    }

    Serial.println("tercerByte: "+byte3);

    // se configura el cuarto byte
     byte4.setCharAt(0, binED10.charAt(7)); 
     byte4.setCharAt(1, binED10.charAt(8)); 
     byte4.setCharAt(2, binED10.charAt(9)); 

      i=3;
     while(i<8){
      byte4.setCharAt((i), binED7.charAt(i-3));
      i++;        
    }

    
     Serial.println("cuartoByte: "+byte4);

     // se configura el Quinto byte

    
     byte5.setCharAt(0, binED7.charAt(5)); 
     byte5.setCharAt(1, binED7.charAt(6)); 

     byte5.setCharAt(2, entidadMedida.charAt(0)); 
     byte5.setCharAt(3, entidadMedida.charAt(1)); 
     byte5.setCharAt(4, entidadMedida.charAt(2)); 
     byte5.setCharAt(5, entidadMedida.charAt(3)); 

     
     
     Serial.println("quintoByte: "+byte5);

     
   
    
    }

    

 
  
