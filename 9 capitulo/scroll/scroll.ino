#include <LiquidCrystal.h>      //Se incluye la librería liquid crystal 
LiquidCrystal lcd(7,6,5,4,3,2);   //Se crea un objeto del tipo liquid crystal llamado lcd con los pines en los que esta conectado
void setup(){
  lcd.begin(16, 2);  //Inicializa el lcd 
}
void loop (){
  lcd.setCursor(2,0); //Se coloca el cursor en el 2,0
  lcd.print("Prueba scroll"); // Se escribe el texto "Prueba scroll"
  lcd.scrollDisplayLeft();    //    Se activa la fución "scroll"
  delay(400); //toma una demora de de 400 milisegundos
}
  
