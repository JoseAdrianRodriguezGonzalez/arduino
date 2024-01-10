#include <EEPROM.h>   //Se incluye la libería del EEPROM
float temperatura= 27.50;   //Se crea una variable flotante llamada "temperautra" con un valor de 27.50
char cadena[] ="Hola esta es una prueba";   //Se escribe una cadenas de caracteres con el texto "Hola esta es una prueba"
void setup() {
  Serial.begin(9600);   //Se inicializa la comunicación con el monitor serie
  EEPROM.put(0,temperatura);    //Se escribe en el byte 0 la variable "temperatura"
EEPROM.put (10,cadena);   //Se escribe en el byte 10 la variable "cadena"

Serial.println("Valor de punto flotante en dirección 0:");   //Se escribe en el monitor serie "Valor de punto flotante en dirección 0:"
Serial.println(EEPROM.get(0,temperatura));  //Se imprime en el monitor serie la lectura del EEPROM de la casilla 0 y su variable contenida

Serial.println(" ");    //Se deja un espacio en el monitor serie
  
Serial.println("Valor de la cadena en dirección 10: ");   //Se escribe en el monitor serie "Valor  de la cadena en dirección 10: "
Serial.println(EEPROM.get(10,cadena));   //Se imprime en el monitor serie lo que se lee en la casilla 10 del EEPROM la variable "cadena"
}

void loop() {
  // put your main code here, to run repeatedly:

}
