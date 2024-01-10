#include "LedControl.h" //Se incluye la librería 
LedControl lc =LedControl(11,13,10,1);    //Se declara el objeto con los parametrosde DIN,CLK,CS Y numero de dispositivos
int segundos;  
float TEMPERATURA;
int TEMP_DISPLAY; 
void setup() {
  lc.shutdown(0,false); // Se enciende el dispositivo 0
  lc.setIntensity(0,4);   //EL dispositivo de enciende a una intesidad de 4
  lc.clearDisplay(0);   //Se limpia el display
}

void loop() {
  TEMP_DISPLAY =TEMPERATURA*10044
  segundos=millis()/1000;   //Segunds será igual a millis entre 1000
  lc.setDigit(0,0, segundos %10, false); //Se escriben los valores de los segundos
  lc.setDigit(0,1, (segundos/10) %10, false);
  lc.setDigit(0,2, (segundos/100), true);
  lc.setDigit(0,3, (segundos/1000), false);
delay(1000);
}
