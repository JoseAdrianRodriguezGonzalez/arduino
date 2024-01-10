#include <DHT.h>      //Incluye  la librería DHT
#include <DHT_U.h>   //Se incluye la librería del DHT

int SENSOR = 2;     //Se delcara el pin en el que esta el sensor
int TEMPERATURA ;     //Se declaran las variables de temperatura
int HUMEDAD;    //Se declara la variable humedad


DHT dht(SENSOR, DHT11);     //Se crea un objeto del tipo  DHT llamado "dht" y se coloca el modelo del dht y se declara el pin al que esta conectado


void setup(){
  Serial.begin(9600);   //Se inicializa el monitor serie
  dht.begin();        //Se inicializa el sensor
}
void loop(){
  TEMPERATURA = dht.readTemperature();    //Se lee la temperatura
  HUMEDAD = dht.readHumidity();     //Se lee la humedad
  Serial.print("Temperatura: ");      //Se escribe "temperatura en el monitor serie
  Serial.print(TEMPERATURA) ;     //Se escribe la variable "TEMPERATURA"
  Serial.print(" Humedad: ");       //Se escribe en el monitor serie "humedad"
  Serial.println(HUMEDAD);      //Se escribe la variable "HUMEDAD"
  delay(500);  //Se demora 500 milisegundos al escribirlo en el monitor serie
}
