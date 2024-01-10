#include "LedControl.h"   //Se incluye la librería "LedControl"
LedControl lc=LedControl(11,13,10,1);   //Se crea un objeto del tipo LedControl llamado "lc" y se llama a la función "LedControl con los parametros DIN,CLK,CS y numero de dispositivos

void setup() {
  lc.shutdown(0,false);   //Se usa este comando con dos parametros, el indice de dispositvos(0 a 7) y el estado(true o false),false, activa el modulo y true, lo apaga
  lc.setIntensity(0,4);   //Lleva dos parametros, el indice de  de dispositivos(0 a 7), y la intensidad del LED,(de 0 a 15);
  lc.clearDisplay(0); //Limpia lo que hay en la matriz, solamente requiere de un parametro, el indice de dispositivos(0 a 7); 

}

void loop() {
  for(int fila=0; fila<8; fila++){    //Este bucle for, dice que se crea una variable llamada "fila", esta debe ser menor a 8 y cada vez va ir aumentando
    for(int columna=0; columna<8; columna++){   //Este bucle for dice que se crea una variable llamada "columna", dicha tiene que ser menor  8 y de igual forma va a ir aumentado
      lc.setLed(0,fila,columna,true);   //Se establece el LED con el indice de dispositivos,la variable de la fila, la de la columna, y un valor de true para encender el led
      delay(100);   //Demora de 100 milisegundos
      lc.setLed(0,fila,columna,false);    //Se establece el LED con los mismos parametros,pero ahora con un "false", para apagar el LED
      delay(100);   //Se demora 100 milisegundos
    }
  }

}
