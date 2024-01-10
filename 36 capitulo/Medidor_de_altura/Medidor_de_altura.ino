#include<Wire.h>  //Se incluye la librería I2C 
#include<Adafruit_Sensor.h>   //Se incluye la librería de las funciones del sensor
#include <Adafruit_BMP280.h>    //Se incluye la librería del sensor BMP280

Adafruit_BMP280 bmp;    //Se crea un objeto del tipo "Adafruit_BMP280" llamado "bmp"
float TEMPERATURA;    //Se crea una variable del tipo flotante a TEMPERATURA
float PRESION, P0;    //Se crean dos variables del tipo flotante, PRESION Y P0

void setup() {
Serial.begin(9600);   //Se inicializa el monitor serie
Serial.println("Iniciando:");   //Se imprime en el monitor serie "Iniciando"
if(!bmp.begin()){   //Si la inicialización del bmp es correcta(o en su defecto, incorrecta)
  Serial.println("BMP280 no encontrado");   //Se imprime que el BMP280 no está y se quedá estancando en el void setup 
  while(1);   //mientra sea verdadero el encontrado del BMP, se pasa al loop, si no, se queda estancado en 
}
P0=1013.25;   //P0 tiene un valor de referencia de 1013.25 
}
void loop() {
TEMPERATURA=bmp.readTemperature();    //La TEMPERATURA es igual a la función de la lectura de la temperatura
PRESION=bmp.readPressure()/100; //La PRESION es la lectura de la presion entre 100,para que sala en hPa
Serial.print("Temperatura:");   //Se imprime "Temperatura"
Serial.print(TEMPERATURA);    //Se escribe lo que se haya leído en la variable VALOR
Serial.print("C");    //Todo medido en C

Serial.print (" Presión:");   //Se escrie "Presión:" en el monitor serie
Serial.print(PRESION);    //Se escribe lo que se haya leído en la variable PRESION
Serial.println("hPa");  //Todo en hPa
Serial.print("Altura aprox.:");   //Se escribe en el monitor serie "Altura aprox.:"
Serial.print(bmp.readAltitude(P0));   //Se usa la función "readAltitude" para leer la altura con el parametro que declaramos en el void setup
Serial.println("m");    //Todo medido en Metros

delay(5000);    //Con una demora de 5 segundos

}
