
#include <Stepper.h>    //Incluye la librería "stepper", para el motor paso a paso

Stepper motor1(2048, 8, 10, 9, 11);   //Se crea un objeto del tipo "stepper" llamado motor 1, y cuenta con los parametros de cantidad de pasos(2048) y los piones en los que está la bobina
void setup() {
 motor1.setSpeed(2);    //Establece la velocidad en RPM en numeros enteros

}

void loop() {
  motor1.step(512);   //Cantidad de pasos en los que girará
  delay(2000);    //Demora de 2 segunddos

}
