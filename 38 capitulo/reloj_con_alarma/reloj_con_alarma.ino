#include<Wire.h>    //Se incluye la librería del i2c
#include<RTClib.h>    //Se incluye la librería del reloj
RTC_DS3231 rtc;   //SSe crea un objeto del tipo "RTC_DS3231" llamado "rtc"
bool alarma = true;   //Se establece una variable booleana lllamada "alarma" que torna un valor verdarero


void setup() {

Serial.begin(9600);   //Se inicializa el monitor serie
  if(!rtc.begin()){   //Si la inicialización del rtc es incorrecta...
    Serial.println("modulo rtc no encontrado" );    //Se escribe "modulo rtc no encontrado"
    while(1);   //Y se queda estancado
  }   //Si fue exitosa
   rtc.adjust(DateTime(__DATE__,__TIME__));   //Se ajusta la fecha y la hora
}


void loop() {
  DateTime fecha =rtc.now;    //Se obtiene los datos dde fecha y hora en la variable "fecha" con la función "now"
  if( fecha.hour() == 14 &&  fecha.minute() == 30){   //Si la hora es igual a las 14:30 
      if(alarma == true){   //Y si la alarma es igual a verdadero
        Serial.println( "Alarma");    //S escribe en el monitor "Alarma"
        alarma= false;    //Y se detiene poniendola en "falso"
      }
    }
      //Se imprime la fecha en el monitor serie
Serial.print(fecha.day());
 Serial.print("/");
 Serial.print(fecha.month());
 Serial.print("/");
 Serial.print(fecha.year());
 Serial.print(" ");
 //Se imprime la hora en el monitor serie
 Serial.print(fecha.hour());
 Serial.print(":");
 Serial.print(fecha.minute());
 Serial.print(":");
 Serial.println(fecha.second());
 delay(1000);   //Durante cada segundo
 if(fecha.hour() == 2 && fecha.minute() == 0);    //Reactiva la alarma a las 2:00 horas
 alarma= true;
}
