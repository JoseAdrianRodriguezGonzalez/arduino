#include <LiquidCrystal.h>    //Incluye la librería "liquid crystal"
LiquidCrystal lcd( 7,6,5,4,3,2);    //Se crea una objeto del tipo liquid crystal de nombre lcd con los pines a los que están conectados
void setup(){
  lcd.begin(16, 2);   //Inicializa la pantall y se pone el tamaño del lcd
}
void loop (){
  lcd.setCursor(0,0);   //Ubica el cursor en el que se va escribir en la pantalla
  lcd.println("Hola, han pasado");    // Se escribe "hola, han pasado"
  lcd.setCursor(0,1);   //Se coloca el cursor en las fila 2
  lcd.print(millis() / 1000);   //Se cuenta el tiempo en segundos dividido entre mil
  lcd.print(" seg.");   //Imprime la palabra "seg"
}
