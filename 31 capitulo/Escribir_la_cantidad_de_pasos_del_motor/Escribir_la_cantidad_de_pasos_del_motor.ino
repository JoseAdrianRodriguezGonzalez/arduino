#include <Stepper.h>    //Se incluye la librería del motor
Stepper motor1(2048, 8, 10, 9, 11);   //Se crea un objeto del tipo Stepper llamado motor1 con los parametros de cantidad de pasos y en los pines en los que está conectado
void setup() {
 motor1.setSpeed(2);    //Se inicializa el motor con 2 revoluciones por minuto
Serial.begin(9600);   //Se inicia el monitor serie
}

void loop() {
  if(Serial.available()){   //Si hay información disponible
    int pasos = Serial.parseInt();    //Se obitene que la variable "pasos" es igual a serial.parseint, del cual obtiene los valores en entero
    Serial.println(pasos);    //Se imprime el valor de pasos
    motor1.step(pasos);   //A step se le asigna la variable pasos,y esta, hará girar al motor la función step 
    //Se desernegiza las bobinas
    digitalWrite(8,LOW);  
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11, LOW);
  }
}
