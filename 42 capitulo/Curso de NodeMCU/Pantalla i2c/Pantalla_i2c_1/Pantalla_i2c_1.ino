#include<Wire.h>  //Incluye la librería de la comunicación I2C
#include <LiquidCrystal_I2C.h>  //Se uncluye la librería de liquidCrystal_I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);   //Se crea el objeto lcd, con la direccipon que tiene, su numero de colunmnas y filas
void setup() {
  Wire.begin();   //Se inicializa el I2C
  lcd.init();   //Se incializa el lcd
  lcd.clear();    //Se limpia el lcd
  lcd.setBacklight(HIGH); //enciende el led de fondo
  lcd.setCursor(4,0);   
  lcd.print("Bienvenido");
  lcd.setCursor(2,1);
  lcd.print("A nodeMCU");

}

void loop() {
  lcd.setCursor(0,0); //Se coloca el cursor en el 0,0
  lcd.print("Scroll izquierda");    //Se escribe "Scroll izquierdo"
  //Se hace un scroll por un for a la derecha
  for(int i=0; i<12; i++){
  lcd.scrollDisplayRight();    
  delay(200);
  }
 lcd.setCursor(0,1);    //Se mueve el cursor al 0,1
  lcd.print("Scroll derecha");    //Se escribe "Scroll derecha"
  //Se hace un scroll a la izquierda con un array a la izquierda
  for(int i=0; i<12; i++){
  lcd.scrollDisplayLeft();    
  delay(200);
  }
  
}
