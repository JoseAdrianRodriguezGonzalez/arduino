#include<Wire.h>    //Se incliuye la libería de la comunciación I2C
#include<RTClib.h>    //Se incluye la libería del reloj
RTC_DS3231 rtc;   //Se crea un objeto del tipo "RTC_DS3231" llamado "rtc"
bool evento_inicio = true;    //Se crea una variable booleana llamada "evento_inicio" considerada como "verdadera"
bool evento_fin = true;   //Se crea una variable booleana llamada "evento_fin" considerada como "verdadera"

#define RELE 3    //Se define una constante llamada "rele" en el pin 3"
void setup() {

Serial.begin(9600);   //Se inicia la comunciación del monitor serie
pinMode(RELE, OUTPUT);    //Se declara como salida al relé
  if(!rtc.begin()){   //Si la inicalización del rtc fue incorrecta
    Serial.println("modulo rtc no encontrado" );    //Se escribe en el monitor serie "modulo rtc no encontrado" 
    while(1);   //Y se queda estancado
  }
   rtc.adjust(DateTime(__DATE__,__TIME__));   //Rtc configura la fecha y la hora
}


void loop() {
  DateTime fecha =rtc.now;    //Fecha consigue todos los datos de la fecha y hora con la función "now"
  if( fecha.hour() == 14 &&  fecha.minute() == 30){   //Si son las 14:30
      if(evento_inicio == true){    //Y si el evento:inicio es verdadero
        digitalWrite(RELE, HIGH); //Se activa el relé y se mantendará encendido hasta las 15:30
        Serial.println( "Rele encendido");    //Se escribe en el monitor serie "Rele encendido"
        evento_inicio= false;   //Se desactiva el evento 
      }
    }
     if( fecha.hour() ==15 &&  fecha.minute() == 30){   //Si son las 15:30 horas
      if(evento_fin == true){     //Si evento_fin es igual a verdadero
        digitalWrite(RELE, LOW);    //El relé se apaga
        Serial.println( "Rele apagado");    //Y se escribe en el monitor serie que está apagado
        evento_inicio= false;   //Y se desactiva el evento_fin
      }
    }
    //Se escribe en el monitor serie la fecha
Serial.print(fecha.day());
 Serial.print("/");
 Serial.print(fecha.month());
 Serial.print("/");
 Serial.print(fecha.year());
 Serial.print(" ");
 //Se escribe la hora en el monitor serie
 Serial.print(fecha.hour());
 Serial.print(":");
 Serial.print(fecha.minute());
 Serial.print(":");
 Serial.println(fecha.second());
 delay(1000);
 if(fecha.hour() == 2 && fecha.minute() == 0);    //A las 2:00 horas se reactivan
 evento_inicio= true;
 evento_fin= true;
}
