#include <Wire.h>   //Se incluye la lbrería I2C
#include <LiquidCrystal_I2C.h>  //Se incluye la librería para la pantalla lcd con bus I2C
LiquidCrystal_I2C lcd (0x27, 16, 2);  //Se crea un objeto del tipo "LiquidCrystal_I2C" llamado "lcd", con los siguientes parametros; dirección hexadecimal y cantidad de columnas y filas
void setup() {
  Wire.begin();   //Se inicializa la conexión I2C
  lcd.init();   //Se inicializa la pantalla
  lcd.clear();  //Se limpia la pantalla de cualquier texto
  lcd.setBacklight(HIGH); //Se enciende el foco trasero de la pantalla
}

void loop() {
 lcd.setCursor(0,0);    //Se dirige a esa ubicación el cursor
  lcd.println("Hola, han pasado");  //Se esribe "Hola, Han pasado" en la pantalla
  lcd.setCursor(0,1);   //Se coloca el cursor en la fila 2 columna 0
  lcd.print(millis() / 1000); //Se escribe el tiempo en milisegundos dividiendolo entre 1000 para que sean en segundos
  lcd.print(" seg."); //Se escribe la palabra "segundos"
}
