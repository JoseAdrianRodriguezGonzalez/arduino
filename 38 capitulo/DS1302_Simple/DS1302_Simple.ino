
// CONNECTIONS:
// DS1302 CLK/SCLK --> 10
// DS1302 DAT/IO --> 11
// DS1302 RST/CE --> 12
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <ThreeWire.h>    //Se incluye la librería de ThreeWire 
#include <RtcDS1302.h>    //Se incluye la librería del reloj
#include <Wire.h>   //Se incluye la librería de 12c
#include <LiquidCrystal_I2C.h>      //Se incluye la librería de la pantallla con el i2c
LiquidCrystal_I2C lcd (0x27, 16, 2);    //Se declara un objeto del tipo LiquidCrystal_I2C llamado "lcd" con su dirección hexadecimal y su tamaño
ThreeWire myWire(11,10,12); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire); //Se declara un objeto del tipo RtcDS1302 
bool alarma=true;   //Unidad booelana, solamente puede aceptar dos paramteros, un "true" o un "false"

void setup () 
{
  Wire.begin();   //Se inicializa el i2c
  lcd.begin(16, 2);   //Se inicia la pantalla
  lcd.clear();  //  Se limpia la pantalla
  lcd.setBacklight(HIGH); //Se encianed la luz interna de la pantalla
    Serial.begin(57600);  //Se incia una comunicación a 57600 baudios
    Serial.print("compiled: "); //El monitor serie compila
    Serial.print(__DATE__);   //Se imprime en el monitor serie la fecha
    Serial.println(__TIME__);   //Se imprime en el monitor serie la hora
    Rtc.Begin();    //Se inicializa el rtc
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); //la función RtcDateTime compila la fehca y la hora
    printDateTime(compiled);  //Se compila
    Serial.println();
 if (!Rtc.IsDateTimeValid())    //Si lo contrario de rtc el tiempo es valido
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!"); //El reloj perdio la confianza de la fecha y hora
        Rtc.SetDateTime(compiled);    //Esto se compila en la función  SetDateTime
    }

    if (Rtc.GetIsWriteProtected())  //Si el conseguido de escritura está protegido
    {
        Serial.println("RTC was write protected, enabling writing now");    //El rtc fue protegidp
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) //Si la fecha actual es menor que la compilación
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)"); //El RTC es más viejo que la hora de compilación
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled)    //Si ahora es mayor que la compilación
    {
        Serial.println("RTC is newer than compile time. (this is expected)"); //El RTC es más  nuevo que el tiempo de compilado
    }
    else if (now == compiled)     //SI no si ahora es igual a compilado
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");  //RTC es lo mismo que el tiempo de compilación
    }
}

void loop () 
{
    RtcDateTime now = Rtc.GetDateTime();    //RtcDateTime ahora, es igual a que el rtc consiga el tiempo

    printDateTime(now);   //Se escribe el "ahora"
    Serial.println();

    if (!now.IsValid())
    {
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(1000); // one second
}

#define countof(a) (sizeof(a) / sizeof(a[0]))//Se defien una constante de tamaño

void printDateTime(const RtcDateTime& dt) //Se crea la funcion "printDateTime" y se crea una constante de tiempo
{
    char datestring[20];    //Se crea una cadena de caracteres de 20 lineas

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),    //Se hace una conversión de datos
            dt.Day(),   //Se ajusta el dia, mes, año, hora, minutos y segundos
             dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);   //Imprime la fecha y tiempo
    if( dt.Hour() == 21 &&  dt.Minute() == 59){   //SI son las 21 horas con 59 minutos
      if(alarma == true){   //Si la alarma es verdadera
        Serial.println( "Alarma");  //Se escribe "Alarma"
        alarma= false;    //Y la alarma se vuelve falsa, para que no esté repitiendo lo mismo
      }
    }
    if(dt.Hour() == 2 && dt.Minute() == 0);    //Reactiva la alarma a las 2:00 horas
 alarma= true;
}
