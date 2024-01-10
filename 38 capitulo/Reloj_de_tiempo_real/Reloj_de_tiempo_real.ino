#include <Wire.h>   // Incluye la librería del i2c
#include <RTClib.h>   //Se incluye la libería del reloj
RTC_DS3231 rtc;   //Se crea un objeto del tipo "RTC_DS3231" llamado "rtc"


void setup() {
  Serial.begin(9600);   //Se inicializa el monitor serie
    if(!rtc.begin()){   //Si la inicialización es incorrecta
    Serial.println("modulo rtc no encontrado" );    //Se escribe que el "modulo rtc no encontrado"
    while(1);   //Y se queda estancado en este bucle
  }
   rtc.adjust(DateTime(__DATE__,__TIME__));   //Se ajusta la fecha y la hora
}

void loop() {
DateTime fecha =rtc.now   //Se obtienen todos los datos de fecha y horario con la función now, por lo que la fecha, es igual a todos esos datos
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
 delay(1000);   //Se hará cada 1 segundo

}
