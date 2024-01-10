#include<SoftwareSerial.h>    //Se incluye la librería "SoftwareSerial"

SoftwareSerial Nodemcu(10,11);    //Se incializa un objeto del tipo SoftwareSerial llamdao "Nodemcu" en los pines RX=10 y TX=11
void setup() {
  Serial.begin(9600);   //Se inicializa el monitor serie
  Nodemcu.begin(9600);    //Se inicializa el Nodemcu

}

void loop() {
  if(Nodemcu.available())   //Si hay infoprmación disponible en el Nodemu
  Serial.write(Nodemcu.read()); //Se escribe en el monitor serie lo que lee del Nodemcu

  if(Serial.available())    //Si hay datos en el monitor serie
  Nodemcu.write(Serial.read());   //Nodemcu escribe lo que lee en el monitor serie

}
