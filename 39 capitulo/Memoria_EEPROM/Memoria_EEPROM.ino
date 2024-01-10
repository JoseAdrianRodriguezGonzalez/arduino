#include <EEPROM.h>   //Se incluye la librería de EEPROM
void setup() {
 Serial.begin(9600);    //Se inicializa el monitor serie

 Serial.print("Capacidad de memoria:  ");   //Se escribe en el monitor serie "Capacidad de memoria: "
 Serial.println(EEPROM.length());  //escribe el valor devuelto en bytes la capacidad de almacenamiento
 Serial.println(" ");   //Se escribe " " en el monitor serie

 Serial.print("Valor almacenado en dirección 0:   "); //Se esccribe en el monitor serie "Valor almacenado en dirección 0:   "
 Serial.println( EEPROM.read(0) );         //Lee la dirección solo requiere un parametro

 Serial.print(" Almacenado numero 39 en dirección 0");//Se escribe en el monitor serie " Almacenado en dirección 0"
 EEPROM.write(0, 39);     //Se almacena el numero 39 en dirección 0 
}     
void loop (){
  //No hay nada por aquí
}
