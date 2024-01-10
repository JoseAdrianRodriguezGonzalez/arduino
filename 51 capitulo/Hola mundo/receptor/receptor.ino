
#include <SPI.h>  // incluye libreria SPI para comunicacion con el modulo
#include <RH_NRF24.h> // incluye la seccion NRF24 de la libreria RadioHead

RH_NRF24 nrf24;   // crea objeto con valores por defecto para bus SPI
      // y pin digital numero 8 para CE
void setup() 
{
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
  if (!nrf24.init())    // si falla inicializacion de modulo muestra texto
    Serial.println("fallo de inicializacion");
  if (!nrf24.setChannel(2)) // si falla establecer canal muestra texto
    Serial.println("fallo en establecer canal");
  if (!nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm)) // si falla opciones 
    Serial.println("fallo en opciones RF");             // RF muestra texto

}

void loop()
{
  Serial.println("Enviando mensaje a la base"); // muestra texto
  uint8_t data[] = "Hola desde lejos!";   // almacena texto a enviar
  nrf24.send(data, sizeof(data));   // envia el texto
  
  nrf24.waitPacketSent();     // espera hasta realizado el envio 
  
  uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];  // buffer con longitud maxima de 32 bytes
  uint8_t len = sizeof(buf);      // obtiene longitud de la cadena

  if (nrf24.available())      // si hay informacion disponible
  {    
    if (nrf24.recv(buf, &len))      // si hay informacion valida en el buffer
    {
      Serial.print("Recibido: ");   // muestra texto
      Serial.println((char*)buf);   // muestra contenido del buffer
    }
    else          // si falla la recepcion
    {
      Serial.println("fallo en recepcion"); // muestra texto
    }
  }
  delay(1000);    // demora de 1 segundo entre envios
  
}
