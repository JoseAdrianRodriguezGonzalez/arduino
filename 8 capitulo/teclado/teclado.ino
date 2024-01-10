#include <Keypad.h>  //Se incluye la librería "keypad"

const byte FILAS = 4;     // Se  declaran por const byte las 4 filas porque tiene una longitud de 8 bits se definen las filas y las columnas
const byte COLUMNAS = 4;    //Se declaran las 4 columnas
char keys [FILAS][COLUMNAS] ={   //Define un mapa de caracteres 
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {9,8,7,6};   //Define los pines en los que esta los pines de filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2,};  //Define los pines en los que esta los pines de filas

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS); // crea un objeto del tipo keypad llamado teclado y tiene algunos parametros que ya se mencionaron anteriormente

char TECLA;   //Se usa una variable char,para poder usar diversos caracteres


void setup(){
  Serial.begin(9600);
}
void loop(){
  TECLA = teclado.getKey();   //Obtiene la tecla
    Serial.print(TECLA); //escribe en el monitor la tecla
  }
  if ( INDICE == 6)
}
