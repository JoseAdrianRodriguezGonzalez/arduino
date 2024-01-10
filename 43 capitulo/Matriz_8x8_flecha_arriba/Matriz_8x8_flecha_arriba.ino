#include "LedControl.h"   //Se incluye la librería "LedControl.h"
LedControl lc=LedControl(11,13,10,1);   //Se crea un objeto del tipo "LedControl" llamado lc y se llama a la función "LedControl" con los parametros de DIN,CLK, CS y cantidad de matrices
#define demora 250    //Se crea una constante llamada "demora" en 250 milisegundos
byte flecha_arriba_1[8]= {
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000
};
byte flecha_arriba_2[8]={
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000
};
byte flecha_arriba_3[8]={
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00000000
};
  byte flecha_arriba_4[8]={
    B01111110,
    B11011011,
    B00011000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00011000
  };
  byte flecha_arriba_5 [8]={
    B11011011,
    B00011000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00011000,
    B00111100,
  };
  byte flecha_arriba_6 [8]={
    B00011000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00011000,
    B00111100,
    B01111110 
  };
  byte flecha_arriba_7 [8]={
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B11011011
  };
  byte flecha_arriba_8[8]={
    B00011000,
    B00000000,
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B11011011,
    B00011000
  };
  byte flecha_arriba_9[8]={
    B00000000,
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B11011011,
    B00011000,
    B00011000,
  };
  void setup() {
  lc.shutdown(0,false);   //Se activa la matriz con el índice de matrices y el false
  lc.setIntensity(0,4);   //Se ajusta la intensidad de los leds, con el índice de matrices y con la cantidad de brillo
  lc.clearDisplay(0);   //Se limpia la pantalla con el indice de matrices
}

void loop() {
  
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

void mostrar_1(){//Función 1
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_1[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_2(){//Función 2
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_2[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_3(){//Función 3
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_3[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_4(){//Función 4
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_4[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_5(){//Función 5
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_5[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}


void mostrar_6(){//Función 6
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_6[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_7(){//Función 7
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_7[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_8(){//Función 8
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_8[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
void mostrar_9(){//Función 9
  for(int i=0; i<8;i++){//Se crea un bucle for para la cantidad de filas
    lc.setRow(0,i,flecha_arriba_9[i]);//Se escriben las filas con los parametros de cantidad de matrices, filas y el valor
  }
}
