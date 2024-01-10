
#include<Wire.h>    //Se incluye la librería del I2C
#include<Adafruit_Sensor.h>   //Se incluye la librería del sensor 
#include <Adafruit_BMP280.h>    //Se incluye la librería del Sensor BMP280

Adafruit_BMP280 bmp;    //Se cre un objeto del tipo "Adafruit_BMP280 llamado "bmp"
float TEMPERATURA;    //Se establece a la variable "TEMPERATURA" del tipo float 
float PRESION;      //Se establece a la variable "PRESION" del tipo float 


void setup() {
Serial.begin(9600);   //Se inicializa el monitor serie
Serial.println("Iniciando:"); //Se imprime "iniciando"        
if(!bmp.begin()){ //Si la inicialización del bmp no está
  Serial.println("BMP280 no encontrado");   //Se imprime que "BMP280 no encontrado"
  while(1);     //Mientras esta en 1, es verdadero, se salta al loop
}
}
void loop() {
TEMPERATURA=bmp.readTemperature();    //TEMPERATURA = la función de la lectura de la temperatura
PRESION=bmp.readPressure()/100;   //PRESION = La lectura de la presión en hectoPascales
Serial.print("Tempreatura:");   //Se imprime en el monitor serie la "Temperatura:"
Serial.print(TEMPERATURA);  //Se imprimea la TEMPERATURA
Serial.print("C");    //Medido en C

Serial.print (" Presión:"); //SE escribe la "Presión" en el montior serie
Serial.print(PRESION);    ////S escribe el valor leído de PRESION 
Serial.println("hPa");    //Medido en hPa

delay(5000);

}
