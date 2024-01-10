#include "LedControl.h"   //Se incluye la librería
LedControl lc=LedControl(11,13,10,1);   //Se crea un objeto del tipo "LedControl" llamado "lc" y se llama a la función "LedControl"con los parametros de DIN,CLK,CS y el número de matrices conectadas
#define demora 1000   //Se define una constante llamada "demora" y tendrá un valor de 1000
//Se ponen en binarios los simbolos o caracteres en un mapa de "pixeles"
byte cero [8]={   
  B00111000,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};//Cero
byte uno [8]={
  B00010000,
  B00110000,
  B01010000,
  B00010000,
  B00010000,
  B00010000,
  B01111100
  
};  //uno
byte dos [8]={
  B00111000,
  B01000100,
  B00000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111100
};    //dos
  byte tres [8]={
    B00011000,
    B00100100,
    B00000100,
    B00011100,
    B00011000,
    B00000100,
    B00100100,
    B00011000
  };    //tres
byte cuatro [8]={
 B00001000,
 B00011000,
 B00101000,
 B01001000,
 B11111110,
 B00001000,
 B00001000,
 B00001000
};    //cuatro
byte cinco [8]={
  B01111000,
  B01000000,
  B01000000,
  B01111000,
  B00000100,
  B00000100,
  B00000100,
  B01111000
};    //cinco
byte seis [8]={
  B00001000,
  B00010000,
  B00100000,
  B01111000,
  B10000100,
  B10000100,
  B01000100,
  B00111000
};    //seis
byte siete [8]={
  B00111111,
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00001000,
  B00001000,
  B00001000
};    //siete
byte ocho[8]=  {
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00011100,
  B00100010,
  B00100010,
  B00011100
};    //ocho
byte nueve[8]={
  B00011100,
  B00100010,
  B00100010,
  B00011110,
  B00000010,
  B00000010,
  B00010010,
  B00001100
};    //nueve
void setup() {
  lc.shutdown(0,false);   //Se activa la matriz con el índice de matrices y el false
  lc.setIntensity(0,4);   //Se ajusta la intensidad de los leds, con el índice de matrices y con la cantidad de brillo
  lc.clearDisplay(0);   //Se limpia la pantalla con el indice de matrices
}

void loop() {
  mostrar_0();    //Muestra la función 0
  delay(demora);    //1 segundo
  mostrar_1();    //Muestra la función 1
  delay(demora);  //1 segundo
    mostrar_2();    //Muestra función 2
  delay(demora);    //1 segundo
    mostrar_3();    //Muestrala función 3
  delay(demora);    //1 segundo
    mostrar_4();    //Muestra la función 4
  delay(demora);    //1 segundo
    mostrar_5();    //Muestra la función 5
  delay(demora);    //1 segundo
    mostrar_6();    //Muestra la función 6
  delay(demora);     //1 segundo
    mostrar_7();    //Muestra la función 7
  delay(demora);    //1 segundo
    mostrar_8();    //Muestra la función 8
  delay(demora);    //1 segundo
    mostrar_9();    //Muestra la función 9
  delay(demora);    //1 segundo
 
}
void mostrar_0(){   //Función 0
  for(int i=0; i<8;i++){    //Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,cero[i]);   //Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_1(){//Función 1
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,uno[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_2(){//Función 2
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,dos[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_3(){//Función 3
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,tres[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_4(){//Función 4
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,cuatro[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_5(){//Función 5
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,cinco[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_6(){//Función 6
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,seis[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_7(){//Función 7
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,siete[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_8(){//Función 8
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,ocho[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_9(){//Función 9
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,nueve[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
