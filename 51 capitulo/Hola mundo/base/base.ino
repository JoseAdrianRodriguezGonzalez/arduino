#include<SPI.h>   //Libreria para la comunicación SPI 
#include<RH_NRF24.h>//Libreria para la comunicación enlace de 2.4 GHz

RH_NRF24 nrf24;  //Se crea un objeto del tipo "RH_NRF24" LLAMADO "nrff24"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Comunicación serie
  if(!nrf24.init()) //Si el modúlo no se incializa
    Serial.println("Fallo de incialización");   //Se escribe en el monior serie que hubo un fallo e la comunicación
  if(!nrf24.setChannel(2))    //Si no se ajusta al canal 2
    Serial.println("Fallo en establecer comunciación");   //No se puede establecer comunicación
  if(!nrf24.setRF(RH_NRF24 ::DataRate250kbps, RH_NRF24::TransmitPower0dBm))   //Si el objeto no se configura a la frecuencia
    Serial.println("fallo en opciones RF"); //fallo en opciones RF
  /*Si todo salió bien*/
  Serial.println("Base iniciada");//base iniciada
}

void loop() {
  // put your main code here, to run repeatedly:
  if (nrf24.available())      // si hay informacion disponible
  {  
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];  // buffer con longitud maxima de 32 bytes
    uint8_t len = sizeof(buf);      // obtiene longitud de la cadena
    if (nrf24.recv(buf, &len))      // si hay informacion valida en el buffer
    {
      Serial.print("Recibido: ");   // muestra texto
      Serial.println((char*)buf);   // muestra contenido del buffer
      
      uint8_t data[] = "Hola amigo remoto"; // se almacena texto a enviar
      nrf24.send(data, sizeof(data));   // envia texto
      nrf24.waitPacketSent();     // espera hasta realizado el envio
      Serial.println("Respondiendo");   // muestra texto
    }
    else          // si falla la recepcion
    {
      Serial.println("fallo en recepcion"); // muestra texto
    }
  }
}
