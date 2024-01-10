//SE AGREGA LIBRERÍAS DE LCD; 
//SE AGREGA LIBRERÍAS PARA RTC
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);
#include <ThreeWire.h>  
#include <RtcDS1302.h>
//SE CREA Y CONFIGURA OBJETO PARA MANEJAR RTC
ThreeWire myWire(11,10,12); //PINES IO, SCLK, CE -> DE RTC DS1302
RtcDS1302<ThreeWire> Rtc(myWire);
bool alarma= true;    //Se configura la alarma
void setup () {   
  // SE INICAR MONITOR SERIE E IMPRIME FECHA Y HORA
  Serial.begin
    Rtc.Begin();// SE INICIALIZA RTC
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);//SE CONFIGURA FECHA Y HORA ACTUAL
     Wire.begin();    //Se inicia la comunicación i2c
  lcd.begin(16, 2); //Se inica la pantalla lcd
  lcd.clear();    //Se limpia la pantalla
  lcd.setBacklight(HIGH);   //Se enciende el led trasero
}

void loop () {
    RtcDateTime now = Rtc.GetDateTime();    //Se consigue la fecha y hora
    printDateTime(now);   //Se compila la fecha y hora de ahora
    delay(1000);    //Cada segundo
   
}

#define countof(a) (sizeof(a) / sizeof(a[0])) //Se definene constantes

//FUNCION PARA IMPRIMIR FECHA Y HORA CON FORMATO ADECUADO
void printDateTime(const RtcDateTime& dt){
    char datestring[20];
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),//SE CONFURA FORMATO DE FECHA Y HORA
            
            dt.Day(),
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    //SE IMPRIME LA FECHA Y HORA EN LCD
  lcd.setCursor(0,0);
   lcd.print("DATE  ");
      lcd.print(dt.Day());
    lcd.print("/");
     lcd.print(dt.Month());
    lcd.print("/");
    lcd.print(dt.Year());
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("TIME  ");
     lcd.print(dt.Hour());
     lcd.print(":");
     lcd.print(dt.Minute());
     lcd.print(":");
    lcd.print(dt.Second());
  //SE IMPRIME EN MONITOR SERIE
  //Se crea una alarma a las 9:54
   if( dt.Hour() == 9 &&  dt.Minute() == 54){
      if(alarma == true){
        Serial.println( "Alarma");
        alarma= false;
      }
      if(dt.Hour() == 2 && dt.Minute() == 0);    //Reactiva la alarma a las 2:00 horas
 alarma= true;
    }
}
