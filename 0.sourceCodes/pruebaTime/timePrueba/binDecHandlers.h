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

    
 void datosTratados(int enteroPromedio, int decimasPromedio, int enteroDesviacion,  int decimasDesviacion, int *entidadMedida ){

    
    
      String binEP10=decToBin(enteroPromedio,10);
      String binDP7=decToBin(decimasPromedio,7);
      String binED10=decToBin(enteroDesviacion,10);
      String binED7=decToBin(decimasDesviacion,10);

 }
  
/*
 int byte1[8]={0,0,0,0,0,0,0,0};
  int byte2[8]={0,0,0,0,0,0,0,0};
  int byte3[8]={0,0,0,0,0,0,0,0};
  int byte4[8]={0,0,0,0,0,0,0,0};
  int byte5[8]={0,0,0,0,0,0,0,0};
  
  static byte bytes[5];
  

  binEP10=decToBin_10(int(enteroPromedio));
  binDP7=decToBin_7(decimasPromedio);
  binED10=decToBin_10(enteroDesviacion);
  binDD7=decToBin_7(decimasDesviacion);

  

  


  // se configura el primer byte
  int i=0;
  int pointer=2;
  while(i<8){
    byte1[i]=binEP10[pointer];
    i++;
    pointer++;
    }

  // se configura el segundo byte
  byte2[0]=binEP10[8];
  byte2[1]=binEP10[9];

  i=2;
  while(i<8){
    byte2[i]=binDP7[pointer];
    i++;
    pointer++;    
    }

  // se configura el tercer byte
  byte3[0]=binDP7[6];

  i=1;
  pointer=0;
  while(i<8){
    byte3[i]=binED10[pointer];
    i++;
    pointer++;
    }

   // se configura el cuarto byte
   byte4[0]=binED10[7];
   byte4[1]=binED10[8];
   byte4[2]=binED10[9];

   i=3;
   pointer=0;

   while(i<8){
    byte4[i]=binDD7[pointer];
    i++;
    pointer++;
    }

    // se configura el quinto byte
    byte5[0]=binDD7[5];
    byte5[1]=binDD7[6];

    byte5[2]=entidadMedida[0];
    byte5[3]=entidadMedida[1];
    byte5[4]=entidadMedida[2];
    byte5[5]=entidadMedida[3];
    byte5[6]=0;
    byte5[7]=0;

    //**Finalmente se configura el arreglo de bytes
    
    bytes[0]=bin8ToByte(byte1);
    bytes[1]=bin8ToByte(byte2);
    bytes[2]=bin8ToByte(byte3);
    bytes[3]=bin8ToByte(byte4);
    bytes[4]=bin8ToByte(byte5);


    return bytes;
    
    
}




*/
