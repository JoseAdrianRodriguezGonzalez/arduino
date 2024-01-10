#define TRIG D5   // Se declara el disparador del sonido 
# define ECO D6      //Se declara el receptor del sonido
#define L1 D0
#define L2 D1 
#include "Mylib.h"
void setup() {
  pinMode(TRIG, OUTPUT);    //Se declara el disparador como "salida"
  pinMode(ECO,INPUT);     //Se declara el receptor como entrada
  pinMode(L1, OUTPUT);  //Se declara el led como salida
  pinMode (L2, OUTPUT);
  digitalWrite (L1, 0);   //Se inicializan los leds apagados
  digitalWrite (L2, 0);
  Serial.begin(9600);   //Se inicializa el monitor serie a 9600 baudios
}

void loop() {
  float DISTANCIA;    //Se crea una variable global llamada distancia
  DISTANCIA= getDistancia(TRIG,ECO);    //Distancia será igual a la función getDistancia
 
  Serial.println(DISTANCIA);      // Se imprime en el monitor serie
  delay(200);       //Lo hace cada 200 milisegundos
  if(Serial.available()){   //Si hay datos disponibles
    String cad; //Se declara una variable auxiliar
    cad=Serial.readString();    // La varibale será igual a la lectura del monitor serie al string
    binled(cad.toInt());    //Los valores de la función"binLed" serán iguales a la converisón de cad a enteros
  }
}
