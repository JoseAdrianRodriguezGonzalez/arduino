#include<Ticker.h>  //Se incluye la librería Ticker
#define PIN_LED D1    //Se define el led
Ticker tiempo;    //Se crea un objeto del tipo ticker llamado tiempo
boolean ESTADO;   //Se crea un "ESTADO" en boolean

void parpadeo(){    //La función parpadeo
  digitalWrite(PIN_LED, ESTADO);    //Se acciona el led según el estado 
  ESTADO=!ESTADO;   //Cambia de estado
}
void setup() {
Serial.begin(9600);   //Se iniciaaliza el monitor serie
Serial.println("/n");   //Se escribe un null
ESTADO = false;   //Se asegura que el estado es false
pinMode(PIN_LED, OUTPUT); //Se declara como salida el led
digitalWrite(PIN_LED, ESTADO);    //Se apaga el led
tiempo.attach(1,parpadeo);    //Se acciona la funcion de parpadeo, con el "tiempo.attach", que requiere el tiempo en segundos que se hara para poner el 1, y a la función a la cuál se le hara
}

void loop() {
  if(Serial.available()){   //Si hay datos disponibles
  String cad = Serial.readString();   //Se crea un string llamado cad y se lee
  if( cad.toInt() == 0){    //Si cad es igual a 0
    tiempo.detach();    //Se detiene la función
  }if(cad.toInt()==1){    //Si cad es igual a 1
    tiempo.attach(1,parpadeo);    //Se acciona la función parpadeo
  }
  }
  // put your main code here, to run repeatedly:

}
