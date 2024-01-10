#include <SoftwareSerial.h>   //Se incluye la librería del bluetooth

SoftwareSerial miBT(10,11);   //Se declara un objeto llamado "miBT del tpo "SoftwareSerial en los pines 10 y 11

void setup(){
  Serial.begin(9600);   //Inicializa el monitor serie a 9600 baudios
  Serial.println("Listo ");     //Se escribe "listo"
  miBT.begin(38400);    //El modulo em´pieza con 38400 baudios
}
void loop(){
  if(miBT.available())       // lee BT y envia a arduino. Available devuelve verdadero cuando hay datos dispopnibles desde el modulo
  Serial.write(miBT.read());    //Serial escribe, miBT lee

  if(Serial.available())        // lee arduino y envia a BT. Si el monitor sere devuelve verdadero cuando hay datos disponibles
  miBT.write(Serial.read());    //miBT escribe, serial lee
}
AT+UART?