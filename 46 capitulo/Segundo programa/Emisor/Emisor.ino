#include<RH_ASK.h>    //Se incluyer la librería de RadioHead
#include<SPI.h>   //Se incluyeb la librería SPI, para una comunicación
#define PULSADOR1 2   //Se definen los pines delos push button
#define PULSADOR2 3
RH_ASK rf_driver;   //Se crea un objeto del tipo "RH_ASK" llamado "rf_driver"
void setup() {
  pinMode(PULSADOR1, INPUT_PULLUP);   //Se declaran como salidas los push button con una resistencia de PULL UP
  pinMode(PULSADOR2, INPUT_PULLUP);
  rf_driver.init();   //Se inicializa el objeto
}

void loop() {
  if(digitalRead(PULSADOR1) ==LOW){   //Si el pulsador se activa
    const char *msg ="1"; //Se envía un mensaje de "1"
    rf_driver.send((uint8_t*)msg, strlen(msg));   //Se envía con el parametro uint8_t del mensaje y la longitud del mensaje
    rf_driver.waitPacketSent(); //Se prepara el paquete
  }
  
   else if(digitalRead(PULSADOR2) ==LOW){   //Si el pulsador 2 se activa
    const char *msg ="2";  //Se envía un 2
    rf_driver.send((uint8_t*)msg, strlen(msg));   //El objeto lo envía
    rf_driver.waitPacketSent();   //Lo prepara el paquete
  }
  delay(200);   //Demora de 200 segundos
}
