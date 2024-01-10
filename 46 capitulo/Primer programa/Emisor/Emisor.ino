#include<RH_ASK.h>    //Se incluye la librería de RadioHead con la moudlación ASK
#include<SPI.h>   //Se necesita esta librería para poder comunicarse el RadioHead

RH_ASK rf_driver;   //Se crea un objeto del tipo RH_ASK llamado rf_driver
void setup() {
  rf_driver.init();   //Se inicializa el objeto
}

void loop() {
  const char *msg ="¡Hola desde lejos!";    //Se crea un mensaje constante con un puntero
  rf_driver.send((uint8_t*)msg, strlen(msg));   //Se envía la información, de la cual, requiere de dos parametros, la cadena a enviar anidada en un entero sin signo byte y el segundo es la longitud del string
  rf_driver.waitPacketSent();   //Se envia el mensaje
  delay(1000);  //Se hace una demora de un segundo
}
