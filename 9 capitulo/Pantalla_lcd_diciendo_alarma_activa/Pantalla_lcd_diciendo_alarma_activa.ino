#include <LiquidCrystal.h> //Se incluye la librería liquid crystal
LiquidCrystal lcd(7,6,5,4,3,2);   //Se crea un objeto del tipo liquid crystal llamado lcd con  los pines en los que está conectado 
void setup(){
  lcd.begin(16, 2);   //Se inicializa la pantalla con la cantidad de espacio que tiene la pantalla
}
void loop (){
  lcd.setCursor(0,0);   //Se coloca el curso en 0,0
  lcd.print("¡Alarma activa!");   //Se escribe el texto" ¡Alarma activa!"
  lcd.display();  //muestra el texto
  delay(500); // demora de medio segundo
  lcd.noDisplay();    //Se oculta el texto
  delay(500);   //Demora medio segundo
}
  
