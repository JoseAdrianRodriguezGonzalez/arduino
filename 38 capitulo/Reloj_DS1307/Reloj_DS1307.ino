// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#define RELE 2
RTC_DS1307 rtc;


char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
unsigned long tiempoAnterior;
bool alarma = true;
int=estado=0;
void setup () {
  Serial.begin(57600);
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif
pinMode(RELE,OUTPUT);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop () {
  
    DateTime fecha = rtc.now();
    if( fecha.hour() == 1 &&  fecha.minute() == 30){   //Si la hora es igual a las 14:30 
      if(alarma == true){   //Y si la alarma es igual a verdadero
        Serial.println( "Alarma");    //S escribe en el monitor "Alarma"
   digitalWrite(RELE, HIGH);
   delay(5000);
   digitalWrite(RELE, LOW);
 }
        alarma= false;    //Y se detiene poniendola en "falso"
      }
    if(fecha.hour()>0 && fecha.hour()<11){    //Si son entre las 0 horas a las 11 horas
      Serial.println("¡Buenos días!");      //Se escribe un mensajes de "¡buenos días!"
    }
     else{
      if(fecha.hour() >=12 && fecha.hour()<=19){ //Si son entre las 12 horas a las 19 horas
        Serial.println("¡Buenas tardes!"); //Se escribe un mensajes de "¡Buenas tardes!"
      }
     }
    Serial.print(fecha.year(), DEC);  //Se escribe el año
    Serial.print('/');
    Serial.print(fecha.month(), DEC);   //Se escribe el mes
    Serial.print('/');
    Serial.print(fecha.day(), DEC);   //Se escribe el día
    Serial.print(" (");
    Serial.print(daysOfTheWeek[fecha.dayOfTheWeek()]);    //
    Serial.print(") ");
    Serial.print(fecha.hour(), DEC);
    Serial.print(':');
    Serial.print(fecha.minute(), DEC);
    Serial.print(':');
    Serial.print(fecha.second(), DEC);
    Serial.println();

    Serial.println();
    delay(1000);
    
    
    if( fecha.hour() == 2 &&  fecha.minute() == 30){   //Si la hora es igual a las 14:30 
      if(alarma == true){   //Y si la alarma es igual a verdadero
      }
    }
   
  
}
