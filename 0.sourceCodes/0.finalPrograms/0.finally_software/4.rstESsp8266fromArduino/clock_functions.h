 int getDaysInMonth(Anio anio, int month_int){

     if(month_int==1){

          return anio.Jan;

    }else if(month_int==2){
      return anio.Feb;


      }else if(month_int==3){
        return anio.Mar;


      }else if(month_int==4){
        return anio.Apr;


      }else if(month_int==5){
        return anio.May;


      }else if(month_int==6){
        return anio.Jun;


      }else if(month_int==7){
        return anio.Jul;


      }else if(month_int==8){
        return anio.Aug;


      }else if(month_int==9){
        return anio.Sep;


      }else if(month_int==10){
        return anio.Oct;


      }else if(month_int==11){
        return anio.Nov;


      }else if(month_int==12){
        return anio.Dec;


      }



      }

  int getMonthInt(String month_str){

   if(month_str=="Jan"){

    return 1;

    }else if(month_str=="Feb"){
      return 2;


      }else if(month_str=="Mar"){
        return 3;


      }else if(month_str=="Apr"){
        return 4;


      }else if(month_str=="May"){
        return 5;


      }else if(month_str=="Jun"){
        return 6;


      }else if(month_str=="Jul"){
        return 7;


      }else if(month_str=="Aug"){
        return 8;


      }else if(month_str=="Sep"){
        return 9;


      }else if(month_str=="Oct"){
        return 10;


      }else if(month_str=="Nov"){
        return 11;


      }else if(month_str=="Dec"){
        return 12;


      }


    }


  Date getDate(){
    Date date_now;

    String date = String(__DATE__);


    int n = date.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, date.c_str());
       char *token = strtok(char_array, " "); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            date_now.mes=getMonthInt(String(token));

            }else if(i==1){
              date_now.dia=String(token).toInt();

              }else if(i==2){
              date_now.anio=String(token).toInt();

              }
               token = strtok(NULL, " ");
              i++;

              }

        return date_now;


    }

  Time getTime_(){
    Time time_now;

    String time_str = String(__TIME__);
    int n = time_str.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, time_str.c_str());
       char *token = strtok(char_array, ":"); // el separador debe ser -

        int i = 0;
        while (token != NULL) {

          if(i==0){
            time_now.horas=String(token).toInt();

            }else if(i==1){
              time_now.minutos=String(token).toInt();

              }else if(i==2){
              time_now.segundos=String(token).toInt();

              }
               token = strtok(NULL, " ");
              i++;

              }

              time_now.segundos=time_str.substring(6, 8).toInt();

        return time_now;

    }

    DateTime handleClock(Date date, Time time, int increment){

    Anio anios[2]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
    int anios_index=0;
    // This variable have to declare global to keep count the years

     time.segundos=time.segundos+increment;
      if(time.segundos>59){
        time.segundos=0;
        time.minutos=time.minutos+1;

        if(time.minutos>59){
          time.minutos=0;
          time.horas=time.horas+1;
          }

         if(time.horas==24){
          time.horas=0;
          date.dia=date.dia+1;
          }

          if(date.dia>getDaysInMonth(anios[anios_index],date.mes)){
            date.dia=1;
            date.mes=date.mes+1;
            }

            if(date.mes>12){
              date.mes=1;
              anios_index++;

              }

        }




        DateTime dateTime;
        dateTime.time=time;
        dateTime.date=date;


        return dateTime;




    }


    String getCurrentTimeStr(Date date, Time time){
     String currenTimeString= String(date.mes)+"-"+String(date.dia)+"-"+String(date.anio)+"h"+String(time.horas)+":"+String(time.minutos)+":"+String(time.segundos);

     return currenTimeString;


     }
