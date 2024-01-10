#include <Adafruit_NeoPixel.h>  //Se incluye la librería NeoPixel
Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 2, NEO_RGB + NEO_KHZ800);   //Se crea un objeto del tipo NeoPixel llamado tira con los siguientes parametros 
//Primer paramaetro=cantidad de la pixeles en la tira
//Segundo parametro= pin de conexión a arduino
//Tercer parametro
// NEO_KHZ800  800 KHz velocidad de datos(WS2812 y nuevos)
// NEO_KHZ400  400KHz velocidad de datos(WS2811 y nuevos)
//NEO_GRB flujo de datos en orden GRB (WS2812 y nuevos)
//NEO_RGB flujo de datos en orden RGB (versiones más antiguas)
void setup() {
  tira.begin();   //Se inicializa la tira con el "begin" y el "show"
  tira.show();
}

void loop() {
  tira.setBrightness(20);   //Se ajusta el brillo
  for(int i = 0; i < 8; i++){   //Se crea un bucle for para encender los leds de uno por uno desde el primero hasta el ultimo
    tira.setPixelColor(0,0,0,255);    //Se empieza desde 0 y se enciende el azul
    tira.show //Se muestra todo lo que se ha escrito en el programa
    delay(500);   //Demora de medio segundo
  }
  tira.clear();   //Se limpia la tira para empezar de nuevo
}
