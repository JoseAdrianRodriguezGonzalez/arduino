#include <Stepper.h>      //Se incluye la librería del motor paso a paso

Stepper motor1(2048, 8, 10, 9, 11); //Se crea un objeto del tipo Stepper llamado "motor1",con los parametros de los pasos que da y en los pines en los que está conectado
void setup() {
 motor1.setSpeed(2);      //Se ajusta la velocidad 2 revoluciones por minuto

}

void loop() {
  motor1.step(512); //Hace un giro horario
  delay(2000);  //Demora 2 segundos
motor1.step(-512);    //Hace un giro anti-horario
  delay(2000);    //Demora 2 segundos

}
