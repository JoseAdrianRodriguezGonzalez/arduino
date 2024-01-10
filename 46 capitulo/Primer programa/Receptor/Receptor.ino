#include<RH_ASK.h>    //Se incluye la librería de RH_ASK
#include<SPI.h> //Se incluye la librería SPI para que funcione 
RH_ASK rf_driver;   //Se crea el objeto"rf_driver"  del tipo RH_ASK
void setup() {
  rf_driver.init();   //Se inicializa el rf_driver
  Serial.begin(9600);   //Se incializa el monitor serie
}

void loop() {
  uint8_t buf[19];    //Almacena la frase enviada
  uint8_t buflen=sizeof(buf);   //Almacena la longitud total de los caracteres
  if(rf_driver.recv(buf, &buflen)){   //Si la función recv es verdadera si el array buf tiene la totalidad de los caracteres
    //Si es así
    Serial.print("Mensaje: ");    //Se escribe en la pantalla "Mensaje;  "  
    Serial.println((char*)buf);   //Y se escribe el mensaje
  }
}
