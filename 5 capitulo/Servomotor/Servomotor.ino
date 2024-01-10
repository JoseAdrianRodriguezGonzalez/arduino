#include <Servo.h>   //Se incluye la librería del servo
Servo servo1;       //Se crea un objeto del tipo "servo" llamado "servo 1"
int PINSERVO =2;        //Se declara la conexión de señal del servo
int PULSOMIN = 500;     //0 grados del pulso minimo en microsegundos(esto puede ser variable en los servos)
int PULSOMAX = 2400;    //180° del pulso maximo en microsegundos
void setup(){
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX); //Inicializa el servo con la funcion attach con tres parametros(el orden las variables)
}
void loop(){
  servo1.write(90);    // Se escribe al angulo en el que se debe de posicionar el servo
  delay(5000);    // con un retrsaso de 5 segundos
  servo1.write(0);      // Se escribe a 180° 
  delay(5000);  //intervalo de 5 segundos
  
  servo1.write(90);    // Se escribe al angulo en el que se debe de posicionar el servo
  delay(5000);    // con un retrsaso de 5 segundos
  servo1.write(180);      // Se escribe a 180° 
  delay(5000);  //intervalo de 5 segundos
}
