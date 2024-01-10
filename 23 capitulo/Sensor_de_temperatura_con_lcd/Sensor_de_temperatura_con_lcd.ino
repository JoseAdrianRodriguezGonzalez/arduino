#include <LiquidCrystal.h>    //Se incluya la librería de la pantalla lcd

LiquidCrystal lcd(7,6,5,4,3,2);   //Se determina el espacio de la pantalla lcd

int SENSOR;     //Se crea una variable llamada sensor
 float TEMPERATURA;   //Se crea la varible del tipo float llamada "TEMPERATURA"
 float SUMA;    // Se crea una variable llamada "suma"
 void setup() {
lcd.begin(16,2);    //Se iniciali<a la pantalla

}

void loop() {
  SUMA =0;    //Se inicia la suma en 0
  for(int i=0; i<5; i++){   //Se crea una bucle for de min. 0 a max. 5 y el paraametro se suma
     SENSOR=analogRead(A0);   //Se lee el sensor
  TEMPERATURA=((SENSOR*5000.0)/1023)/10;    //TEMPERATURA es igual al sensor por 5000 entre 1023 dividido entre todo por 10 
  SUMA=TEMPERATURA +SUMA;   //La suma será igual a la lectura de la temperatura más la del valor anterior
  delay (500);    //  Demoar de medio segundo
  }
 
 lcd.setCursor(0,0);    //Se inicia el cursor
 lcd.println("TEMP:");    //Se escribme "TEMP: "
lcd.print(SUMA/5.0,1);    //Se imprime el promedio de las temperaturas
lcd.print( "C");  //  Se imprime el "C"
}
