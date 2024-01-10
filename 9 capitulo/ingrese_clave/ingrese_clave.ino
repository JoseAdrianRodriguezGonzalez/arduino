#include <LiquidCrystal.h>    //Se incluye la librería de liquid crystal
LiquidCrystal lcd(7,6,5,4,3,2);   //Se crea un objeto del tipo liquid crystal llamado lcd colocando lso pines en lo que está conectado
void setup(){
  lcd.begin(16, 2);     //Se inicializa el lcd con el tamaño que tiene
}
void loop (){
  lcd.setCursor(0,0);   //Se coloca el cursor en 0,0
  lcd.print("Ingrese clave:");    //Se imprime la frase "" Ingrese clave:"
  lcd.setCursor(0,1); //Se coloca el cursor en 0,1
  lcd.cursor(); //Se muestra el cursor
  delay(500);   //Demora de medio segundo
  lcd.noCursor();   //Apaga el cursor
  delay(500);       //Demora de medio segundo
}
  
