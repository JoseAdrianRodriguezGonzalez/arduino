#include <Adafruit_NeoPixel.h>    //Se incluye la librería NeoPixel
Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 2, NEO_RGB + NEO_KHZ800);   //Se crea un objeto del tipop NeoPixel con el nombre de "tira",con los siguientes 3 parametros
//Primer paramaetro=cantidad de la pixeles en la tira
//Segundo parametro= pin de conexión a arduino
//Tercer parametro
// NEO_KHZ800  800 KHz velocidad de datos(WS2812 y nuevos)
// NEO_KHZ400  400KHz velocidad de datos(WS2811 y nuevos)
//NEO_GRB flujo de datos en orden GRB (WS2812 y nuevos)
//NEO_RGB flujo de datos en orden RGB (versiones más antiguas)
void setup() {
  tira.begin();   //Se inicializa con el begin y con el show
  tira.show();
}

void loop() {
  tira.setBrightness(20);   //Se ajusta el brillo de la tira 
  for(int i = 0; i < 8; i++){   //Se inicia un bucle for para empezar desde el pirmer pixel hasta el ultimo(los enciende y los mantiene encendidos)
    tira.setPixelColor(i,0,0,255);//Se empieza desde cero y se enciende el color azul
    delay(500);   //Con demora de medio segundo
    tira.show(); //Se muestra lo que está escrito en el programa
  }
  tira.setBrightness(20); //Se ajusta el brillo global de la tira
  for(int i = 7; i >=0; i--){   //Se decrementa desde el ultimo led hasta el principio
    tira.setPixelColor(i,255,0,0);    //Se enciende el led rojo
    delay(500);   //Con una demora de medio segundo
    tira.show();    //Se muestra lo que está escrito en el programa
  }
  tira.clear();   //Se limpia todo
}
