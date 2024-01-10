#include<RH_ASK.h>    //Se incluye la librería de RadioHead
#include<SPI.h>   //Se incluye la librería de la comunicación
//Se definen los lEDS
#define LEDROJO 2 
#define LEDVERDE 3
RH_ASK rf_driver;   //Se crea un objeto del tipo de RH_ASK llamado "rf_driver"

void setup() {
    //Se inicializan los LEDS
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  rf_driver.init();   //Se inicializa el RadioHead
}

void loop() {
  uint8_t buf [1];    //Se crea un entero del caracter que se recibirá
  uint8_t buflen = sizeof(buf);   //Se mide el largo del array
  if(rf_driver.recv(buf, &buflen)){   //Si llega la información
  
   if ((char) buf[0]=='1'){   //Si el buf recibe en su indice 0 un 1
    digitalWrite(LEDROJO, !digitalRead(LEDROJO));   //Endencerá el led rojo
  }
  else if((char)buf[0]=='2'){   //Si no y si hay un 2 en el indice 0
    digitalWrite(LEDVERDE, HIGH); //Se prende por 5 segundos
    delay(5000);
    digitalWrite(LEDVERDE, LOW);    //Se apaga
  }
}
}
