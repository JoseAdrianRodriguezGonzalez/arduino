//Se incluyen las librerías del DHT
#include<DHT.h>
#include<DHT_U.h>
#define SENSOR D2
int TEMPERATURA;
int HUMEDAD;
int hi; //Se crea una varaible de sensación termica
DHT dht(SENSOR, DHT11);   //Se crea un objeto del tipo DHT llamado dht


void setup() {
  Serial.begin(9600);   //Se incializa el monitor serie
  dht.begin();    //Se incializa el dht
}

void loop() {
  
  TEMPERATURA=dht.readTemperature();    //Se lee la temperatura y se anida en la varialbe TEMPERATURA
  HUMEDAD=dht.readHumidity(); //Se la humedad y se anidad en la variable HUMEDAD
  hi=dht.computeHeatIndex(TEMPERATURA, HUMEDAD);  //Se opera la sensación termica con loss valores de TEMPERATURA y HUMEDAD
  //Se escribe en el monitor serie la temperatura
  Serial.print("Temperatura: ");  
  Serial.println(TEMPERATURA);
  //Se escribe la humedad 
  Serial.print("Humedad: ");
  Serial.println(HUMEDAD);
    //Se escribe la sensación termica
  Serial.print("Sensación termica: ");
  Serial.println(hi);
  delay(5000);
 
}
