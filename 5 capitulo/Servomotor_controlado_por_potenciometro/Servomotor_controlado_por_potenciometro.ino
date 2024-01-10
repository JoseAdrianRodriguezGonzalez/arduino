# include<Servo.h>    //ASe incluye la librería "servo"
Servo servo1;   //Se crea un objeto del tipo servo llaado "servo1"
int PINSERVO = 2;   // Se declara el pin de la señal del servomotor
int PULSOMIN = 550;   //Se declara el pulso minimo
int PULSOMAX= 2600;   //Se declara el pulso maximo
int VALORPOT;   //Se declara una variable llamada "VALORPOT"
int ANGULO;   //Se declara una variable llamada "ANGULO"
int POT = 0;    //Se declara el pin analogico en el que esta el potenciometro
 void setup(){
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);    //Se inicializa el servomotor
 }
 void loop(){
  VALORPOT= analogRead(POT);    //  El valor del pot es igual al giro del potenciometro en la entrada analogica
  ANGULO = map(VALORPOT, 0, 1023, 0, 180);//El angulo es igual al mapa que se crea de los valores analogicos (primer parametro) y el angulo(el segundo parametro)
  servo1.write(ANGULO);  //El servo escribe lo que hay en el angulo
  delay(20);    //Con un retraso de 20 milisegundos
 }
